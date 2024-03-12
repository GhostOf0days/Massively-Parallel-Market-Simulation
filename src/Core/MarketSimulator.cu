#include "MarketSimulator.h"
#include "../Utils/CSVReader.h"
#include "../Utils/CSVWriter.h"
#include "../Utils/Logger.h"
#include "../Strategies/TrendFollowing.h"
#include "../Strategies/MeanReversion.h"
#include <mpi.h>
#include <cuda_runtime.h>
#include <curand_kernel.h>

__global__ void simulateMarketKernel(Asset* assets, int numAssets, curandState* randStates) {
    int idx = blockIdx.x * blockDim.x + threadIdx.x;
    if (idx < numAssets) {
        curandState localState = randStates[idx];
        double randPrice = curand_normal_double(&localState) * 0.01 + assets[idx].getPrice();
        double randVolume = curand_uniform_double(&localState) * 1000.0;
        assets[idx].setPrice(randPrice);
        assets[idx].setVolume(randVolume);
        randStates[idx] = localState;
    }
}

MarketSimulator::MarketSimulator(int numAssets, int numTraders, int numTimeSteps)
    : numAssets(numAssets), numTraders(numTraders), numTimeSteps(numTimeSteps) {
    // Initialize assets
    CSVReader assetReader("data/assets.csv");
    assets = assetReader.readAssets();

    // Initialize traders
    CSVReader traderReader("data/traders.csv");
    traders = traderReader.readTraders();

    // Initialize strategies
    strategies.push_back(new TrendFollowing());
    strategies.push_back(new MeanReversion());
}

void MarketSimulator::run() {
    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Allocate memory on GPU
    Asset* d_assets;
    cudaMalloc(&d_assets, numAssets * sizeof(Asset));
    curandState* d_randStates;
    cudaMalloc(&d_randStates, numAssets * sizeof(curandState));

    // Initialize random states for CUDA
    curandState* h_randStates = new curandState[numAssets];
    for (int i = 0; i < numAssets; i++) {
        curand_init(rank * numAssets + i, 0, 0, &h_randStates[i]);
    }
    cudaMemcpy(d_randStates, h_randStates, numAssets * sizeof(curandState), cudaMemcpyHostToDevice);
    delete[] h_randStates;

    for (int t = 0; t < numTimeSteps; t++) {
        // Simulate market on GPU
        cudaMemcpy(d_assets, assets.data(), numAssets * sizeof(Asset), cudaMemcpyHostToDevice);
        int blockSize = 256;
        int numBlocks = (numAssets + blockSize - 1) / blockSize;
        simulateMarketKernel<<<numBlocks, blockSize>>>(d_assets, numAssets, d_randStates);
        cudaMemcpy(assets.data(), d_assets, numAssets * sizeof(Asset), cudaMemcpyDeviceToHost);

        // Execute trading strategies
        for (auto strategy : strategies) {
            strategy->execute(assets, traders);
        }

        // Gather market data and trading orders from all ranks
        MPI_Allgather(MPI_IN_PLACE, 0, MPI_DATATYPE_NULL, assets.data(), numAssets * sizeof(Asset), MPI_BYTE, MPI_COMM_WORLD);
        MPI_Allgather(MPI_IN_PLACE, 0, MPI_DATATYPE_NULL, traders.data(), numTraders * sizeof(Trader), MPI_BYTE, MPI_COMM_WORLD);

        // Write market snapshot to CSV file
        if (rank == 0) {
            CSVWriter snapshotWriter("results/snapshot_" + std::to_string(t) + ".csv");
            snapshotWriter.writeAssets(assets);
            snapshotWriter.writeTraders(traders);
            Logger::log("Snapshot written for time step " + std::to_string(t));
        }
    }

    // Cleanup
    cudaFree(d_assets);
    cudaFree(d_randStates);
    for (auto strategy : strategies) {
        delete strategy;
    }
}
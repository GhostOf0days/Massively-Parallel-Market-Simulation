#include "Core/MarketSimulator.h"
#include "Utils/Config.h"
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int numAssets = Config::getNumAssets();
    int numTraders = Config::getNumTraders();
    int numTimeSteps = Config::getNumTimeSteps();

    MarketSimulator simulator(numAssets, numTraders, numTimeSteps);
    simulator.run();

    MPI_Finalize();

    return 0;
}
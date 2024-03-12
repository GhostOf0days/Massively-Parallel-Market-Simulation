# Parallel Financial Market Simulation

This project implements a parallel financial market simulation using MPI (Message Passing Interface) and CUDA (Compute Unified Device Architecture). The simulation models the behavior of a simplified financial market with multiple assets and traders, each employing different trading strategies.

THIS IS A TEST OF CLAUDE 3 OPUS CODE GENERATION CAPABILITIES.

## Table of Contents
- [Features](#features)
- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Configuration](#configuration)
- [Project Structure](#project-structure)
- [Testing](#testing)
- [Results](#results)

## Features
- Parallel execution of the market simulation using MPI for distributed memory parallelism
- Utilization of CUDA for accelerating computations on NVIDIA GPUs
- Modular design with support for multiple trading strategies
- CSV-based input and output for initial market conditions and simulation results
- Logging functionality for monitoring the simulation progress
- Configuration management using JSON files
- Visualization of simulation results using Python scripts
- Unit testing of core components and trading strategies

## Requirements
- C++ compiler with C++11 support
- MPI library (e.g., OpenMPI, MPICH)
- CUDA Toolkit (version 10.0 or later)
- NVIDIA GPU with CUDA support
- CMake (version 3.10 or later)
- Python (version 3.6 or later) with Matplotlib library

## Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/parallel-market-simulation.git
   cd parallel-market-simulation
   ```

2. Create a build directory and navigate to it:
   ```bash
   mkdir build
   cd build
   ```

3. Configure the project using CMake:
   ```bash
   cmake ..
   ```

4. Build the project:
   ```bash
   make
   ```

## Usage
1. Prepare the initial market conditions and configuration files in the `data` directory.

2. Run the simulation:
   ```bash
   mpirun -np <num_processes> ./market_simulator
   ```
   Replace `<num_processes>` with the desired number of MPI processes.

3. Monitor the simulation progress through the log messages.

4. After the simulation completes, the results will be stored in the `results` directory.

5. Visualize the simulation results using the provided Python scripts:
   ```bash
   python scripts/plot_results.py
   ```

## Configuration
The simulation can be configured using the JSON files in the `data` directory:
- `config.json`: Contains general simulation parameters such as the number of assets, traders, and time steps.
- `initial_market.csv`: Specifies the initial market conditions, including asset prices and volumes.
- `historical_data.csv`: Provides historical market data for backtesting and analysis.

Modify these files according to your simulation requirements.

## Project Structure
The project structure is as follows:
```
parallel-market-simulation/
├── src/
│   ├── Core/
│   │   ├── Asset.h
│   │   ├── Trader.h
│   │   ├── TradingStrategy.h
│   │   ├── MarketSimulator.h
│   │   └── MarketSimulator.cu
│   ├── Strategies/
│   │   ├── TrendFollowing.h
│   │   ├── TrendFollowing.cpp
│   │   ├── MeanReversion.h
│   │   └── MeanReversion.cpp
│   ├── Utils/
│   │   ├── CSVReader.h
│   │   ├── CSVReader.cpp
│   │   ├── CSVWriter.h
│   │   ├── CSVWriter.cpp
│   │   ├── Logger.h
│   │   ├── Logger.cpp
│   │   ├── Config.h
│   │   └── Config.cpp
│   └── Main.cpp
├── data/
│   ├── config.json
│   ├── initial_market.csv
│   └── historical_data.csv
├── results/
│   ├── market_snapshots/
│   └── performance_metrics.csv
├── scripts/
│   ├── plot_results.py
│   └── analyze_performance.py
├── tests/
│   ├── test_asset.cpp
│   ├── test_trader.cpp
│   ├── test_trading_strategy.cpp
│   └── test_market_simulator.cpp
├── CMakeLists.txt
└── README.md
```

## Testing
The project includes unit tests for the core components and trading strategies. To run the tests:
```bash
cd build
make test
```

The test results will be displayed in the console.

## Results
The simulation results are stored in the `results` directory:
- `market_snapshots/`: Contains CSV files representing the market state at different time steps.
- `performance_metrics.csv`: Stores the performance metrics of the trading strategies.

The provided Python scripts in the `scripts` directory can be used to visualize and analyze the simulation results.
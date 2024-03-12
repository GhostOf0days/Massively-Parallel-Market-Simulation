market-sim/
│
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
│
├── data/
│   ├── initial_market.csv
│   ├── historical_data.csv
│   └── config.json
│
├── results/
│   ├── market_snapshots/
│   └── performance_metrics.csv
│
├── scripts/
│   ├── run_simulation.sh
│   └── plot_results.py
│
├── tests/
│   ├── test_asset.cpp
│   ├── test_trader.cpp
│   ├── test_trading_strategy.cpp
│   ├── test_market_simulator.cpp
│   └── ...
│
├── Makefile
└── README.md
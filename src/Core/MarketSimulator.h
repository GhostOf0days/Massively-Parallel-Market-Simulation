#pragma once
#include <vector>
#include "Asset.h"
#include "Trader.h"
#include "TradingStrategy.h"

class MarketSimulator {
public:
    MarketSimulator(int numAssets, int numTraders, int numTimeSteps);

    void run();

private:
    int numAssets;
    int numTraders;
    int numTimeSteps;
    std::vector<Asset> assets;
    std::vector<Trader> traders;
    std::vector<TradingStrategy*> strategies;
};
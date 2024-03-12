#pragma once
#include "../Core/TradingStrategy.h"
#include <vector>

class MeanReversion : public TradingStrategy {
public:
    void execute(std::vector<Asset>& assets, std::vector<Trader>& traders) override;

private:
    std::vector<std::vector<double>> prices;
    int maxHistorySize = 100;
};
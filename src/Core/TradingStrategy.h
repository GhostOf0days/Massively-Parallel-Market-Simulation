#pragma once
#include <vector>
#include "Asset.h"
#include "Trader.h"

class TradingStrategy {
public:
    virtual ~TradingStrategy() = default;
    virtual void execute(std::vector<Asset>& assets, std::vector<Trader>& traders) = 0;
};
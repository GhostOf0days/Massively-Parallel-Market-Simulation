#include "../src/Strategies/MeanReversion.h"
#include <iostream>

int main() {
    std::vector<Asset> assets = {
        {"AAPL", 100.0, 1000.0},
        {"GOOG", 200.0, 500.0},
        {"MSFT", 150.0, 750.0}
    };

    std::vector<Trader> traders = {
        {1, 10000.0, {0, 0, 0}},
        {2, 20000.0, {0, 0, 0}},
        {3, 15000.0, {0, 0, 0}}
    };

    MeanReversion meanReversion;
    meanReversion.execute(assets, traders);

    // Print updated trader holdings and balances
    for (const auto& trader : traders) {
        std::cout << "Trader " << trader.id << ":" << std::endl;
        std::cout << "  Holdings: ";
        for (int holding : trader.holdings) {
            std::cout << holding << " ";
        }
        std::cout << std::endl;
        std::cout << "  Balance: " << trader.balance << std::endl;
    }

    return 0;
}
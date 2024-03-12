#include <gtest/gtest.h>
#include "../src/Core/MarketSimulator.h"
#include "../src/Strategies/TrendFollowing.h"
#include "../src/Strategies/MeanReversion.h"

TEST(MarketSimulatorTest, Run) {
    // Create a market simulator with sample assets and traders
    MarketSimulator simulator(1000, 100, 10);

    // Add trading strategies
    simulator.addStrategy(new TrendFollowing());
    simulator.addStrategy(new MeanReversion());

    // Run the simulation
    simulator.run();

    // Check the final state of assets and traders
    const auto& assets = simulator.getAssets();
    const auto& traders = simulator.getTraders();

    // Check the number of assets and traders
    EXPECT_EQ(assets.size(), 1000);
    EXPECT_EQ(traders.size(), 100);

    // Check the price and volume of the first asset
    EXPECT_GT(assets[0].getPrice(), 0.0);
    EXPECT_GT(assets[0].getVolume(), 0.0);

    // Check the balance and holdings of the first trader
    EXPECT_GT(traders[0].getBalance(), 0.0);
    EXPECT_FALSE(traders[0].getHoldings().empty());
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
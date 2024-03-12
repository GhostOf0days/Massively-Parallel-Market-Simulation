#include <gtest/gtest.h>
#include "../src/Strategies/TrendFollowing.h"
#include "../src/Strategies/MeanReversion.h"

TEST(TradingStrategyTest, TrendFollowing) {
    std::vector<Asset> assets = {
        Asset("AAPL", 100.0, 1000.0),
        Asset("GOOG", 200.0, 500.0),
        Asset("MSFT", 150.0, 750.0)
    };
    std::vector<Trader> traders = {
        Trader(1, 10000.0),
        Trader(2, 20000.0),
        Trader(3, 15000.0)
    };

    // Set initial holdings for traders
    traders[0].setHoldings({0, 0, 0});
    traders[1].setHoldings({0, 0, 0});
    traders[2].setHoldings({0, 0, 0});

    TrendFollowing trendFollowing;

    // Execute the trend following strategy
    trendFollowing.execute(assets, traders);

    // Check the updated holdings and balances of traders
    EXPECT_EQ(traders[0].getHoldings(), std::vector<int>({1, 0, 0}));
    EXPECT_DOUBLE_EQ(traders[0].getBalance(), 9900.0);

    EXPECT_EQ(traders[1].getHoldings(), std::vector<int>({2, 1, 1}));
    EXPECT_DOUBLE_EQ(traders[1].getBalance(), 19450.0);

    EXPECT_EQ(traders[2].getHoldings(), std::vector<int>({1, 0, 1}));
    EXPECT_DOUBLE_EQ(traders[2].getBalance(), 14750.0);
}

TEST(TradingStrategyTest, MeanReversion) {
    std::vector<Asset> assets = {
        Asset("AAPL", 100.0, 1000.0),
        Asset("GOOG", 200.0, 500.0),
        Asset("MSFT", 150.0, 750.0)
    };
    std::vector<Trader> traders = {
        Trader(1, 10000.0),
        Trader(2, 20000.0),
        Trader(3, 15000.0)
    };

    // Set initial holdings for traders
    traders[0].setHoldings({0, 0, 0});
    traders[1].setHoldings({0, 0, 0});
    traders[2].setHoldings({0, 0, 0});

    MeanReversion meanReversion;

    // Execute the mean reversion strategy
    meanReversion.execute(assets, traders);

    // Check the updated holdings and balances of traders
    EXPECT_EQ(traders[0].getHoldings(), std::vector<int>({0, 1, 0}));
    EXPECT_DOUBLE_EQ(traders[0].getBalance(), 9800.0);

    EXPECT_EQ(traders[1].getHoldings(), std::vector<int>({1, 2, 1}));
    EXPECT_DOUBLE_EQ(traders[1].getBalance(), 19250.0);

    EXPECT_EQ(traders[2].getHoldings(), std::vector<int>({0, 1, 1}));
    EXPECT_DOUBLE_EQ(traders[2].getBalance(), 14600.0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
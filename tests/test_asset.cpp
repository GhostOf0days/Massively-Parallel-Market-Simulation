#include <gtest/gtest.h>
#include "../src/Core/Asset.h"

TEST(AssetTest, Initialization) {
    Asset asset("AAPL", 100.0, 1000.0);
    EXPECT_EQ(asset.getSymbol(), "AAPL");
    EXPECT_DOUBLE_EQ(asset.getPrice(), 100.0);
    EXPECT_DOUBLE_EQ(asset.getVolume(), 1000.0);
}

TEST(AssetTest, SetPrice) {
    Asset asset("AAPL", 100.0, 1000.0);
    asset.setPrice(150.0);
    EXPECT_DOUBLE_EQ(asset.getPrice(), 150.0);
}

TEST(AssetTest, SetVolume) {
    Asset asset("AAPL", 100.0, 1000.0);
    asset.setVolume(2000.0);
    EXPECT_DOUBLE_EQ(asset.getVolume(), 2000.0);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
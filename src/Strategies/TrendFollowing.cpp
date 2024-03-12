#include "TrendFollowing.h"
#include <algorithm>
#include <numeric>

void TrendFollowing::execute(std::vector<Asset>& assets, std::vector<Trader>& traders) {
    int numAssets = assets.size();
    int numTraders = traders.size();

    std::vector<double> prevPrices(numAssets);
    std::vector<double> movingAverages(numAssets);

    // Calculate moving averages
    for (int i = 0; i < numAssets; i++) {
        prevPrices[i] = assets[i].price;
        movingAverages[i] = std::accumulate(prices[i].begin(), prices[i].end(), 0.0) / prices[i].size();
    }

    // Execute trades based on trend following strategy
    for (int i = 0; i < numTraders; i++) {
        for (int j = 0; j < numAssets; j++) {
            if (assets[j].price > movingAverages[j] && traders[i].balance >= assets[j].price) {
                traders[i].holdings[j]++;
                traders[i].balance -= assets[j].price;
            } else if (assets[j].price < movingAverages[j] && traders[i].holdings[j] > 0) {
                traders[i].holdings[j]--;
                traders[i].balance += assets[j].price;
            }
        }
    }

    // Update price history
    for (int i = 0; i < numAssets; i++) {
        prices[i].push_back(assets[i].price);
        if (prices[i].size() > maxHistorySize) {
            prices[i].erase(prices[i].begin());
        }
    }
}
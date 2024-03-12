#include "MeanReversion.h"
#include <algorithm>
#include <numeric>
#include <cmath>

void MeanReversion::execute(std::vector<Asset>& assets, std::vector<Trader>& traders) {
    int numAssets = assets.size();
    int numTraders = traders.size();

    std::vector<double> meanPrices(numAssets);
    std::vector<double> stdDevs(numAssets);

    // Calculate mean prices and standard deviations
    for (int i = 0; i < numAssets; i++) {
        double sum = std::accumulate(prices[i].begin(), prices[i].end(), 0.0);
        double mean = sum / prices[i].size();
        double sqSum = std::inner_product(prices[i].begin(), prices[i].end(), prices[i].begin(), 0.0);
        double stdDev = std::sqrt((sqSum / prices[i].size()) - (mean * mean));
        meanPrices[i] = mean;
        stdDevs[i] = stdDev;
    }

    // Execute trades based on mean reversion strategy
    for (int i = 0; i < numTraders; i++) {
        for (int j = 0; j < numAssets; j++) {
            double zScore = (assets[j].price - meanPrices[j]) / stdDevs[j];
            if (zScore < -2.0 && traders[i].balance >= assets[j].price) {
                traders[i].holdings[j]++;
                traders[i].balance -= assets[j].price;
            } else if (zScore > 2.0 && traders[i].holdings[j] > 0) {
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
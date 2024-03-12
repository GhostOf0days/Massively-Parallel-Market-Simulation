#include "CSVWriter.h"
#include <fstream>

CSVWriter::CSVWriter(const std::string& filename) : filename(filename) {}

void CSVWriter::writeAssets(const std::vector<Asset>& assets) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& asset : assets) {
            file << asset.getSymbol() << "," << asset.getPrice() << "," << asset.getVolume() << "\n";
        }
        file.close();
    }
}

void CSVWriter::writeTraders(const std::vector<Trader>& traders) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& trader : traders) {
            file << trader.getId() << "," << trader.getBalance() << "\n";
            for (int holding : trader.getHoldings()) {
                file << holding << ",";
            }
            file << "\n";
        }
        file.close();
    }
}
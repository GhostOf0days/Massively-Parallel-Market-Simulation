#include "CSVReader.h"
#include <fstream>
#include <sstream>

CSVReader::CSVReader(const std::string& filename) : filename(filename) {}

std::vector<Asset> CSVReader::readAssets() {
    std::vector<Asset> assets;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string symbol;
            double price, volume;
            if (std::getline(iss, symbol, ',') >> price >> volume) {
                assets.emplace_back(symbol, price, volume);
            }
        }
        file.close();
    }
    return assets;
}

std::vector<Trader> CSVReader::readTraders() {
    std::vector<Trader> traders;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int id;
            double balance;
            if (iss >> id >> balance) {
                traders.emplace_back(id, balance);
            }
        }
        file.close();
    }
    return traders;
}
#pragma once
#include <string>
#include <vector>
#include "../Core/Asset.h"
#include "../Core/Trader.h"

class CSVReader {
public:
    CSVReader(const std::string& filename);

    std::vector<Asset> readAssets();
    std::vector<Trader> readTraders();

private:
    std::string filename;
};
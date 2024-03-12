#pragma once
#include <string>
#include <vector>
#include "../Core/Asset.h"
#include "../Core/Trader.h"

class CSVWriter {
public:
    CSVWriter(const std::string& filename);

    void writeAssets(const std::vector<Asset>& assets);
    void writeTraders(const std::vector<Trader>& traders);

private:
    std::string filename;
};
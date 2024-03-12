#include "Config.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int Config::numAssets = 0;
int Config::numTraders = 0;
int Config::numTimeSteps = 0;

void Config::loadConfig() {
    std::ifstream file("data/config.json");
    if (file.is_open()) {
        json config;
        file >> config;
        numAssets = config["numAssets"];
        numTraders = config["numTraders"];
        numTimeSteps = config["numTimeSteps"];
        file.close();
    }
}

int Config::getNumAssets() {
    if (numAssets == 0) {
        loadConfig();
    }
    return numAssets;
}

int Config::getNumTraders() {
    if (numTraders == 0) {
        loadConfig();
    }
    return numTraders;
}

int Config::getNumTimeSteps() {
    if (numTimeSteps == 0) {
        loadConfig();
    }
    return numTimeSteps;
}
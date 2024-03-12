#include "Config.h"
#include <fstream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int Config::getNumAssets() {
    std::ifstream file("data/config.json");
    json config;
    file >> config;
    return config["numAssets"];
}

int Config::getNumTraders() {
    std::ifstream file("data/config.json");
    json config;
    file >> config;
    return config["numTraders"];
}

int Config::getNumTimeSteps() {
    std::ifstream file("data/config.json");
    json config;
    file >> config;
    return config["numTimeSteps"];
}
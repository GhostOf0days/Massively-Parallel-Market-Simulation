#pragma once
#include <string>

class Config {
public:
    static int getNumAssets();
    static int getNumTraders();
    static int getNumTimeSteps();

private:
    static void loadConfig();
    static int numAssets;
    static int numTraders;
    static int numTimeSteps;
};
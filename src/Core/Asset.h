#pragma once
#include <string>

class Asset {
public:
    Asset(const std::string& symbol, double price, double volume);

    std::string getSymbol() const;
    double getPrice() const;
    double getVolume() const;
    void setPrice(double price);
    void setVolume(double volume);

private:
    std::string symbol;
    double price;
    double volume;
};
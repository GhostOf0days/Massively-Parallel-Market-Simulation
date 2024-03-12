#include "Asset.h"

Asset::Asset(const std::string& symbol, double price, double volume)
    : symbol(symbol), price(price), volume(volume) {}

std::string Asset::getSymbol() const {
    return symbol;
}

double Asset::getPrice() const {
    return price;
}

double Asset::getVolume() const {
    return volume;
}

void Asset::setPrice(double price) {
    this->price = price;
}

void Asset::setVolume(double volume) {
    this->volume = volume;
}
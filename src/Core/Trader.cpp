#include "Trader.h"

Trader::Trader(int id, double balance) : id(id), balance(balance) {}

int Trader::getId() const {
    return id;
}

double Trader::getBalance() const {
    return balance;
}

const std::vector<int>& Trader::getHoldings() const {
    return holdings;
}

void Trader::setBalance(double balance) {
    this->balance = balance;
}

void Trader::setHoldings(const std::vector<int>& holdings) {
    this->holdings = holdings;
}
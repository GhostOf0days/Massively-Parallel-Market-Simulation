#pragma once
#include <vector>

class Trader {
public:
    Trader(int id, double balance);

    int getId() const;
    double getBalance() const;
    const std::vector<int>& getHoldings() const;
    void setBalance(double balance);
    void setHoldings(const std::vector<int>& holdings);

private:
    int id;
    double balance;
    std::vector<int> holdings;
};
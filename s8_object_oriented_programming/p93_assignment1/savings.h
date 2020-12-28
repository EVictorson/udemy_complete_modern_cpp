#ifndef SAVINGS_H
#define SAVINGS_H

#include "account.h"

class Savings : public Account {
    float m_Rate;

public:
    Savings(const std::string &name, float balance, float rate);
    ~Savings();

    float GetInterestRate() const;
    void AccumulateInterest();

};

#endif
#ifndef CHECKING_H
#define CHECKING_H

#include "account.h"

class Checking : public Account {
    float m_AccMin{50.0};

public:
    // with c++11 onwards you can inherit the base class constructors with:
    // inheritinc constructors
    using Account::Account;
    // we can use `using <base>::<base> in derived classes if they don't 
    // have any of their own members that need to be intialized
    //Checking(const std::string &name, float balance);
    ~Checking();

    void Withdraw(float amount);

};

#endif
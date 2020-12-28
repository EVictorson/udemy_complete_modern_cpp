#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>

class Account {
    std::string m_Name;
    int m_AccNo;
    static int s_ANGenerator;

protected:
    float m_Balance;

public:
    Account(const std::string &name, float balance);
    ~Account();
    const std::string GetName()const;
    float GetBalance()const;
    int GetAccountNo()const;

    // need virtual keyword so that derived class functions can override
    // these are polymorphic functions
    virtual void AccumulateInterest();
    virtual void Withdraw(float amount);
    void Deposit(float amount);
    virtual float GetInterestRate()const;

};


#endif
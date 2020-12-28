#include "transaction.h"
#include <iostream>

// since we want a transaction to work with any of the drived classes
// we accept a pointer to the base class
// in order for the correct child class functions (polymorphic functions)
// to be called, we need to mark them as virtual in the base class
// if we do not mark them as virtual only the base class functions will be called
void Transaction(Account *pAccount) {
    std::cout<<"Transaction started."<<std::endl;
    std::cout<<"Initial balance: "<<pAccount->GetBalance()<<std::endl;
    pAccount->Deposit(100);
    pAccount->AccumulateInterest();
    pAccount->Withdraw(170);
    std::cout<<"Interest rate: "<<pAccount->GetInterestRate()<<std::endl;
    std::cout<<"Final balance: "<<pAccount->GetBalance()<<std::endl;
}

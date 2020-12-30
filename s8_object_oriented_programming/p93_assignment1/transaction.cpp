#include "transaction.h"
#include <iostream>
#include "checking.h"

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

    // we can use run-time type information (RTTI) to determine what to do:
    if(typeid(*pAccount) == typeid(Checking)) {
        // downcast account pointer to a checking pointer
        Checking *pChecking = static_cast<Checking*>(pAccount);
        std::cout<<"Minimum balance of checking = " << pChecking->GetMinimumBalance() << std::endl;
    }

    // alternatively can perform this with dynamic_cast:
    // dynamic cast and typeid should be avoided when possible
    Checking *pChecking = dynamic_cast<Checking*>(pAccount);
    if (pChecking != nullptr) { 
        std::cout<<"Minimum balance of checking = " << pChecking->GetMinimumBalance() << std::endl;
    }

    pAccount->Withdraw(170);
    std::cout<<"Interest rate: "<<pAccount->GetInterestRate()<<std::endl;
    std::cout<<"Final balance: "<<pAccount->GetBalance()<<std::endl;
}

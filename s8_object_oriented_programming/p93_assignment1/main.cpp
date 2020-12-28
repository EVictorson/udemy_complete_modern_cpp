#include "account.h"
#include "checking.h"
#include "savings.h"
#include "transaction.h"
#include <iostream>

int main() {
    /*
    Account acc("Bob", 1000);
    std::cout<<"Initial balance: "<<acc.GetBalance()<<std::endl;
    acc.Deposit(200);
    acc.Withdraw(380);
    std::cout<<"Balance: "<<acc.GetBalance()<<std::endl;
    */
    Checking checking_acct("Bob", 1000);
    std::cout<<"Initial checking acct balance: "<<checking_acct.GetBalance()<<std::endl;
    //checking_acct.Withdraw(960);

    Transaction(&checking_acct);

    Savings savings_acct("Bob", 100, 0.05);
    Transaction(&savings_acct);


    return 0;
}
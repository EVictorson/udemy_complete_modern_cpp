#include "checking.h"
#include <iostream>

/*Checking::Checking(const std::string &name, float balance) : 
    Account(name, balance) {
}*/

Checking::~Checking() {

}

void Checking::Withdraw(float amount) {
    if ((m_Balance - amount) > m_AccMin) {
        m_Balance -= amount;
    }
    else {
        std::cout<<"Insufficient balance"<<std::endl;
    }
}
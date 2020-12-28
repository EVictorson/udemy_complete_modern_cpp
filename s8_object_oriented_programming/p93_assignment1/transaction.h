#ifndef TRANSACTION_H
#define TRANSACTION_H
#include "account.h"

// takes a pointer to the base account class so that it can
// operate on any of the derived classes
void Transaction(Account *pAccount);


#endif
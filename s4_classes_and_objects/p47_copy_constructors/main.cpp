#include <iostream>
#include "integer.h"

int main () {
    //int *p1 = new int(5);
    // shallow copy
    //int *p2 = p1;

    // deep copy
    //int *p3 = new int(*p1);

    Integer i(5);
    // call the copy constructor
    Integer i2(i); // forces compiler to synthesize copy constructor if we haven't defined one
    std::cout<<i.GetValue()<<std::endl;

    return 0;
}

/* Notes:
Rule of 3
If a user has implemented any one of the following, they should all probably be defined
destructor
copy constructor
copy assignment operator
*/
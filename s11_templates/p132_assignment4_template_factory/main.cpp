/*
Create a factory method that creates an instance of some type T, initializes it with arguments and returns it.

Here are some usage examples of the factory.

int *p1 = CreateObject<int>(5) ;
 
std::string *s = CreateObject<std::string>() ;//Default construction
 
Employee * emp = CreateObject<Employee>(
"Bob",    //Name
101,      //Id
1000) ;   //Salary
 
Contact *p = CreateObject<Contact>(
"Joey",                //Name
987654321,             //Phone number
"Boulevard Road, Sgr", //Address
"joey@poash.com") ;    //Email

*/

#include <iostream>
#include "employee.h"

// variadic templated factory method
template<typename T, typename... Params>
T* createObject(Params... args) {
    return new T(args...);
}

int main() {

    auto s = createObject<int>(5);
    std::cout<<"*s = "<<*s<<std::endl;

    auto str = createObject<std::string>("This is a string.");
    std::cout<<"*str = "<<*str<<std::endl;

    auto emp = createObject<Employee>("Bob", 1000.00);
    std::cout<<"emp = "<<*emp<<std::endl;

    auto emp2 = createObject<Employee>("Ryan", 2500.00);
    std::cout<<"emp2 = "<<*emp2<<std::endl;

    delete s;
    delete str;
    delete emp;
    delete emp2;

    return 0;
}

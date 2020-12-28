#include "integer.h"
#include <iostream>

Integer Add(const Integer &a, const Integer &b) {
    Integer temp;
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;
}

Integer Add(int a, int b) {
    Integer temp(a+b);
    return temp;    // named return value optimization

    // below is a better way to do the above 
    //return Integer(a + b); //return value optimization
}

void Print(Integer val) {

}

int main () {
    //Integer a(1), b(3);
    //a = Add(a, b).GetValue();
    //a.SetValue(Add(a, b).GetValue());

    Integer a = Add(3,5);
    // with copy elision turned on (by default) this will only call 
    // a single parameterized constructor
    // g++ main.cpp integer.cpp
    // ./a.out
    //Parameterized constructor Integer(int)
    //Destructor called!

    // if we force copy elision off w/ -fno-elide-constructors flag to gcc
    // we should see one parameterized constructor
    // one move constructor to assign to the temporary value returned from Add()
    // and another move constructor to move the temporary returned from add to Integer a
    // in console: g++ -fno-elide-constructors main.cpp integer.cpp
    // ./a.out
    /*
    Parameterized constructor Integer(int)
    Move constructor Integer(Integer &&obj)
    Destructor called!
    Move constructor Integer(Integer &&obj)
    Destructor called!
    Destructor called!
    */

   // for copy elision to work the class should have copy and move constructors


    // moving on to std::move lesson:

    Integer b(1);
    // this will call the copy constructor since b is an l-value
    auto c{b};

    // to force move constructor to be used we can use std::move
    auto d{std::move(a)};

    // if we call our Print function w/ std::move
    // it moves b into val, which will then be destroyed when Print;s
    // scope ends
    Print(std::move(b));
    std::cout<<"just finished print func"<<std::endl;

    //prints the following:
    /*
    Parameterized constructor Integer(int)
    Parameterized constructor Integer(int)
    Copy constructor Integer(const Integer &obj)
    Move constructor Integer(Integer &&obj)
    Move constructor Integer(Integer &&obj)
    Destructor called!
    just finished print func
    Destructor called!
    Destructor called!
    Destructor called!
    Destructor called!
    */

    return 0;
}
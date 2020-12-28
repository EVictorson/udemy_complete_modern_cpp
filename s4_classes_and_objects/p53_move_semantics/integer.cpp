#include "integer.h"
#include <iostream>

// default constructor
Integer::Integer() {
    std::cout<<"Default constructor Integer()"<<std::endl;
    m_pInt = new int(0);
}

// parameterized constructor
Integer::Integer(int value) {
    std::cout<<"Parameterized constructor Integer(int)"<<std::endl;
    m_pInt = new int(value);
}

// copy constructor, creates new integer object from passed in integer object
// by invoking new we are creating a deep copy of the original object
// modify with const so we aren't able to change original Integer object
Integer::Integer(const Integer &obj) {
    std::cout<<"Copy constructor Integer(const Integer &obj)"<<std::endl;
    m_pInt = new int(*obj.m_pInt);
}


Integer::Integer(Integer &&obj) {
    std::cout<<"Move constructor Integer(Integer &&obj)"<<std::endl;
    // shallow copy (both pointers point to the same address)
    m_pInt = obj.m_pInt;

    // assign original object's pointer to nullptr so when original
    // object is destroyed it will not crash
    obj.m_pInt = nullptr;
}


// rule of 3, if we have a copy constructor we probably need to explicitly define
// a destructor to free the newly allocated memory.
Integer::~Integer() {
    std::cout<<"Destructor called!"<<std::endl;
    delete m_pInt;
}

int Integer::GetValue() const {
    return *m_pInt;
}

void Integer::SetValue(int value) {
    *m_pInt = value;
}
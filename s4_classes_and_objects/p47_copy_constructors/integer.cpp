#include "integer.h"
#include <iostream>

Integer::Integer() {
    std::cout<<"Default constructor called!"<<std::endl;
    m_pInt = new int(0);
}

Integer::Integer(int value) {
    std::cout<<"Parameterized constructor called!"<<std::endl;
    m_pInt = new int(value);
}

// copy constructor, creates new integer object from passed in integer object
// by invoking new we are creating a deep copy of the original object
// modify with const so we aren't able to change original Integer object
Integer::Integer(const Integer &obj) {
    std::cout<<"Copy constructor called!"<<std::endl;
    m_pInt = new int(*obj.m_pInt);
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

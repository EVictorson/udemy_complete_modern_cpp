#pragma once
#include <iostream>

class Integer {
    int *m_pInt;

public:
    // default constructor
    Integer();
    // parameterized constructor
    Integer(int value);
    // copy constructor
    Integer(const Integer &obj);
    // move constructor
    Integer(Integer &&obj);

    int GetValue()const;
    void SetValue(int value);
    ~Integer();
};
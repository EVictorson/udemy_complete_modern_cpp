#pragma once
#include <iostream>

class Integer {
    int *m_pInt;
public:
    Integer();
    Integer(int value);
    Integer(const Integer &obj);
    Integer(Integer &&obj);
    int GetValue()const;
    void SetValue(int value);
    ~Integer();

    // pre-increment operator overload
    Integer & operator ++();
    //post increment operator overload,
    // needs to have int argument so compiler can distinguish between the two overloads
    Integer operator ++(int);

    // overload the + operator
    Integer operator +(const Integer & a)const;

    // overload the comparison (==) operator
    bool operator ==(const Integer &obj)const;

    // overload the assignment (=) operator (copy assignment)
    Integer & operator =(const Integer &a);

    // overload the assignment (=) operator (move assignment)
    Integer & operator =(Integer &&a);

    // function operator overload
    //void operator ()();

    // overload the extraction operator as a friend to the integer class
    // allows istream to be a friend of the integer class, giving it access to private members
    // usage of friend keyword is generally discouraged, use as last resort
    //friend std::istream& operator >>(std::istream& input, Integer &a);

    explicit operator int();

};

// global insertion operator overload (because it's a member of the ostream class
// we need to do it as a global overload, or as a friend to the class)
std::ostream& operator <<(std::ostream& out, const Integer &a);

// global extraction operator overload
std::istream& operator >>(std::istream& input, Integer &a);
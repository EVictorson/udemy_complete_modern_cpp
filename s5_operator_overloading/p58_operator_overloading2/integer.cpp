#include "integer.h"
#include <iostream>

Integer::Integer() {
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(int value) {
	std::cout << "Integer(int)" << std::endl;
	m_pInt = new int(value);
}

Integer::Integer(const Integer & obj) {
	std::cout << "Integer(const Integer&)" << std::endl;
	m_pInt = new int(*obj.m_pInt);
}

Integer::Integer(Integer && obj) {
	std::cout << "Integer(int&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}

int Integer::GetValue() const {
	return *m_pInt;
}

void Integer::SetValue(int value) {
	*m_pInt = value;
}

Integer::~Integer() {
	std::cout << "~Integer()" << std::endl;
	delete m_pInt;
}

// overload the + operator
Integer Integer::operator+(const Integer & a) const {
	Integer temp;
	*temp.m_pInt = *m_pInt + *a.m_pInt;
	return temp;
}

// overload the pre-increment operator 
// note: pre-increment operator does not need to create a temporary variable
// so it is more efficient (returns by reference)
Integer& Integer::operator++() {
	++(*m_pInt);
	return *this;
}

// overload the post-increment operator
Integer Integer::operator++(int) {
	// copy constructor to create temp Integer
	Integer temp(*this);
	++(*m_pInt);

	// temp is temporary variable, so we cannot return it by reference
	return temp;
}

// overloaded comparison operator
bool Integer::operator==(const Integer &a) const {
	return *m_pInt == *a.m_pInt;
}

// overloaded copy assignment operator
Integer& Integer::operator=(const Integer &a) {
	std::cout<<"Overloaded assignment."<<std::endl;
	// first verify that we aren't assigning something to itself
	if(this !=&a) {
		// delete the memory for the existing value to prevent memory leak
		delete m_pInt;
		m_pInt = new int(*a.m_pInt);
	}
	return *this;
}

// overloaded move assignment operator
Integer& Integer::operator=(Integer &&a) {
	if(this != &a) {
		delete m_pInt;
		m_pInt = a.m_pInt;
		a.m_pInt = nullptr;
	}
	return *this;
}

// type conversion operator
Integer::operator int() {
	std::cout<<"type conversion operator"<<std::endl;
	return *m_pInt;
}

// global insertion operator overload (because it's a member of the ostream class
// we need to do it as a global overload, or as a friend to the class)
std::ostream& operator <<(std::ostream& out, const Integer &a) {
    out<<"a = "<<a.GetValue();
    return out;
}

// global extraction operator overload
std::istream& operator >>(std::istream& input, Integer &a) {
    int x;
    input >> x;
    a.SetValue(x);
    return input;
}

// when declared as a friend we can directly access private members
/*
std::istream& operator >>(std::istream& input, Integer &a) {
	int x;
	input >> x;
	*a.m_pInt = x;
	return input;
}
*/

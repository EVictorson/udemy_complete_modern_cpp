#include "employee.h"
#include <iostream>

int Employee::id_generator_ = 1;

Employee::Employee() {
    id_ = ++id_generator_;
    
}

Employee::Employee(std::string name, float salary) :
 name_(name), salary_(salary) {
    id_ = ++id_generator_;
    std::cout<<"Employee name: "<<name<<" , ID: "<<id_<<std::endl;
}

Employee::~Employee() {
    std::cout<<"~Employee()"<<std::endl;
}

std::string Employee::getName() const {
    return name_;
}

int Employee::getId() const {
    return id_;
}

float Employee::getSalary() const {
    return salary_;
}

std::ostream& operator <<(std::ostream& out, const Employee &emp) {
    out<<"Name: "<<emp.getName()<<", ";
    out<<"ID: "<<emp.getId()<<", ";
    out<<"Salary: "<<emp.getSalary()<<std::endl;
}
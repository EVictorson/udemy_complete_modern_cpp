#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
public:
    Employee();
    Employee(std::string name, float salary);
    //Employee(const Employee &emp);
    //Employee(Employee &&emp);
    ~Employee();
    std::string getName()const;
    int getId()const;
    float getSalary()const;


private:
    std::string name_{};
    int id_;
    static int id_generator_;
    float salary_{};
};

std::ostream& operator <<(std::ostream& out, const Employee &emp);


#endif
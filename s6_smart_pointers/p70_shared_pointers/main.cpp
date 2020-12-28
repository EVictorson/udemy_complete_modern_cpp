#include "integer.h"
#include <memory>

class Project {
public:
    ~Project() {
        std::cout<<"~Project()"<<std::endl;
    }

};

class Employee {
    std::shared_ptr<Project> m_pProject;

public:
    ~Employee() {
        std::cout<<"~Employee()"<<std::endl;
    }

    void SetProject(std::shared_ptr<Project> p) {
        m_pProject = p;
    }

    std::shared_ptr<Project> GetProject()const {
        return m_pProject;
    }
};

std::shared_ptr<Employee> AssignProject() {
    // create shared_ptr p with direct initialization
    std::shared_ptr<Project> p{new Project{}};
    Employee *e1 = new Employee{};
    e1->SetProject(p);
    return std::shared_ptr<Employee>{e1};
}

int main() {
    std::cout<<"In this example of shared pointers, you should see both destructors called."<<std::endl;
    auto sp = AssignProject();
    
    // check that the underlying pointer is not nullptr, then do something
    if(sp == nullptr) {

    }
    // get the underlying pointer
    sp.get();
    // reset the smart pointer
    sp.reset(new Employee{});
    
    return 0;
}
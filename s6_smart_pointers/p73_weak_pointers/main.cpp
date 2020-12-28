#include <iostream>
#include <memory>
class Employee;

class Project {
public:
    int blah{10};
    std::shared_ptr<Employee> m_emp;
    Project() {
        std::cout<<"Project()"<<std::endl;
    }
    ~Project() {
        std::cout<<"~Project()"<<std::endl;
    }
};

class Employee {
public:
    int blarg{2};
    //std::shared_ptr<Project> m_prj;
    std::weak_ptr<Project> m_prj;
    Employee() {
        std::cout<<"Employee()"<<std::endl;
    }
    ~Employee() {
        std::cout<<"~Employee()"<<std::endl;
    }

    void Print() {
        std::cout<<"ref count: "<<m_prj.use_count()<<std::endl;
        if(m_prj.expired()) {
            std::cout<<"Resource is no longer available"<<std::endl;
            return;
        }
        // lock method returns a shared pointer so we can access what the resource is pointing to.
        auto sp = m_prj.lock();
        // with the shared pointer we can then access the value / object being pointed to
        std::cout<<"weak pointer is pointing to object w/ val of: "<<sp->blah<<std::endl;
    }
};

int main() {
    std::shared_ptr<Employee> emp{new Employee{}};
    std::shared_ptr<Project> prj{new Project{}};
    std::cout<<"prj.use_count() = "<<prj.use_count()<<std::endl;
    std::cout<<"emp.use_count() = "<<emp.use_count()<<std::endl;
    emp->m_prj = prj;
    prj->m_emp = emp;

    emp->Print();

    std::cout<<"prj.use_count() = "<<prj.use_count()<<std::endl;
    std::cout<<"emp.use_count() = "<<emp.use_count()<<std::endl;
    
    // with this implementation neither destructor is called and we leak memory.
    // This is because with shared pointers, we've copy assigned them to each other
    // so the reference count is two
    /*
    Employee()
    Project()
    prj.use_count() = 1
    emp.use_count() = 1
    prj.use_count() = 2
    emp.use_count() = 2
    */
    // in order to prevent circular references like this from happening we can use a weak pointer
    // instead of one of the shared pointer member variables.

    // by changing one of the shared_ptrs to a weak pointer we get:
    /*
    Employee()
    Project()
    prj.use_count() = 1
    emp.use_count() = 1
    prj.use_count() = 1
    emp.use_count() = 2
    ~Project()
    ~Employee()
    */

}
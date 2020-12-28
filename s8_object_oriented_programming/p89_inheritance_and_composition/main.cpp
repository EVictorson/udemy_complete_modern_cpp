#include <iostream>

class Animal {
public:
    void Eat() {
        std::cout<<"Animal Eating"<<std::endl;
    }

    void Run() {
        std::cout<<"Animal Running"<<std::endl;
    }

    void Speak() {
        std::cout<<"Animal Speaking"<<std::endl;
    }
};

class Dog : public Animal {
public:
    void Eat() {
        std::cout<<"Dog Eating"<<std::endl;
    }
    
    void Speak() {
        std::cout<<"Dog Speaking"<<std::endl;
    }
};

int main() {
    Dog d;
    d.Eat();
    d.Run();
    d.Speak();

    return 0;
}
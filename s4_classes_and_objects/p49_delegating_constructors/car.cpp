#include "car.h"
#include <iostream>

// static member variable needs to be defined in implementation file
int Car::total_count = 0;

// delegating default constructor
Car::Car():Car(0) {
    std::cout<<"Car()"<<std::endl;
}

// delegating constructor
Car::Car(float amount):Car(amount, 0) {
    std::cout<<"Car(float)"<<std::endl;
}

// delegating constructor
Car::Car(float amount, int num_pass) {
    std::cout<<"Car(float, int)"<<std::endl;
    ++total_count;
    fuel = amount;
    speed = 0;
    passengers = num_pass;
}

// destructor
Car::~Car() {
    --total_count;
    std::cout<<"~Car()"<<std::endl;
}


void Car::FillFuel(float amount) {
    fuel = amount;
}

void Car::Accelerate() {
    // this pointer
    this->speed++;
    this->fuel -=0.5;
}

void Car::Brake() {
    speed = 0;
}

void Car::AddPassengers(int count) {
    passengers = count;
}

// const member function, nothing in here can modify the class's internal state
void Car::Dashboard()const {
        std::cout << "Fuel:" << fuel << std::endl;
        std::cout << "Speed:" << speed << std::endl;
        std::cout << "Passengers:" << passengers << std::endl;
}

void Car::ShowCount() {
        std::cout << "Total cars : " << total_count << std::endl;
}


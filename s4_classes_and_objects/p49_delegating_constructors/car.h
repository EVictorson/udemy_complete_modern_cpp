#pragma once

class Car {
public:
    Car();
    Car(float amount);
    Car(float amount, int num_pass);
    ~Car();
    void FillFuel(float amount);
    void Accelerate();
    void Brake();
    void AddPassengers(int count);
    void Dashboard()const;
    static void ShowCount();

private:
    float fuel;
    float speed;
    int passengers;
    static int total_count;
};
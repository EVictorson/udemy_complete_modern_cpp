// using const

#include <iostream>

int main() {
    float radius = 3.0;

    // PI cannot be changed after initialization
    // use capital letters to specify cannot be changed after compile time
    const float PI = 3.14159;
    float area = PI * radius * radius;
    float circumference = PI * 2 * radius;

    // PI = 2.0; gives error: expression must be a modifiable lvalueC/C++

    std::cout<<"Area is : "<<area<<std::endl;
    std::cout<<"Circumerence is :"<<circumference<<std::endl;

    return 0;
}
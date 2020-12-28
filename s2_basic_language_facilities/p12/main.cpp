/* This is moving so slow */

#include <iostream>
#include <vector>

int main() {
    int i{0};
    std::cout<<"int i = "<<i<<std::endl;
    char ch = 'a';
    std::cout<<"char ch = "<<ch<<std::endl;
    float f = 1.28;
    std::cout<<"float f = "<<f<<std::endl;
    double d = 521.123;
    std::cout<<"double d = "<<d<<std::endl;
    int arr[5]{1,2,3,4,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    for(i=0; i<size; i++) {
        std::cout<<"arr[i] = "<<arr[i]<<std::endl;
    }
    std::cout<<"arr memory addr = "<<arr<<std::endl;
}
#include <iostream>

int main() {
    char buffer[512];
    std::cout<<"What is your name?"<<std::endl;
    std::cin.getline(buffer, 64, '\n');
    std::cout<<"Your name is "<<buffer<<std::endl;
}
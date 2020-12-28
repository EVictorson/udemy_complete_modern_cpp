#include <iostream>
#include <sstream>

int main() {
    int a{5}, b{6};
    int sum = a + b;
    std::stringstream ss;
    ss <<"Sum of "<<a<<" and "<<b<<" is : "<<sum<<std::endl;
    std::string s = ss.str();
    std::cout<<s<<std::endl;
    // clear the contents of the string stream
    ss.str("");
    ss<<sum;
    auto ssum = "ssum = " + std::to_string(sum);
    std::cout<< ssum <<std::endl;

    std::string data = "12 34 56";
    int a2;
    std::stringstream ss2;
    ss2.str(data);

    // this while loop will check the ss.fail() bit
    while (ss2 >> a2) {
        std::cout<<a2<<std::endl;
    }

    return 0;
}
#include <iostream>
#include <string>
#include <cstring>
// assignment: implement a ToUpper and ToLower function for strings

std::string ToUpper(const std::string &str) {
    std::string s;
    for(char const &c : str) {
        s += toupper(c);
    }
    return s;
}

std::string ToLower(const std::string &str) {
    std::string s;
    for(char const &c : str) {
        s += tolower(c);
    }
    return s;
}

int main() {
    std::string test_str = "hello";
    std::string out_str = ToUpper(test_str);
    std::cout<<"output string = "<<out_str<<std::endl;
    out_str = ToLower(out_str);
    std::cout<<"output string = "<<out_str<<std::endl;

    return 0;
}
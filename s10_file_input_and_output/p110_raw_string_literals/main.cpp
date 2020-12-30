#include <iostream>
#include <string>

int main() {
    // notice how when this prints it recognizes the \t and \n special characters

    std::string filename{"C:\temp\newfile.txt"};
    std::string rsl_filename{R"(C:\temp\newfile.txt)"};

    // in C++17 we have custom delimeters too:
    std::string msg{R"MSG(C++ introducted filesystem API" (In C++17))MSG"};

    std::cout<<"Filename = "<<filename<<std::endl;
    std::cout<<"rsl_filename = "<<rsl_filename<<std::endl;
    std::cout<<"msg = "<<msg<<std::endl;
}
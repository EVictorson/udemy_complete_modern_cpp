#include <iostream>
#include <string>

void StringDemo() {
    //Initialization and assignment
    std::string s = "hello";
    s = "Hello!";

    // access via subscript operator
    s[0] = 'W';
    char ch = s[0];

    std::cout<<"s = "<<s<<std::endl;
    //std::cin>>s;

    std::cout<<"Enter new value for string s:"<<std::endl;
    std::getline(std::cin, s);

    // size
    // note, length() is cached and is thus of constant time
    // whereas c-style strlen is of linear time
    std::cout<<"length of s is: "<<s.length()<<std::endl;
    std::cout<<"s = "<<s<<std::endl;

    // insert and concatenate
    std::string s1{"Hello!"}, s2{"World!"};
    // string class overloads + and += operators for concatenation
    s = s1 + s2;
    s += s1;
    std::cout<<"s = "<<s<<std::endl;

    s.insert(6, "World");

    // comparison
    if(s1 != s2) {
        std::cout<<"s1 != s2"<<std::endl;
    }

    // removal
    // erase all characters from the string
    //s.erase();
    // erase first 5 characters of the string
    s.erase(0, 5);
    std::cout<<"s = "<<s<<std::endl;
    // also erase all characters from string
    s.clear();

    // search
    auto pos = s.find("World", 0);
    if(pos != std::string::npos) {
        //found
    }
}

std::string Combine(std::string first, std::string last) {
    std::string fullname = first + " " + last;
    return fullname;
}

int main() {
    StringDemo();

    std::string first_name;
    std::string last_name;
    std::cout<<"Enter first name:"<<std::endl;
    std::getline(std::cin, first_name);
    std::cout<<"Enter last name:"<<std::endl;
    std::getline(std::cin, last_name);

    std::string fullname = Combine(first_name, last_name);
    std::cout<<"Fullname = "<<fullname<<std::endl;

    // can also access the raw c-style string
    std::cout<<"Fullname cstring = "<<fullname.c_str()<<std::endl;

    // always prefer direct initialization with c++11+
    std::string name{"Harry Potter"};

    return 0;
}
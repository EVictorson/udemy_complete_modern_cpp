#include <iostream>
#include <string>
#include <sstream>
#include <vector>

enum class Case{SENSITIVE, INSENSITIVE};

std::string ToLower(const std::string &str) {
    std::string s;
    for(char const &c : str) {
        s += tolower(c);
    }
    return s;
}

std::string ToUpper(const std::string &str) {
    std::string s;
    for(char const &c : str) {
        s += toupper(c);
    }
    return s;
}

size_t FindCore( 
  const std::string &source,
  const std::string &search_string,
  size_t offset) {
    std::string temp = source.substr(offset);
    std::cout<<"\ntrimmed substr = "<<temp;
    std::size_t found = temp.find(search_string);
    // note: will return std::string::npos (-1) if not found
    if(found==std::string::npos) {
        std::cout<<"\nsubstr not found."<<std::endl;
    }
    return found;
}

/** Find, returns position of the first character of a search substring, else std::string::npos */
size_t Find(
 const std::string &source,         //Source string to be searched
 const std::string &search_string,  //The string to search for
 Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
 size_t offset = 0 ) {                //Start the search from this offset
    std::size_t found;
    std::string temp_source = source;
    std::string temp_search = search_string;
    if(searchCase==Case::INSENSITIVE) {
        temp_source = ToLower(source);
        temp_search = ToLower(search_string);
    }
    found = FindCore(temp_source, temp_search, offset);
    return found;
}

std::vector<int> FindAll(
 const std::string &source,         //Target string to be searched
 std::string &search_string,         //The string to search for
 Case searchCase = Case::INSENSITIVE,//Choose case sensitive/insensitive search
 size_t offset = 0) {                //Start the search from this offset
    std::vector<int> found_vec;
    size_t found{offset};
    while(found != std::string::npos) {
        found = Find(source, search_string, searchCase, offset);
        if(found!= std::string::npos) {
            offset += found;
            found_vec.push_back(offset);
            offset += 1;
        }
        else {
            found_vec.push_back(found);
        }

    }
    return found_vec;
 }

void PrintVec(std::vector<int> &v) {
    for(auto x: v){
        std::cout<<x<<std::endl;
    }
}

int main() {
    std::cout<<"Insensitive search demo."<<std::endl;
    std::string source{"Throw roSes InTo the abyss to thank the demons that failed to consume us."};
    std::string search_string{"tHe"};
    std::cout<<"source string = "<<source<<std::endl;
    std::cout<<"search_string = "<<search_string<<std::endl;

    size_t found = Find(source, search_string, Case::INSENSITIVE);
    std::cout<<"\nFound search string at position "<<found<<std::endl;

    std::cout<<"\n\nSensitive search demo."<<std::endl;
    found = Find(source, search_string, Case::SENSITIVE);
    std::cout<<"\nFound search string at position "<<found<<std::endl;

    std::cout<<"\nFindAll() Demo"<<std::endl;
    std::vector<int> found_vec = FindAll(source, search_string, Case::INSENSITIVE);
    PrintVec(found_vec);


    return 0;
}

// output from main
/*
Insensitive search demo.
source string = Throw roSes InTo the abyss to thank the demons that failed to consume us.
search_string = tHe

trimmed substr = throw roses into the abyss to thank the demons that failed to consume us.
Found search string at position 17


Sensitive search demo.

trimmed substr = Throw roSes InTo the abyss to thank the demons that failed to consume us.
substr not found.

Found search string at position 18446744073709551615

FindAll() Demo

trimmed substr = throw roses into the abyss to thank the demons that failed to consume us.
trimmed substr = he abyss to thank the demons that failed to consume us.
trimmed substr = he demons that failed to consume us.
substr not found.
17
36
-1
*/
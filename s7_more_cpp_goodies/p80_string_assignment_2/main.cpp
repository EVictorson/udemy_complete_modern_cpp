#include <iostream>
#include <string>
#include <sstream>

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
    std::size_t found = temp.find(search_string);
    // note: will return std::string::npos (-1) if not found
    if(found==std::string::npos) {
        std::cout<<"substr not found."<<std::endl;
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

int main() {
    std::cout<<"Insensitive search demo."<<std::endl;
    std::string source{"Throw roSes InTo the abyss."};
    std::string search_string{"RosE"};
    std::cout<<"source string = "<<source<<std::endl;
    std::cout<<"search_string = "<<search_string<<std::endl;

    size_t found = Find(source, search_string, Case::INSENSITIVE);
    std::cout<<"Found search string at position "<<found<<std::endl;

    std::cout<<"\nSensitive search demo."<<std::endl;
    found = Find(source, search_string, Case::SENSITIVE);
    std::cout<<"Found search string at position "<<found<<std::endl;

    return 0;
}

// main output:
/*
Insensitive search demo.
source string = Throw roSes InTo the abyss.
search_string = RosE
Found search string at position 6

Sensitive search demo.
substr not found.
Found search string at position 18446744073709551615
*/
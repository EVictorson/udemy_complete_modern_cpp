#include <iostream>
#include <vector>
#include <list>

const char * GetErrorMessage(int errorNo) {
    std::cout<<"errorno: "<<errorNo<<std::endl;
    return "Empty";
}

//typedef const char *(PFN)(int);
// alias is more natural than typedef
using PFN = const char *(*)(int);
void ShowError(PFN pfn) {
    *pfn(1);
}

//typedef std::vector< std::list<std::string>> Names;

//template<typename T>
//using Names = std::vector<std::list<T>>;

using Names = std::vector<std::list<std::string>>;


int main() {
    Names names;
    //Names<Names<std::string>> nnames;
    PFN pfn = GetErrorMessage;
    ShowError(pfn);

    return 0;
}
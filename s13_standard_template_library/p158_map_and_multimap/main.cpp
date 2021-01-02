#include <iostream>
#include <map>
#include <string>

void Map() {
    // accepts template parameters: type of key, type of value, comparator object, allocator
    std::map<int, std::string>  m{
        {1, "superman"},
        {2, "batman"},
        {3, "green lantern"}
    };

    m.insert(std::pair<int, std::string>(8, "aquaman"));

    // can also accept factory method std::make_pair
    m.insert(std::make_pair(6, "wonder woman"));

    m[0] = "flash";

    auto itr = m.begin();
    std::cout<< itr->first << " : "<<itr->second<<std::endl;

    // will print according to sorted keys
    for( const auto &x: m) {
        std::cout<< x.first << " : "<<x.second<<std::endl;

    }

    // be careful about using subscripts, if the index isn't found, it will add an element with that key
    // with a value initialized to default for that type
    // avoid using subscript operator for searching in the map
    std::cout<<"10: "<<m[10]<< std::endl;

    // to remove an element use erase() function w/ either position or key
    std::cout<<"After erasing the first element"<<std::endl;
    m.erase(0);
    for( const auto &x: m) {
        std::cout<< x.first << " : "<<x.second<<std::endl;

    }

    // to perform search operation use find(<key>)
    // if find fails it will return iterator to the end
    itr = m.find(1);
    if (itr != m.end()) {
        std::cout<<"Found: "<<itr->second<<std::endl;
    }
    else {
        std::cout<<"Not Found."<<std::endl;
    }


    //Note: map does not allow duplicate keys, whereas multimap does

    std::multimap<int, std::string> mm {
        {1, "superman"},
        {2, "batman"},
        {3, "green lantern"}
    };

    mm.insert(std::pair<int, std::string>(8, "aquaman"));
    // can also accept factory method std::make_pair
    mm.insert(std::make_pair(6, "wonder woman"));
    mm.insert(std::make_pair(6, "powergirl"));
    std::cout<<"\nmultimap allows duplicate keys: "<<std::endl;
    for( const auto &x: mm) {
        std::cout<< x.first << " : "<<x.second<<std::endl;
    }

    std::cout<<"\nmm.equal_range():"<<std::endl;
    auto found = mm.equal_range(6);
    while(found.first != found.second) {
        std::cout<<found.first->first <<" : "<<found.first->second<<std::endl;
        found.first++;
    }

}


int main() {
    Map();

    return 0;
}
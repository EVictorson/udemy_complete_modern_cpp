#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>

void UnorderedSet() {
    std::unordered_multiset<std::string> u;
    u.insert("hulk");
    u.insert("batman");
    u.insert("green lantern");
    u.insert("the flash");
    // note, as we increase the number of elements, the load factor increases until the hash table needs to be re-hashed
    u.insert("wonder woman");
    u.insert("iron man");
    u.insert("iron man");
    u.insert("iron man");
    u.insert("wolverine");
    u.insert("dr strange");
    u.insert("hawkman");

    for (const auto x:u) {
        std::cout<<"Bucket #: "<<u.bucket(x)<<" contains: "<< x << std::endl;
    }

    std::cout<<"Bucket count: "<<u.bucket_count()<<std::endl;
    std::cout<<"Number of elements: "<<u.size()<<std::endl;
    std::cout<<"Load factor: "<<u.load_factor()<<std::endl;


}

void UnorderedMap() {
    std::cout<<"UnorderedMap()"<<std::endl;
    std::unordered_map<std::string, std::string> coll;
    coll["Batman"] = "Bruce Wayne";
    coll["Superman"] = "Clark Kent";
    coll["Hulk"] = "Bruce Banner";

    for (const auto &x : coll) {
        std::cout<<"Bucket #: "<<coll.bucket(x.first) << " -> "<<x.first<<": "<<x.second<<std::endl;
    }
}

// when using hash tables with user defined classes, will need to overload comparison operators
class Employee {
    std::string m_Name;
    int m_Id;
public:
    Employee(const std::string &n, int id) :m_Name(n), m_Id(id) {

    }
    const std::string & GetName()const {
        return m_Name;
    }
    int GetId()const {
        return m_Id;
    }
};

//Custom hash function
struct EmployeeHash {
    size_t operator()(const Employee & emp)const {
        auto s1 = std::hash<std::string>{}(emp.GetName());
        auto s2 = std::hash<int>{}(emp.GetId());
        return s1 ^ s2;
    }
};

//Custom function object for equality
struct EmpEquality {
    bool operator()(const Employee &e1, const Employee e2)const {
        return e1.GetId() == e2.GetId();
    }
};
void Hashes() {
    std::cout<<"Hashes()"<<std::endl;
    std::hash<std::string> h;
    //Hash is computed by the function object
    std::cout << "Hash:" << h("Hello") << std::endl;


    std::unordered_set<Employee, EmployeeHash, EmpEquality> coll;
    coll.insert(Employee("Umar", 123));
    coll.insert(Employee("Bob", 678));
    coll.insert(Employee("Joey", 612));

    for (const auto &x : coll) {
        std::cout << x.GetId() << ":" << x.GetName() << std::endl;
    }
}


int main() {
    UnorderedSet();
    UnorderedMap();
    Hashes();

    return 0;
}
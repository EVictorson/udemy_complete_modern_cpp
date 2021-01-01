#include <iostream>
#include <vector>

template<typename T>
class PrettyPrinter {
    T *m_pData;

public:
    PrettyPrinter(T *data) : m_pData(data) {

    }

    void Print() {
        std::cout<< "{" << *m_pData << "}" << std::endl;
    }

    T* GetData() {
        return m_pData;
    }
};

// explicitly specialize a single member function for a special type
template<>
void PrettyPrinter<std::vector<int>>::Print() {
    std::cout<< "{";
    for (const auto &x : *m_pData) {
        std::cout<< x;
    }
    std::cout << "}"<<std::endl;
}

// explicit specialization of member function for vector of vector<int>
template<>
void PrettyPrinter<std::vector<std::vector<int>>>::Print() {
    std::cout<<"{";
    for (const auto &i : *m_pData) {
        std::cout<< "{";
        for (const auto &j : i) {
            std::cout<<j;
            if (j != i.back()) {
                std::cout<<",";     
            }
        }
        std::cout<< "}";
        if(i != m_pData->back()){
            std::cout<<","<<std::endl;
        }
    }
    std::cout<< "}"<<std::endl;
}


template<>
class PrettyPrinter<char*> {
    char *m_pData;

public:
    PrettyPrinter(char *data) :m_pData(data) {

    } 

    void Print() {
        std::cout<< "{" << m_pData << "}"<<std::endl;
    }

    char* GetData() {
        return m_pData;
    }

};

int main() {
    int data = 5;
    float f = 8.2f;

    PrettyPrinter<int> p1(&data);
    p1.Print();
    PrettyPrinter<float> p2(&f);
    p2.Print();

    char *p{"Hello World"};
    PrettyPrinter<char*> p3(p);
    p3.Print();
    char *pData = p3.GetData();

    std::vector<int> v{1,2,3,4,5};
    std::vector<int> v2{6,7,8,9,10};
    std::vector<int> v3{11, 12, 13, 14, 15};
    PrettyPrinter<std::vector<int>> pv(&v);
    pv.Print();

    std::vector<std::vector<int>> vv{v, v2, v3};
    PrettyPrinter<std::vector<std::vector<int>>> pvv(&vv);
    pvv.Print();
    

    return 0;
}
#include <iostream>

class Distance {
    long double m_Kilometers;

public:
    Distance(long double km) : m_Kilometers{km} {

    }
    
    long double GetKm()const {
        return m_Kilometers;
    }

    void SetKm(long double val) {
        m_Kilometers = val;
    }
};

Distance operator"" _mi(long double val) {
    return Distance{val * 1.609};
}

Distance operator""_meters(long double val) {
    return Distance{val / 1000};
}

int main() {
    Distance dist{32.0_mi};
    Distance dist2{7123.0_meters};
    std::cout<<"dist.GetKm() = "<<dist2.GetKm()<<std::endl;
    return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <utility>

/*
Create lambda expressions & their equivalent function objects for the following functions.

T Max(T, T); //Return largest element
bool Greater(T, T) ; //Return true if first argument is greater than the second
bool Less(T, T) ; //Return true if first argument is less than the second
pair<T,T> MinMax(ItrBegin, ItrEnd) ;//Accept iterators of any container and return the largest and smallest element from that container.
*/



// ========================== 1 ========================== 
// create lambda expression and equivalent functor for T Max(T, T)

// 1. equivalent function object (functor) for: T Max(T, T) // return largest element
template <typename T>
struct MaxFunctor {
    T operator()(T x, T y) {
        return x > y ? x : y;
    }
};

void eval_max() {
    std::cout<<" == 1 =="<<std::endl;

    // 1. lambda expression for: T Max(T, T); //Return largest element
    auto max = [](auto x, auto y) {
        return x > y ? x : y;
    };

    std::cout<<"lambda expression max = "<<max(3.3, 2.2)<<std::endl;
    std::cout<<typeid(max).name()<<std::endl;

    MaxFunctor<float> max_functor;
    std::cout<<"Function object max = "<<max_functor(3.3, 2.2)<<std::endl;
    std::cout<<typeid(max_functor).name()<<std::endl;
}

// ========================== 2 ========================== 
// create lambda expression and equivalent functor for bool Greater(T, T)
// return true if first argument is greater than the second

template<typename T>
struct GreaterFunctor {
    bool operator()(T x, T y) {
        return (x > y);
    }
};

void eval_greater() {
    std::cout<<"\n == 2 =="<<std::endl;

    auto greater = [](auto x, auto y) -> bool{
        return (x > y);
    };

    std::cout<<"lambda expression greater(3.3, 2.2) = "<<greater(3.3, 2.2)<<std::endl;
    std::cout<<"lambda expression greater(2.2, 3.3) = "<<greater(2.2, 3.3)<<std::endl;
    std::cout<<typeid(greater).name()<<std::endl;

    GreaterFunctor<float> greater_functor;
    std::cout<<"function object greater(3.3, 2.2) = "<<greater_functor(3.3, 2.2)<<std::endl;
    std::cout<<"function object greater(2.2, 3.3) = "<<greater_functor(2.2, 3.3)<<std::endl;
    std::cout<<typeid(greater_functor).name()<<std::endl;
}

// ========================== 3 ========================== 
// create lambda expression and equivalent functor for bool Less(T, T)
// return true if first argument is less than the second

template<typename T>
struct LessFunctor {
    bool operator()(T x, T y) {
        return (x < y);
    }
};

void eval_less() {
    std::cout<<"\n == 3 =="<<std::endl;

    auto less = [](auto x, auto y) -> bool {
        return (x < y);
    };

    std::cout<<"lambda expression less(3.3, 2.2) = "<<less(3.3, 2.2)<<std::endl;
    std::cout<<"lambda expression less(2.2, 3.3) = "<<less(2.2, 3.3)<<std::endl;
    std::cout<<typeid(less).name()<<std::endl;


    LessFunctor<float> less_functor;
    std::cout<<"function object less(3.3, 2.2) = "<<less_functor(3.3, 2.2)<<std::endl;
    std::cout<<"function object less(2.2, 3.3) = "<<less_functor(2.2, 3.3)<<std::endl;
    std::cout<<typeid(less_functor).name()<<std::endl;

}
// ========================== 4 ========================== 
// create lambda expression and equivalent functor for:
// pair<T,T> MinMax(ItrBegin, ItrEnd) ;//Accept iterators of any container and return the largest and smallest element from that container.


template<typename T>
struct MinMaxFunctor {
    auto operator()(T itr_begin, T itr_end) {
        auto pair = std::make_pair(*itr_begin, *itr_begin);
        for (auto iter = itr_begin; iter != itr_end; ++iter) {
            if (*iter > pair.second) {
                pair.second = *iter;
            }
            if (*iter < pair.first) {
                pair.first = *iter;
            }
        }
        return pair;
    }
};

void eval_minmax() {
    std::cout<<"\n == 4 =="<<std::endl;

    std::vector<float> v{1.1 ,2,3,4,5};
    std::vector<int> v1{1, 5, 3, 10, 2};


    auto greater = [](auto x, auto y) -> bool{
        return (x > y);
    };

    auto less = [](auto x, auto y) -> bool{
        return (x < y);
    };

    // capture everything by reference so we can call other lambda expressions
    auto minmax = [&](auto itr_begin, auto itr_end) { 
        auto pair = std::make_pair(*itr_begin, *itr_begin);
        for (auto iter = itr_begin; iter != itr_end; ++iter) {
            if (greater(*iter, pair.second)) {
                pair.second = *iter;
            }
            if (less(*iter, pair.first)) {
                pair.first = *iter;
            }
        }
        return pair;
    };

    auto pair = minmax(v.begin(), v.end());
    std::cout<<"lambda expression minmax(v.begin(), v.end()) = "<<pair.first<<", "<<pair.second<<std::endl;
    auto pair1 = minmax(v1.begin(), v1.end());
    std::cout<<"lambda expression minmax(v1.begin(), v1.end()) = "<<pair1.first<<", "<<pair1.second<<std::endl;

    MinMaxFunctor<decltype(v1.begin())> minmax_functor;
    auto pair3 = minmax_functor(v1.begin(), v1.end());
    std::cout<<"functor minmax(v1.begin(), v1.end() = "<<pair3.first<<", "<<pair3.second<<std::endl;

}


int main() {
    eval_max();

    eval_greater();

    eval_less();

    eval_minmax();


    return 0;
}
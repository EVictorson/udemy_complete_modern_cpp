#include <iostream>
#include <thread>

void Process() {
    std::cout<<"Threadid: "<<std::this_thread::get_id()<<std::endl;
    for (int i = 0; i< 10; ++i) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout<< i << std::endl;
    }

}


int main() {
    std::thread t1(Process);
    auto id = t1.get_id();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    std::cout<<"Thread id: "<<id<<std::endl;
    std::cout<<"Native handle: "<<t1.native_handle()<<std::endl;

    int cores = std::thread::hardware_concurrency();
    std::cout<<"Cores: "<<cores<<std::endl;

    t1.join();

    return 0;
}
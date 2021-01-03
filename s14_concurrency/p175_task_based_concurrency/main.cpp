#include <iostream>
#include <thread>
#include <future>

void Downloader() {
    using namespace std::chrono_literals;
    for(int i = 0; i < 10; ++i) {
        std::cout<<"."<<std::endl;
        std::this_thread::sleep_for(300ms);
    }
}

int Operation(int count) {
    using namespace std::chrono_literals;
    int sum{};
    for(int i = 0; i < count; ++i) {
        sum += i;
        std::cout<<"."<<std::endl;
        std::this_thread::sleep_for(300ms);
    }

    return sum;
}

int main() {
    using namespace std::chrono_literals;

    std::future<int> result = std::async(std::launch::async, Operation, 10);
    std::cout<<"main() thread continues execution..."<<std::endl;
    std::this_thread::sleep_for(1s);

    if(result.valid()) {
        auto timepoint = std::chrono::system_clock::now();
        timepoint += 1s;
        // wait() acts like get() (it blocks the calling thread), 
        // except it doesn't return the shared state
        //result.wait();

        // as an alternative to wait_for, can use wait_until
        auto status = result.wait_until(timepoint);

        // because task takes 3 seconds and we only wait for 1, it will timeout
        // wait_for() in a loop can used to periodically check the shared state
        //auto status = result.wait_for(1s);
        switch (status) {
            case std::future_status::deferred:
                std::cout<<"status is deferred"<<std::endl;
                break;
            case std::future_status::ready:
                std::cout<<"status is ready"<<std::endl;
                break;
            case std::future_status::timeout:
                std::cout<<"status is timeout"<<std::endl;
                break;
        }
        auto sum = result.get();
        std::cout<<"Sum = "<<sum<<std::endl;
    }

    // will make the main thread wait
    //result.get();
    return 0;
}
#include <iostream>
#include <thread>
#include <future>

int Operation(std::promise<int> &data) {
    using namespace std::chrono_literals;
    auto f = data.get_future();
    try {
        std::cout<<"[Task] Waiting for count."<<std::endl;
        auto count = f.get();
        std::cout<<"[Task] Count acquired."<<std::endl;
        int sum{};
        for(int i = 0; i < count; ++i) {
            sum += i;
            std::cout<<"."<<std::endl;
            std::this_thread::sleep_for(300ms);
        }

        return sum;
    }
    catch(std::exception&ex) {
        std::cout<<"[Task] exception: "<<ex.what()<<std::endl;
    }

}

int main() {
    using namespace std::chrono_literals;
    std::promise<int> data;

    std::future<int> result = std::async(std::launch::async, Operation, std::ref(data));
    std::this_thread::sleep_for(2s);
    std::cout<<"main() Setting the data in the promise."<<std::endl;
    try {
        throw std::runtime_error{"Data not available"};
        data.set_value(10);

        if(result.valid()) {
            auto sum = result.get();
            std::cout<<"sum = "<<sum << std::endl;
        }
    }
    catch(std::exception &ex) {
        // by using set_exception we can pass the exception to the task
        data.set_exception(std::make_exception_ptr(ex));
    }


    return 0;
}
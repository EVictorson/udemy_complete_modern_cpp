#include <iostream>
#include <list>
#include <thread>
#include <string>
#include <mutex>

std::list<int> g_Data;
std::list<int> g_Data2;
const int SIZE = 10000;

std::mutex g_Mutex;

void Download(std::string &file) {
    for (int i = 0; i < SIZE; ++i) {
        g_Data.push_back(i);
    }
}

void Download2(std::string &file) {
    for (int i = 0; i < SIZE; ++i) {
        g_Data.push_back(i);
    }
}

// using lock_gaurd (RAII) (scope based resource acquisition)
// we can prevent deadlocks by ensuring that locks are unlocked 
// when execution goes out of scope.
void DownloadWithSemaphores(std::string &file) {
    for (int i = 0; i < SIZE; ++i) {
        std::lock_guard<std::mutex> mtx(g_Mutex);
        g_Data2.push_back(i);
    }
}

void DownloadWithSemaphores2(std::string &file) {
    for (int i = 0; i < SIZE; ++i) {
        std::lock_guard<std::mutex> mtx(g_Mutex);
        g_Data2.push_back(i);
    }
}

int main() {
    std::cout<<"[main] User started an operation."<<std::endl;
    
    std::string file{"cppcast.mp4"};

    // create a race condition where two threads are operating on the same list
    // each execution will yield a different sized list since both threads may be 
    // trying to write to the same index.
    std::thread thDownloader(Download, std::ref(file));
    std::thread thDownloader2(Download2, std::ref(file));
    std::thread thDownloader3(DownloadWithSemaphores, std::ref(file));
    std::thread thDownloader4(DownloadWithSemaphores2, std::ref(file));
    std::cout<<"[main] User started another operation."<<std::endl;

    thDownloader.join();
    thDownloader2.join();
    thDownloader3.join();
    thDownloader4.join();

    std::cout<<"Because of race conditions, g_Data.size() should be: "<<(SIZE*2)<<std::endl;
    std::cout<<"Actual g_Data.size(): "<<g_Data.size()<<std::endl;

    std::cout<<"When used with semaphores g_Data2.size() should be: "<<(SIZE*2)<<std::endl;
    std::cout<<"Actual g_Data2.size(): "<<g_Data2.size()<<std::endl;
    return 0;
}
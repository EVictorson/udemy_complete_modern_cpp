#include <iostream>
#include <list>
#include <thread>
#include <string>

std::list<int> g_Data;
const int SIZE = 50000000;

void Download(std::string &file) {
    std::cout<<"[Downloader] Started download of file: "<<file<<std::endl;
    for (int i = 0; i < SIZE; ++i) {
        g_Data.push_back(i);
    }

    std::cout<<"[Downloader] Finished download."<<std::endl;
}

int main() {
    std::cout<<"[main] User started an operation."<<std::endl;
    
    std::string file{"cppcast.mp4"};
    // create as joinable thread
    // thread constructor is variadic
    // we need to use helper function std::ref() if we are passing by reference to thread
    std::thread thDownloader(Download, std::ref(file));

    // if it's a const that we're passing by reference we need to use std::cref()
    // std::thread thDownloader(Download, std::cref(file));

    // if a thread takes a really long time, we can detach it
    // detach the thread
    //thDownloader.detach();

    std::cout<<"[main] User started another operation."<<std::endl;

    // cannot join a detached thread,so check to see if it's joinable
    if (thDownloader.joinable()) {
        // join() is blocking
        thDownloader.join();
    }

    return 0;
}
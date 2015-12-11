// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <set>
#include <thread>
#include <random>
#include <chrono>

using namespace std;

#include <iostream>
#include <condition_variable>
#include <thread>
#include <chrono>
 
std::condition_variable cv;
std::mutex cv_m; // This mutex is used for three purposes:
                 // 1) to synchronize accesses to i
                 // 2) to synchronize accesses to std::cerr
                 // 3) for the condition variable cv
int i = 0;
 
void waits1()
{
    std::unique_lock<std::mutex> lk(cv_m);
    std::cerr << "Waiting... \n";
    cv.wait(lk, []{return i == 1;});
    std::cerr << "...finished waiting. i == 1\n";
    i=4;
    cv.notify_all();
}
 
void waits2()
{
    std::unique_lock<std::mutex> lk(cv_m);
    std::cerr << "Waiting... \n";
    cv.wait(lk, []{return i == 2;});
    std::cerr << "...finished waiting. i == 2\n";
    i=4;
    cv.notify_all();
}

void waits3()
{
    std::unique_lock<std::mutex> lk(cv_m);
    std::cerr << "Waiting... \n";
    cv.wait(lk, []{return i == 3;});
    std::cerr << "...finished waiting. i == 3\n";
    i=4;
    cv.notify_all();
}

 
void signals()
{
 /*   std::this_thread::sleep_for(std::chrono::seconds(1));
    {
        std::lock_guard<std::mutex> lk(cv_m);
        std::cerr << "Notifying...\n";
    }
    cv.notify_all();*/
 
    std::this_thread::sleep_for(std::chrono::seconds(1));

    {
        std::lock_guard<std::mutex> lk(cv_m);
        i = 1;
        std::cerr << "Notifying again1...\n";
        
    }
    cv.notify_all();
    {
        std::unique_lock<std::mutex> lk(cv_m);
        
        cv.wait(lk, []{return i==4;});
        std::cerr << "1...\n";
    }


    {
        std::lock_guard<std::mutex> lk(cv_m);
        i = 2;
        std::cerr << "Notifying again2...\n";
    }
    cv.notify_all();
    {
        std::unique_lock<std::mutex> lk(cv_m);
        
        cv.wait(lk, []{return i==4;});
        std::cerr << "2...\n";
    }

    {
        std::lock_guard<std::mutex> lk(cv_m);
        i = 3;
        std::cerr << "Notifying again3...\n";
    }
    cv.notify_all();
    {
        std::unique_lock<std::mutex> lk(cv_m);
       
        cv.wait(lk, []{return i==4;});
        std::cerr << "3...\n";
    }
}


int _tmain(int argc, _TCHAR* argv[])
{
//    std::set<int> int_set;
//auto f = [&int_set]() {
//    try {
//        std::random_device rd;
//        std::mt19937 gen(rd());
//        std::uniform_int_distribution<> dis(1, 1000);
//        for(std::size_t i = 0; i != 100000; ++i) {
//            int_set.insert(dis(gen));
//        }
//    } catch(...) {}
//};
//std::thread td1(f), td2(f);
//td1.join();
//td2.join();
    while(true) {
    std::thread t2(waits1), t1(waits2), t3(waits3), t4(signals);
    t1.join(); 
    t2.join(); 
    t3.join();
    t4.join();

    }

    system("PAUSE");
	return 0;
}

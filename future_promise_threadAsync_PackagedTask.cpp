#include <iostream>
#include <future>
#include <thread>

int _tmain(int argc, _TCHAR* argv[])
{
    //Printer::Instance()->print();
    /*
    int x = 1;
    int y = 5;
    (x ^= y), (y ^= x), (x ^= y);
     
    std::cout << x << y << std::endl;
    */
    std::packaged_task<int()> task([](){ return 7;});
    std::future<int> p1 = task.get_future();
    
#if 0
    task();
#else
    std::thread(std::move(task)).detach();
#endif
    std::cout << p1.get() << std::endl;



    std::future<int> f2 = std::async(std::launch::async, []() {std::cout << "thread1  " << std::this_thread::get_id()  << std::endl; return 8;});
    std::future<int> f3 = std::async(std::launch::deferred, []() {std::cout << "thread2  " << std::this_thread::get_id()  << std::endl; return 9;});
    std::cout << f2.get() << f3.get() << std::endl;



    //VS2012 error
    std::promise<int> p4;
    std::future<int> f4 = p4.get_future();
    std::thread([](std::promise<int> p4) {p4.set_value_at_thread_exit(10);}, 
                std::move(p4)).detach();
    std::cout << f4.get() << std::endl;

    system("PAUSE");
	return 0;
}

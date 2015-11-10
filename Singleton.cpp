// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <mutex>

using namespace std;


std::mutex mutex1;
std::once_flag of;

class Printer {
    public:
        static Printer* Instance();

        static void deleteInstance();//1

        void print() {
            cout << "LLLL" << val <<  endl;
        }
    private:
        int val;
        static Printer* m_printer;
        Printer() : val(10) {}//3
        Printer(Printer&) {}
        Printer& operator=(Printer&) {}
        
};

Printer* Printer::m_printer = nullptr; //2

Printer* Printer::Instance() {
#if 0
    std::lock_guard<std::mutex> lock(mutex1);

    if(!m_printer) {
        m_printer = new Printer;
    }
#else
    std::call_once(of, [&]() {m_printer = new Printer;});
#endif
    return m_printer;
}



void Printer::deleteInstance() {
    delete m_printer;
}


int _tmain(int argc, _TCHAR* argv[])
{
    Printer::Instance()->print();

    system("PAUSE");
	return 0;
}

#include <iostream>
#include <vector>
#include <list>


template <class T>
void printEle(T t) {
    
    for (auto i : t) {
        std::cout << i << "\t";
    }
    std::cout << "\n";
}

int main(int argc, const char * argv[])
{

    // insert code here...
    std::cout << "Hello, World!\n";
    std::vector<int> v = {1,2,3,4};
    printEle(v);
    
    std::list<int> m = {5,6,7,8};
    printEle(m);
    return 0;
}


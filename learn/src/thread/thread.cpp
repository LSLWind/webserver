//c++11多线程 std::thread
#include <thread>
#include <iostream>

void f1()
{
    std::cout << "f1" << std::endl;
}

int main(int argc, char *argv[])
{
    std::thread t1(f1);
    t1.join();

    return 0;
}

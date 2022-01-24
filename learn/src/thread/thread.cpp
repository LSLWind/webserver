//c++11多线程 std::thread
#include <thread>
#include <iostream>
#include <mutex>
void f1()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "f1" << std::endl;
}
void test()
{
    std::thread t1(f1);
    t1.detach();
    //t1.join();
    std::cout << "test finished" << std::endl;
}
//互斥锁mutex
void shared_mutex()
{
    std::mutex lock;
    lock.lock();
    for (int i = 0; i < 10; i++)
    {
        std::cout << "shared_mutex " << i << std::endl;
    }
    lock.unlock();
}
//使用模板std::lock_guard<std::mutex> 自动管理和释放锁
void mutex_lock_guard()
{
    std::mutex lock;
    {
        std::lock_guard<std::mutex> lockGuard(lock);
        for (int i = 0; i < 10; i++)
        {
            std::cout << "mutex_lock_guard " << i << std::endl;
        }
    }
}
/**************
 * join与detach的区别
 * join阻塞等待线程执行完毕
 * detach守护进程放到后台运行
 * join与detach只能二选一，后面也不能互相调用
 * 可以使用joinable()函数判断一个线程对象能否调用join()。
 * *****************/
int main(int argc, char *argv[])
{
    test();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    //匿名函数构造
    std::thread t2([](std::string m)
                   { std::cout << m << std::endl; },
                   "world");
    t2.join();
    //竞态条件，t3 t4是线程安全的，但组合起来却不是
    std::thread t3(shared_mutex);
    std::thread t4(mutex_lock_guard);

    for (int i = 0; i < 10; i++)
    {
        std::cout << "main " << i << std::endl;
    }
    t3.join();
    t4.join();
    return 0;
}

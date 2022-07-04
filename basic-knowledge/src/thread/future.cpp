/**
 * @file future.cpp
 * @author lsl
 * @brief 多线程 future 异步任务
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <future>
#include <thread>
#include <iostream>
void promise_f(std::future<int> &f)
{
    //获取共享状态的值
    int x = f.get();
    std::cout << "获取共享状态： " << x << std::endl;
}
int task_f(int a, int b)
{
    std::cout << "packaged_task包装异步任务" << std::endl;
    return a + b;
}
int main(int argc, char *argv[])
{
    //promise可以保存共享状态
    std::promise<int> promise;
    //与future绑定
    std::future<int> future0 = promise.get_future();
    //thread 执行 future
    std::thread t1(promise_f, std::ref(future0));
    //promise设置值
    promise.set_value(10);
    t1.join();
    //----------------------------------------------------------------
    //packaged_task包装异步任务
    std::packaged_task<int(int, int)> packaged_task(task_f);
    //绑定future，可以返回结果
    std::future<int> future1 = packaged_task.get_future();
    //thread执行异步包装任务，返回值在future上，共享状态
    std::thread t2(std::move(packaged_task), 1, 1);
    std::cout << future1.get() << std::endl;
    t2.join();

    return 0;
}

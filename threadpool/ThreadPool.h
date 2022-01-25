/**
 * @file ThreadPool.h
 * @author lsl 
 * @brief 线程池，维护一个任务队列，thread拿到task执行任务
 * @version 0.1
 * @date 2022-01-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef __THREADPOOL__
#define __THREADPOOL__
#include "./SafeQueue.h"
#include <future>
#include <functional>
#include <condition_variable>
class ThreadPool
{
private:
    //任务队列，任务统一为void函数
    SafeQueue<std::function<void()>> task_queue;
    //线程池，条件变量，有任务时唤醒线程
    std::condition_variable condition;

    /**
     * @brief 工作线程 
    */
    class WorkerThread
    {
    private:
        int id;           //工作id
        ThreadPool *pool; //线程池
    public:
    };

public:
    ThreadPool(/* args */);
    ~ThreadPool();

    /**
     * @brief 提交一个任务到任务队列中
     * 
     * @tparam F future
     * @tparam Args 可变参数模板
     * @return auto 尾置类型推导
     */
    template <typename F, typename... Args>
    auto submit(F &&f, Args &&...args) -> std::future<decltype(f(args...))>
    {
        std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...);

        //任务指针，使用智能指针
        auto task_ptr = std::make_unique<std::packaged_task<decltype(f(args...))()>>(func);

        //将packaged_task包装成一个void函数，lambda函数
        std::function<void()> wrapper_func = [task_ptr]()
        {
            (*task_ptr)();
        };

        //提交任务，将任务提交至队列
        task_queue.push_back(wrapper_func);

        //通知线程有任务
        condition.notify_one();

        //返回future，异步执行，通过future获取结果
        return task_ptr->get_future();
    }
};

ThreadPool::ThreadPool(/* args */)
{
}

ThreadPool::~ThreadPool()
{
}

#endif
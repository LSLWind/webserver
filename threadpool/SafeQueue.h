#ifndef __SAFE_QUEUE___
#define __SAFE_QUEUE___

#include <queue>
#include <mutex>
/**
 * @brief 线程安全队列
 * 
 */

template <typename T>
class SafeQueue
{

private:
    std::queue<T> queue; //队列
    std::mutex mutex;    //维护一把锁
public:
    SafeQueue();
    ~SafeQueue();

    /**
     * 
     * @brief 重写一些函数，使用锁保持互斥
     **/
    bool empty()
    {
        std::unique_lock<std::mutex> lock(mutex);
        return queue.empty();
    }
    int size()
    {
        std::unique_lock<std::mutex> lock(mutex);
        return queue.size();
    }
    /**
     * @brief 入队
     * 
     * @param t 
     */
    void push_back(T &t)
    {
        std::unique_lock<std::mutex> lock(mutex);
        queue.emplace(t); //调用T的构造函数并加入队列
    }
    /**
     * @brief 出队
     * 
     * @param t 队列首部元素赋值给t
     * @return true 
     * @return false 
     */
    bool dequeue(T &t)
    {
        std::unique_lock<std::mutex> lock(mutex);
        if (queue.empty())
        {
            return false;
        }
        t = std::move(queue.front());
        queue.pop();
        return true;
    }
};

#endif
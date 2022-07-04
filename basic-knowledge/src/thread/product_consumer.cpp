/**
 * 
 * 生产者消费者模型
 * 条件变量
 **/
#include <iostream>
#include <thread>
#include <deque>
#include <mutex>
#include <condition_variable>

std::deque<int> q;
std::mutex mu;
std::condition_variable condition;
const static int MAX_SIZE = 10;
/**
 * @brief 生产者
 * 
 */
void product()
{
    int size = 0;
    while (size < MAX_SIZE)
    {
        //生产者
        std::unique_lock<std::mutex> lock(mu);
        q.push_back(size);
        lock.unlock();
        condition.notify_one(); //条件变量，通知线程
        std::this_thread::sleep_for(std::chrono::seconds(1));
        size++;
    }
}
/**
 * @brief 消费者
 * 
 */
void consumer()
{
    int data = 0;
    while (data < MAX_SIZE)
    {
        std::unique_lock<std::mutex> lock(mu);
        while (q.empty())
        {
            condition.wait(lock); //lock-mu 等待被唤醒
        }
        data = q.front();
        q.pop_front();
        lock.unlock();
        std::cout << data << std::endl;
    }
}
int main(int argc, char **argv)
{
    std::thread t1(product);
    std::thread t2(consumer);
    t1.join();
    t2.join();
    return 0;
}
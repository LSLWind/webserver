cmake_minimum_required(VERSION 3.20)
project(basic-knowledge)

set(CMAKE_CXX_STANDARD 11)

# 全局日志框架
INCLUDE_DIRECTORIES(../include/third_lig/spdlog)

# 头文件路径
INCLUDE_DIRECTORIES(include/socket)

# 查找src下的所有cpp文件，然后将结果存进指定变量名(这里是DIR_SRCS)
AUX_SOURCE_DIRECTORY(src/socket SOCKET_SRCS)

add_executable()

# add_executable(test learn/src/test.cpp)

# add_executable(lslserver main.cpp )
# add_executable(simple_server learn/src/simple_server.cpp)
# add_executable(client learn/src/client.cpp)
# #learn
# # select poll epll
# add_executable(select_server learn/src/io_function/select_server.cpp)
# add_executable(poll_server learn/src/io_function/poll_server.cpp)
# add_executable(epoll_server learn/src/io_function/epoll_server.cpp)
# # c++11 thread mutex
# add_executable(thread learn/src/thread/thread.cpp)
# #链接到动态库pthread
# set(THREADS_PREFER_PTHREAD_FLAG ON)
# find_package(Threads REQUIRED)
# target_link_libraries(thread PUBLIC Threads::Threads)
# # 条件变量，condition_variable
# add_executable(product_consumer learn/src/thread/product_consumer.cpp)
# target_link_libraries(product_consumer PUBLIC Threads::Threads)
# # future 异步任务
# add_executable(future learn/src/thread/future.cpp)
# target_link_libraries(future PUBLIC Threads::Threads)
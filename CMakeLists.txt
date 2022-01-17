cmake_minimum_required(VERSION 3.20)
project(webserver)

set(CMAKE_CXX_STANDARD 11)

# 头文件路径
INCLUDE_DIRECTORIES(include)

# 查找src下的所有cpp文件，然后将结果存进指定变量名(这里是DIR_SRCS)
AUX_SOURCE_DIRECTORY(src DIR_SRCS)


add_executable(test learn/src/test.cpp)

add_executable(lslserver main.cpp )
add_executable(simple_server learn/src/simple_server.cpp)
add_executable(simple_client learn/src/simple_client.cpp)

add_executable(select_server learn/src/io_function/select_server.cpp)
add_executable(select_client learn/src/io_function/select_client.cpp)





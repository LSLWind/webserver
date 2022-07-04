/*
 * @Author: lsl
 * @Date: 2022-07-04 20:37:05
 * @Last Modified by: lsl
 * @Last Modified time: 2022-07-04 21:11:22
 */
#ifndef SIMPLE_SERVER_H
#define SIMPLE_SERVER_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <csignal>
#include <unistd.h>
#include <stdlib.h>
#include <assert.h>
#include "string.h"
#include "iostream"

class SimpleServer
{
private:
    bool InitSocket(); // 初始化Socket

    int port_;         // 端口
    int listen_len_;   //监听长度
    bool is_shutdown_; // 是否关闭
    const char* kIp_;

public:
    SimpleServer(int port, int listen_len);
    ~SimpleServer();
};

#endif SIMPLE_SERVER_H
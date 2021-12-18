//
// Created by lsl on 2021/12/7.
//
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<csignal>
#include<unistd.h>
#include<stdlib.h>
#include<assert.h>
#include "string.h"
#include "iostream"

using std::cout;

static bool stop = false;

static void handle_term(int sig) {
    stop = true;
}

const int BUF_SIZE = 1024;

int main(int argc, char *argv[]) {
    std::cout << "lsl";
    signal(SIGTERM, handle_term);

    const char *ip = "192.168.187.128";//ip
    int port = atoi("1234");//端口
    int backlog = 5;//监听队列长度
    //创建socket，ipv4，字符流（tcp）
    int sock = socket(PF_INET, SOCK_STREAM, 0);
    assert(sock > 0);
    /*创建一个IPv4 socket地址，主要设置ip和端口信息*/
    struct sockaddr_in address;
    bzero(&address, sizeof(address));//清空地址
    address.sin_family = AF_INET;//ipv4
    inet_pton(AF_INET, ip, &address.sin_addr);//ip转换
    address.sin_port = htons(port);//端口
    //命名Socket / 绑定Socket
    int ret = bind(sock, (struct sockaddr *) &address, sizeof(address));
    assert(ret != -1);
    //监听Socket
    ret = listen(sock, backlog);
    assert(ret != -1);
    //客户端tcp连接描述，等待符合格式的连接
    struct sockaddr_in client;
    socklen_t client_addrlength = sizeof(client);
    //接受客户端连接
    while (true) {
        int connfd = accept(sock, (struct sockaddr *) &client, &client_addrlength);
        if (connfd < 0) {
            std::cout << "客户端连接错误，错误码：" << connfd;
        } else {
            //接收客户端信息
            char remote[INET_ADDRSTRLEN];
            std::cout << "客户端连接成功：" << inet_ntop(AF_INET, &client.sin_addr, remote, INET_ADDRSTRLEN) << "，端口："
                      << ntohs(client.sin_port) << std::endl;
//            struct sockaddr clientInfo;
//            int clientInfoFd = getpeername(connfd, &clientInfo, &client_addrlength);
            char buffer[BUF_SIZE];
            memset(buffer, '\0', BUF_SIZE);
            int res = recv(connfd, buffer, BUF_SIZE - 1, 0);
            std::cout << "接受信息：" << res << "，" << buffer << std::endl;
            close(connfd);
            if (res == -1)break;
        }
    }

    //关闭Socket
    close(sock);

    return 0;


}
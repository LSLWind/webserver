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

static bool stop= false;
static void handle_term(int sig){
    stop= true;
}

int main(int argc, char *argv[]) {
    std::cout<<"lsl";
    signal(SIGTERM,handle_term);

    const char *ip = argv[1];//ip
    int port = atoi(argv[2]);//端口
    int backlog = atoi(argv[3]);//监听队列长度
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
    assert(ret!=-1);
    //监听Socket
    ret= listen(sock,backlog);
    assert(ret!=-1);
    while (!stop){
        sleep(1);
    }
    //关闭Socket
    close(sock);

    return 0;


}
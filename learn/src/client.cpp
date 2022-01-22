//
// Created by lsl on 2021/12/13.
//

#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<csignal>
#include<unistd.h>
#include<netdb.h>
#include<stdlib.h>
#include<assert.h>
#include "string.h"
#include "iostream"

int main() {
    const char *ip = "192.168.187.128";
    int port = 1234;

    //服务器tcp连接描述
    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &server_address.sin_addr);
    server_address.sin_port = htons(port);
    //建立socket
    int sockfd = socket(PF_INET, SOCK_STREAM, 0);
    assert(sockfd > 0);
    //连接服务器
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        std::cout << "连接服务器失败" << std::endl;
    } else {
        std::cout << "连接服务器成功" << std::endl;
        //发送数据
        send(sockfd, "helloworld!", 12, 0);
        std::cout << "发送数据成功" << std::endl;
    }
    //关闭socket
    close(sockfd);

    //获取目标服务器上的时间服务
    /*获取目标主机地址信息*/
    struct hostent *hostInfo = gethostbyname("localhost");
    assert(hostInfo);
    /*获取daytime服务信息*/
    struct servent *servInfo = getservbyname("daytime", "tcp");
    assert(servInfo);
    std::cout << "daytime服务端口：" << servInfo->s_port << std::endl;
    //切换服务ip与端口，注意地址列表是一个二维指针，取第一个地址

    server_address.sin_addr = (*(struct in_addr *) *hostInfo->h_addr_list);
    std::cout << inet_ntoa(server_address.sin_addr) << std::endl;
    server_address.sin_port = servInfo->s_port;
    //建立socket
    sockfd = socket(PF_INET, SOCK_STREAM, 0);
    assert(sockfd > 0);
    //连接daytime服务，需要在ubuntu中启动
    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        std::cout << "连接服务失败" << std::endl;
    } else {
        std::cout << "连接服务成功" << std::endl;
        //接受数据
        char buffer[128];
        int result = read(sockfd, buffer, sizeof(buffer));
        assert(result > 0);
        buffer[result] = '\0';
        std::cout << "接收数据：" << buffer << std::endl;
    }
    //关闭socket
    close(sockfd);

    return 0;
}
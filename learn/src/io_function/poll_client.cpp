#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <csignal>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <assert.h>
#include "string.h"
#include "iostream"

int main()
{
    const char *ip = "127.0.0.1";
    int port = 8899;

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
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        std::cout << "连接服务器失败" << std::endl;
    }
    else
    {
        std::cout << "连接服务器成功" << std::endl;
        //发送数据
        sleep(5);
        send(sockfd, "hello select!", 12, 0);
        std::cout << "发送数据成功" << std::endl;
    }
    //关闭socket
    close(sockfd);

    return 0;
}
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <string>


const unsigned short PORT = 10086;
const uint32_t MAX_BUFF_SIZE = 4096;

using namespace std;

int main(int argc, char** argv){
    int s_sock;
    int c_sock;
    struct sockaddr_in addr;
    int opt = 1;
    int addr_len = sizeof(addr);

    char buff[MAX_BUFF_SIZE] = {0};

    s_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(s_sock == 0){
        cout<<"sock init error!"<<endl;
        return -1;
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = "45.32.243.237";
    addr.sin_port = htons(PORT);

    if(bind(s_sock, (struct sockaddr*)&addr, sizeof(addr)) < 0){
        cout<<"bind error"<<endl;
        return -2;
    }
    if(listen(s_sock, 3) < 0){
        cout<<"listen error"<<endl;
        return -3;
    }
    c_sock = accept(s_sock, (struct sockaddr*)&addr, (socklen_t*)&addr_len);
    if(c_sock)

}

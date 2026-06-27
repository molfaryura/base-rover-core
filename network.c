// TCP server
#include "config.h"
#include <netinet/in.h>
#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

int tcp_server(){

    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock == -1) {
        perror("ERROR initializing TCP server socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_family = AF_INET;

    int binded_sock = bind(server_sock, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(binded_sock == -1){
        perror("ERROR during binding socket");
        return 1;
    }

    int listen_sock = listen(server_sock, 3);
    if(listen_sock == -1){
        perror("ERROR during listening");
        return 1;
    }

    int client_sock = accept(server_sock, (struct sockaddr*)&server_addr,
                            (socklen_t*)sizeof(server_addr));
    if(client_sock == -1){
        perror("ERROR during accepting");
    }

    char buffer[1024];

    while (1) {
        int received_butes = recv(client_sock, buffer, sizeof(buffer) - 1, 0);
        if (received_butes == -1) {
            perror("Error during receiving message");
        }

        buffer[received_butes] = '\0';
    }

    close(server_sock);
    close(client_sock);

}

int main(){
    tcp_server();
}

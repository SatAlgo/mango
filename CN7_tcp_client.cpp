#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

int main() {
    int client_socket;
    sockaddr_in server_address;

    client_socket = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(5555);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(client_socket, (struct sockaddr *)&server_address, sizeof(server_address))

    const char* message = "Hello, TCP Server!";
    send(client_socket, message, strlen(message), 0);

    char buffer[1024] = {0};
    read(client_socket, buffer, sizeof(buffer));

    cout << "Server replied: " << buffer << endl;

    close(client_socket);
    return 0;
}

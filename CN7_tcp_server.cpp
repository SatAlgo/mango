#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

int main() {
    int server_socket, client_socket;
    sockaddr_in server_address, client_address;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(5555);
    server_address.sin_addr.s_addr = INADDR_ANY;

    ::bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address))

    listen(server_socket, 1)

    cout << "Server listening on port 5555..." << endl;

    socklen_t client_length = sizeof(client_address);
    client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_length);

    char buffer[1024] = {0};
    read(client_socket, buffer, sizeof(buffer));

    cout << "Received: " << buffer << endl;

    send(client_socket, buffer, strlen(buffer), 0);

    close(client_socket);
    close(server_socket);

    return 0;
}

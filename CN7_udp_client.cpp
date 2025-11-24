#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    const char *msg = "Hello, UDP Server!";
    sendto(sock, msg, strlen(msg), 0, (struct sockaddr*)&server_addr, sizeof(server_addr));

    char buf[1024];
    sockaddr_in from_addr;
    socklen_t from_len = sizeof(from_addr);

    int n = recvfrom(sock, buf, sizeof(buf) - 1, 0, (struct sockaddr*)&from_addr, &from_len);
    buf[n] = '\0';

    cout << "Server replied: " << buf << endl;

    close(sock);
    return 0;
}

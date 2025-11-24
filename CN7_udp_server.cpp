#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    ::bind(sock, (struct sockaddr*)&addr, sizeof(addr));

    cout << "UDP server listening on port 8080..." << endl;

    char buf[1024];
    socklen_t addrlen = sizeof(addr);

    int n = recvfrom(sock, buf, sizeof(buf) - 1, 0, (struct sockaddr*)&addr, &addrlen);
    buf[n] = '\0';

    cout << "Received: " << buf << endl;

    sendto(sock, buf, n, 0, (struct sockaddr*)&addr, addrlen);

    close(sock);
    return 0;
}

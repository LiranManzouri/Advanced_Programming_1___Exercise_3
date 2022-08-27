//#include "Server.h"
#include "ServerFront.h"
#include "../CLI.h"
#include "../CreateClassifiedFiles.h"
#include <iostream>
#include <cstring>
#include <thread>
#include <sys/socket.h>
#include <netinet/in.h>

using namespace std;

void func() {
    cout << "ok" << endl;
}

/*
 * Main for the server, to communicate with the clients.
 * The server gets a path to unclassified flowers from a client and
 * classify them, after that, the server sends it back to the client.
 */
int main(int argc, char const *argv[]) {
    // Responsible for the communication.
//    ServerFront front;

    // Port to use.
    const int server_port = 5555;
    // Creates the socket and checks it created successfully.
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        cout << "Error creating socket in SERVER" << endl;
        exit(1);
    }
    // Initializes the info about the socket.
    struct sockaddr_in sin{};
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    // Binding the socket and checks it bind successfully.
    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        cout << "Error binding socket in SERVER" << endl;
        exit(1);
    }

    // Runs until it being said to stop.
//    bool listening = true;
    while(true) {
        // Waits for a client.
        if (listen(sock, 3) < 0) {
            cout << "Error listening to a socket in SERVER" << endl;
            exit(1);
        }
        // Accepts the client and checks it went successfully.
        struct sockaddr_in client_sin{};
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr *) &client_sin, &addr_len);
        if (client_sock < 0) {
            cout << "Error accepting client in SERVER" << endl;
            exit(1);
        }
        CLI cli(client_sock);
        cli.start();
    }
}

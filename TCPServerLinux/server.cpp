// Marlon R.

// Implementation of a TCP socket in C++ and Linux

// To connect to server after running the program, open a new Terminal window
// and use the command: $ telnet localhost 54000

// References:
// - https://www.cs.dartmouth.edu/~campbell/cs60/socketprogramming.html
// - https://man7.org/linux/man-pages/man2/socket.2.html
// - http://manpages.ubuntu.com/manpages/xenial/man2/socket.2.html
// - Sloan Kely. Youtube

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

int main()
{
    // Try to create a socket and return if it is not possible

    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if (listening == -1)
    {
        cerr << "Not able to create a socket! Quitting" << endl;
        return -1;
    }

    // Bind the IP address and port to the socket
    // Bind to any available IP address

    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(54000);
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);

    bind(listening, (sockaddr *)&hint, sizeof(hint));

    // Mark the socket as passive (will be used to accept incoming connection requests)

    listen(listening, SOMAXCONN);

    // Wait for a connection

    sockaddr_in client;
    socklen_t clientSize = sizeof(client);

    int clientSocket = accept(listening, (sockaddr *)&client, &clientSize);

    char host[NI_MAXHOST];    // Client's remote name
    char service[NI_MAXSERV]; // Service or port where the client is connect to

    memset(host, 0, NI_MAXHOST);
    memset(service, 0, NI_MAXSERV);

    // If possible get the name of client and display it

    if (getnameinfo((sockaddr *)&client, sizeof(client), host, NI_MAXHOST, service, NI_MAXSERV, 0) == 0)
    {
        cout << host << " connected on port " << service << endl;
    }
    else
    {
        inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
        cout << host << " connected on port " << ntohs(client.sin_port) << endl;
    }

    // Close the listening socket

    close(listening);

    // We receive into this buffer here

    char buf[4096];

    // Keep looping, accept message annd send back to client
    // until and error occurs or client disconnects

    while (true)
    {
        // Clear buffer from whatever was there before

        memset(buf, 0, 4096);

        // Wait for client to send data

        int bytesReceived = recv(clientSocket, buf, 4096, 0);

        if (bytesReceived == -1)
        {
            cerr << "Error in recv(). Quitting" << endl;
            break;
        }

        if (bytesReceived == 0)
        {
            cout << "Client disconnected " << endl;
            break;
        }

        // Show client's message on Server

        cout << string(buf, 0, bytesReceived) << endl;

        // Send message back to client

        send(clientSocket, buf, bytesReceived + 1, 0);
    }

    // Close the socket

    close(clientSocket);

    return 0;
}

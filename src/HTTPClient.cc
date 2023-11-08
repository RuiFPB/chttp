#include "../include/HTTPClient.h"

#include <string>
#include <iostream>
#include "../include/HTTPRequest.h"

// Networking libraries
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>


HTTPClient::HTTPClient(std::string address, int port) : address(address), port(port) {};
HTTPClient::HTTPClient(std::string address) : address(address), port(80) {};
HTTPClient::HTTPClient() : address("localhost"), port(80) {};

HTTPResponse HTTPClient::sendRequest(HTTPRequest request) {
    // Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    // Create sockaddr_in struct
    struct sockaddr_in server;
    // Clear the struct
    memset(&server, 0, sizeof(server));
    // Set the family to IPv4
    server.sin_family = AF_INET;
    // Set the address
    server.sin_addr.s_addr = inet_addr(address.c_str());
    // Set the port
    server.sin_port = htons(port);

    // Connect to the server
    if(connect(sock, (struct sockaddr *)&server, sizeof(server))) {
        std::cout << "Failed to connect to server" << std::endl;
        return HTTPResponse();
    }

    // Send the request
    send(sock, request.toString().c_str(), request.toString().length(), 0);

    // Receive the response
    std::string response;
    char buffer[1024] = {0};
    int bytes_read = 0;
    while ((bytes_read = read(sock, buffer, 1024)) > 0) {
        response.append(buffer, bytes_read);
    }

    // Close the socket
    close(sock);

    // Print the response to console for now
    // TODO: Use HTTPResponse class
    std::cout << response << std::endl;

    return HTTPResponse();
}
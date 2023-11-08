#pragma once

#include "HTTPRequest.h"
#include <string>

// This is temporary, Will be replaced with a proper HTTPResponse class
// TODO: Create HTTPResponse class
struct HTTPResponse {
    int statusCode;
    std::string statusMessage;
    std::string body;
};

class HTTPClient {
private: 
    std::string address;
    int port;
public:
    HTTPClient(std::string address, int port);
    HTTPClient(std::string address);
    HTTPClient();

    HTTPResponse sendRequest(HTTPRequest request);
};
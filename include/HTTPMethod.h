#pragma once

#include <string>

// Class: HTTPMethod
// This class represents an HTTP method.

class HTTPMethod {
    
private:
    std::string method;

public:
    HTTPMethod();
    HTTPMethod(std::string method);
    std::string getMethod();
    bool operator==(const HTTPMethod& other) const;
    bool operator!=(const HTTPMethod& other) const;
    static const HTTPMethod GET;
    static const HTTPMethod POST;
    static const HTTPMethod PUT;
    static const HTTPMethod DELETE;
    static const HTTPMethod HEAD;
    static const HTTPMethod OPTIONS;
    static const HTTPMethod TRACE;
    static const HTTPMethod CONNECT;
    static const HTTPMethod PATCH;
};
#include "../include/HTTPMethod.h"
#include <string>

// Class: HTTPMethod
// This class represents an HTTP method.

HTTPMethod::HTTPMethod() {
    this->method = "GET";
}

HTTPMethod::HTTPMethod(std::string method) {
    this->method = method;
}

std::string HTTPMethod::getMethod() {
    return this->method;
}

bool HTTPMethod::operator==(const HTTPMethod& other) const {
    return this->method.compare(other.method) == 0;
}

bool HTTPMethod::operator!=(const HTTPMethod& other) const {
    return this->method.compare(other.method) != 0;
}

const HTTPMethod HTTPMethod::GET = HTTPMethod("GET");
const HTTPMethod HTTPMethod::POST = HTTPMethod("POST");
const HTTPMethod HTTPMethod::PUT = HTTPMethod("PUT");
const HTTPMethod HTTPMethod::DELETE = HTTPMethod("DELETE");
const HTTPMethod HTTPMethod::HEAD = HTTPMethod("HEAD");
const HTTPMethod HTTPMethod::OPTIONS = HTTPMethod("OPTIONS");
const HTTPMethod HTTPMethod::TRACE = HTTPMethod("TRACE");
const HTTPMethod HTTPMethod::CONNECT = HTTPMethod("CONNECT");
const HTTPMethod HTTPMethod::PATCH = HTTPMethod("PATCH");


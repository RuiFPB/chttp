#include "../include/HTTPRequest.h"

#include <string>
#include <map>
#include "../include/HTTPMethod.h"

HTTPRequest::HTTPRequest() : path("/") {} ;
HTTPRequest::HTTPRequest(HTTPMethod method) : method(method), path("/") {};
HTTPRequest::HTTPRequest(HTTPMethod method, std::string path) : method(method), path(path) {};
HTTPRequest::HTTPRequest(HTTPMethod method, std::string path, std::map<std::string, std::string> headers) : method(method), path(path), headers(headers) {};
HTTPRequest::HTTPRequest(HTTPMethod method, std::string path, std::map<std::string, std::string> headers, std::string body) : method(method), path(path), headers(headers), body(body) {};

const HTTPMethod HTTPRequest::getMethod() {
    return method;
}

const std::string HTTPRequest::getPath() {
    return path;
}

const std::map<std::string, std::string> HTTPRequest::getHeaders() {
    return headers;
}

const std::string HTTPRequest::getBody() {
    return body;
}

const std::string HTTPRequest::getHeaderValue(std::string key) {
    return headers[key];
}

HTTPRequest HTTPRequest::setMethod(HTTPMethod method) {
    this->method = method;
    return *this;
}

HTTPRequest HTTPRequest::setPath(std::string path) {
    this->path = path;
    return *this;
}

HTTPRequest HTTPRequest::setHeaders(std::map<std::string, std::string> headers) {
    this->headers = headers;
    return *this;
}

HTTPRequest HTTPRequest::setBody(std::string body) {
    this->body = body;
    return *this;
}

HTTPRequest HTTPRequest::addHeader(std::string key, std::string value) {
    this->headers[key] = value;
    return *this;
}

std::string HTTPRequest::toString() {
    std::string request = "";
    request += method.getMethod() + " " + path + " HTTP/1.1\r\n";
    for (auto const& header : headers) {
        request += header.first + ": " + header.second + "\r\n";
    }
    request += "\r\n";
    request += body;
    return request;
}
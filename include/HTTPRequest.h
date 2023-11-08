#pragma once

#include <string>
#include <map>
#include "HTTPMethod.h"

class HTTPRequest {
private:
    HTTPMethod method;
    std::string path;
    std::map<std::string, std::string> headers;
    std::string body;

public:
    // Empty default constructor
    HTTPRequest();
    HTTPRequest(HTTPMethod method);
    HTTPRequest(HTTPMethod method, std::string path);
    HTTPRequest(HTTPMethod method, std::string path, std::map<std::string, std::string> headers);
    HTTPRequest(HTTPMethod method, std::string path, std::map<std::string, std::string> headers, std::string body);

    const HTTPMethod getMethod();
    const std::string getPath();
    const std::map<std::string, std::string> getHeaders();
    const std::string getBody();
    const std::string getHeaderValue(std::string key);

    HTTPRequest setMethod(HTTPMethod method);
    HTTPRequest setPath(std::string path);
    HTTPRequest setHeaders(std::map<std::string, std::string> headers);
    HTTPRequest setBody(std::string body);

    HTTPRequest addHeader(std::string key, std::string value);

    std::string toString();
};
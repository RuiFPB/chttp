#include "../include/HTTPMethod.h"
#include "../include/HTTPRequest.h"
#include "../include/HTTPClient.h"
#include <assert.h>

void testHTTPMethod();
void testHTTPRequest();
void testHTTPClient();

int main() {
    testHTTPMethod();
    testHTTPRequest();
    testHTTPClient();
}

void testHTTPMethod() {
    HTTPMethod test = HTTPMethod("TEST");

    assert(test.getMethod() == "TEST");
    assert(test == HTTPMethod("TEST"));
    assert(test != HTTPMethod("GET"));

    assert(HTTPMethod::GET == HTTPMethod());
    assert(HTTPMethod::GET == HTTPMethod("GET"));
    assert(HTTPMethod::POST == HTTPMethod("POST"));
    assert(HTTPMethod::PUT == HTTPMethod("PUT"));
    assert(HTTPMethod::DELETE == HTTPMethod("DELETE"));
    assert(HTTPMethod::HEAD == HTTPMethod("HEAD"));
    assert(HTTPMethod::OPTIONS == HTTPMethod("OPTIONS"));
    assert(HTTPMethod::TRACE == HTTPMethod("TRACE"));
    assert(HTTPMethod::CONNECT == HTTPMethod("CONNECT"));
    assert(HTTPMethod::PATCH == HTTPMethod("PATCH"));
}

void testHTTPRequest() {
    HTTPRequest req = HTTPRequest();
    assert(req.getMethod() == HTTPMethod::GET);
    assert(req.getPath().compare("/") == 0);

    std::map<std::string, std::string> headers{{"Content-Type", "application/json"}};

    req = HTTPRequest(HTTPMethod::PUT, "/", headers, "TEST BODY");
    assert(((std::map<std::string, std::string>)req.getHeaders())["Content-Type"].compare("application/json") == 0);
    assert(req.getBody().compare("TEST BODY") == 0);

    assert(req.setBody("NEW TEST").getBody().compare("NEW TEST") == 0);
    assert(req.addHeader("Connection", "keep-alive").getHeaderValue("Connection").compare("keep-alive") == 0);

    req = HTTPRequest(HTTPMethod::GET, "/test", headers, "TEST BODY");
    assert(req.toString().compare("GET /test HTTP/1.1\r\nContent-Type: application/json\r\n\r\nTEST BODY") == 0);
}

void testHTTPClient() {
    HTTPClient client = HTTPClient("127.0.0.1", 8080);

    HTTPRequest req = HTTPRequest(HTTPMethod::GET, "/test/testFile", {{"Content-Type", "application/json"}}, "TEST BODY");

    HTTPResponse res = client.sendRequest(req);
}
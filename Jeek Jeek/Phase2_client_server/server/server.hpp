#ifndef __SERVER__
#define __SERVER__
#include "../utils/include.hpp"
#include "../utils/request.hpp"
#include "../utils/response.hpp"
#include "route.hpp"
#include <exception>
#include <string>
#include <vector>

class RequestHandler {
public:
  virtual Response *callback(Request *req);
};

class ShowFile : public RequestHandler {
  string filePath;
  string fileType;

public:
  ShowFile(string filePath, string fileType);
  Response *callback(Request *req);
};

class ShowPage : public ShowFile {

public:
  ShowPage(string _filePath);
};

class ShowImage : public ShowFile {

public:
  ShowImage(string _filePath);
};

class Server {
public:
  Server(int port = 5000, std::string notFoundErrPage = "static/404.html");
  void run();
  void get(std::string path, RequestHandler *handler);
  void post(std::string path, RequestHandler *handler);
  class Exception : public std::exception {

  public:
    Exception() {}
    Exception(const char *pStr) { pMessage = pStr; }
    const char *getMessage();

  private:
    const char *pMessage;
  };

private:
  int sc;
  int port;
  std::vector<Route *> routes;
  std::string notFoundErrPage;
};
#endif

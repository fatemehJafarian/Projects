#include "interface.hpp"
#include "server.hpp"
#include <cstdlib> // for rand and srand
#include <ctime>   // for time
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
  srand(time(NULL)); // for rand
  try 
  {
    Interface interface(argc > 1 ? atoi(argv[1]) : 5000);
    interface.run();
  } 
  catch (Server::Exception e) 
  {
    cout << e.getMessage() << endl;
  }
}

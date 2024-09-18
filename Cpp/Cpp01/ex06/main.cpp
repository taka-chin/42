#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {
  Harl harl;
  if (argc != 2) {
    std::cout << "Invalid argument" << std::endl;
    return (0);
  }
  harl.complain(argv[1]);
}

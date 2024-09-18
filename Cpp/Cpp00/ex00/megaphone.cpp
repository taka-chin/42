#include <iostream>
#include <string>

int main(int argc, char **argv) {
  int i;

  i = 1;
  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return (0);
  }
  while (i < argc) {
    std::string message = argv[i];
    std::transform(message.begin(), message.end(), message.begin(), toupper);
    std::cout << message;
    i++;
  }
  std::cout << "\n";
  return (0);
}

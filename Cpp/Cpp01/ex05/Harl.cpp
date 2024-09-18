#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) { std::cout << "DEBUG" << std::endl; };

void Harl::info(void) { std::cout << "INFO" << std::endl; };

void Harl::warning(void) { std::cout << "WARNING" << std::endl; };

void Harl::error(void) { std::cout << "ERROR" << std::endl; };

void Harl::complain(std::string level) {
  Level levels[] = {{"DEBUG", &Harl::debug},
                    {"INFO", &Harl::info},
                    {"WARNING", &Harl::warning},
                    {"ERROR", &Harl::error}};
  for (int i = 0; i < 4; i++) {
    if (level == levels[i].level) {
      (this->*levels[i].f)();
      return;
    }
  }
  std::cout << "[ Probably complaining about insignificant problems ] "
            << std::endl;
}

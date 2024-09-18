#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) {
  std::cout << "[ DEBUG ]" << std::endl;
  std::cout << "here is debug message" << std::endl;
};

void Harl::info(void) {
  std::cout << "[ INFO ]" << std::endl;
  std::cout << "here is info message" << std::endl;
};

void Harl::warning(void) {
  std::cout << "[ WARNING ]" << std::endl;
  std::cout << "here is warning message" << std::endl;
};

void Harl::error(void) {
  std::cout << "[ ERROR ]" << std::endl;
  std::cout << "here is error message" << std::endl;
};

void Harl::complain(std::string level) {
  Level levels[] = {{"DEBUG", &Harl::debug, 1},
                    {"INFO", &Harl::info, 2},
                    {"WARNING", &Harl::warning, 3},
                    {"ERROR", &Harl::error, 4}};

  unsigned index = 0;
  for (unsigned int i = 0; i < 4; i++) {
    if (level == levels[i].level)
      index = levels[i].index;
  }
  switch (index) {
  case 1:
    (this->*levels[0].f)();
  case 2:
    (this->*levels[1].f)();
  case 3:
    (this->*levels[2].f)();
  case 4:
    (this->*levels[3].f)();
    break;
  default:
    std::cout << "[ Probably complaining about insignificant problems ] "
              << std::endl;
    break;
  }
}

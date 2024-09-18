#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	std::cout << "constructor called"<<std::endl;
}

const std::string &Zombie::getName() { return name_; }

void Zombie::setName(std::string name) { name_ = name; }

void Zombie::announce(void) {
  std::string name;
  name = getName();
  std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

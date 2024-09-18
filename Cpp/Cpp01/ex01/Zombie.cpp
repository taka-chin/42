#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	std::cout << "consructor called" <<std::endl;
}
const std::string &Zombie::getName() { return name_; }

void Zombie::setName(std::string name) { name_ = name; }

void Zombie::announce(void) {
  std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

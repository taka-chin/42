#include "HumanA.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string name, Weapon &weapon)
    : name_(name), weapon_(weapon) {}

const std::string HumanA::getName() { return name_; }

void HumanA::setName(std::string name) { name_ = name; }

void HumanA::attack() {
  std::string type;
  std::string name;

  type = weapon_.getType();
  name = getName();
  std::cout << name << " attacks with their " << type << std::endl;
}

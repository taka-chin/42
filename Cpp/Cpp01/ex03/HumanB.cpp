#include "HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string name) : name_(name) {}

const std::string HumanB::getName() { return name_; }

void HumanB::setName(std::string name) { name_ = name; }

void HumanB::setWeapon(Weapon &weapon) { this->weapon_ = &weapon; }

void HumanB::attack() {
  std::string type;
  std::string name;

  type = weapon_->getType();
  name = getName();
  std::cout << name << " attacks with their " << type << std::endl;
}

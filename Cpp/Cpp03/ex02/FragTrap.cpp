#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
  std::cout << "FragTrap Default constructor called" << std::endl;
  HitPoints = 100;
  EnergyPoints = 100;
  AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  std::cout << "FragTrap Name constructor called" << std::endl;
  Name = name;
  HitPoints = 100;
  EnergyPoints = 100;
  AttackDamage = 30;
}

FragTrap::FragTrap(const FragTrap &f) : ClapTrap(f) {
  std::cout << "FragTrap Copy constructor called" << std::endl;
  *this = f;
}

FragTrap &FragTrap::operator=(const FragTrap &f) {
  std::cout << "FragTrap Copy assignment operator called" << std::endl;
  this->Name = f.Name;
  this->HitPoints = f.HitPoints;
  this->EnergyPoints = f.EnergyPoints;
  this->AttackDamage = f.AttackDamage;
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target) {
  std::cout << "FragTrap attck function called" << std::endl;
  if (EnergyPoints <= 0) {
    std::cout << "ClapTrap " << Name << " No Energy Points !!" << std::endl;
  } else if (HitPoints <= 0) {
    std::cout << "ClapTrap " << Name << " No Hit Points !!" << std::endl;
  } else {
    std::cout << "ClapTrap " << Name << " attacks " << target << ", causing "
              << AttackDamage << " points of damage!" << std::endl;
    this->EnergyPoints -= 1;
  }
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap highFivesGuys function called" << std::endl;
  std::cout << "High Five!" << std::endl;
}

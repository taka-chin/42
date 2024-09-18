#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
  std::cout << "ScavTrap Default constructor called" << std::endl;
  HitPoints = 100;
  EnergyPoints = 50;
  AttackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
  std::cout << "ScavTrap Name constructor called" << std::endl;
  Name = name;
  HitPoints = 100;
  EnergyPoints = 50;
  AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &f) : ClapTrap(f) {
  std::cout << "ScavTrap Copy constructor called" << std::endl;
  *this = f;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &f) {
  std::cout << "ScavTrap Copy assignment operator called" << std::endl;
  this->Name = f.Name;
  this->HitPoints = f.HitPoints;
  this->EnergyPoints = f.EnergyPoints;
  this->AttackDamage = f.AttackDamage;
  return *this;
}

ScavTrap::~ScavTrap() {
  std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string &target) {
  std::cout << "ScavTrap attck function called" << std::endl;
  if (EnergyPoints <= 0) {
    std::cout << "ScavTrap " << Name << " No Energy Points !!" << std::endl;
  } else if (HitPoints <= 0) {
    std::cout << "ScavTrap " << Name << " No Hit Points !!" << std::endl;
  } else {
    std::cout << "ScavTrap " << Name << " attacks " << target << ", causing "
              << AttackDamage << " points of damage!" << std::endl;
    this->EnergyPoints -= 1;
  }
}

void ScavTrap::guardGate() {
  std::cout << "ScavTrap guardGate function called" << std::endl;
  std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}

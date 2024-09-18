#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

ClapTrap::ClapTrap() : HitPoints(10), EnergyPoints(10), AttackDamage(0) {
  std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : Name(name), HitPoints(10), EnergyPoints(10), AttackDamage(0) {
  std::cout << "ClapTrap Name constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
  std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &f) {
  std::cout << "ClapTrap Copy constructor called" << std::endl;
  *this = f;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &f) {
  std::cout << "ClapTrap Copy assignment operator called" << std::endl;
  this->Name = f.Name;
  this->HitPoints = f.HitPoints;
  this->EnergyPoints = f.EnergyPoints;
  this->AttackDamage = f.AttackDamage;
  return *this;
}

void ClapTrap::attack(const std::string &target) {
  std::cout << "ClapTrap attck function called" << std::endl;
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

void ClapTrap::takeDamage(unsigned int amount) {
  std::cout << "ClapTrap takeDamage function called" << std::endl;
  std::cout << "ClapTrap " << Name << " " << amount << " Damage taked!"
            << std::endl;
  if (HitPoints <= amount) {
    this->HitPoints = 0;
    std::cout << Name << " is dead" << std::endl;
  } else
    this->HitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
  std::cout << "ClapTrap beRepaired function called" << std::endl;
  if (HitPoints <= 0) {
    std::cout << "ClapTrap " << Name << " No Hit Points !!" << std::endl;
    return;
  }
  if (EnergyPoints > 0) {
    std::cout << "ClapTrap " << Name << " " << amount << " Hitpoints Repaired!"
              << std::endl;
    if (std::numeric_limits<unsigned int>::max() - HitPoints < amount)
      this->HitPoints = std::numeric_limits<unsigned int>::max();
    else
      this->HitPoints += amount;
    this->EnergyPoints -= 1;
  } else {
    std::cout << "ClapTrap No Energy Points !!" << std::endl;
  }
}

unsigned int ClapTrap::getHitPoints() {
  std::cout << "ClapTrap getHitPoints function called" << std::endl;
  return this->HitPoints;
}

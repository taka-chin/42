#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {
public:
  ScavTrap();
  ScavTrap(std::string name);
  ~ScavTrap();
  ScavTrap(const ScavTrap &f);
  ScavTrap &operator=(const ScavTrap &f);
  void attack(const std::string &target);
  void guardGate();
};

#endif

#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap : public ClapTrap {
public:
  FragTrap();
  FragTrap(std::string name);
  ~FragTrap();
  FragTrap(const FragTrap &f);
  FragTrap &operator=(const FragTrap &f);
  void attack(const std::string &target);
  void highFivesGuys(void);
};

#endif

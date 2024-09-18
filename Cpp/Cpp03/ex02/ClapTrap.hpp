#ifndef CLAP_TRAP_HPP
#define CLAP_TRAP_HPP

#include <string>

class ClapTrap {
protected:
  std::string Name;
  unsigned int HitPoints;
  unsigned int EnergyPoints;
  unsigned int AttackDamage;

public:
  ClapTrap();
  ClapTrap(std::string name);
  ~ClapTrap();
  ClapTrap(const ClapTrap &f);
  ClapTrap &operator=(const ClapTrap &f);
  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);
  unsigned int getHitPoints(void);
};

#endif

#ifndef CPP01_EX03_HUMANA_H_
#define CPP01_EX03_HUMANA_H_
#include "Weapon.hpp"
#include <string>

class HumanA {
private:
  std::string name_;
  Weapon &weapon_;

public:
  HumanA(std::string name, Weapon &weapon);
  void attack();
  const std::string getName(void);
  void setName(std::string name);
};
#endif

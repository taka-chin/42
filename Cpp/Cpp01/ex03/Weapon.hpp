#ifndef CPP01_EX03_WEAPON_H_
#define CPP01_EX03_WEAPON_H_

#include <string>

class Weapon {
private:
  std::string type_;

public:
  Weapon(std::string type);
  const std::string getType(void);
  void setType(std::string type);
};
#endif

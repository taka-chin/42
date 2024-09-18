#ifndef CPP01_EX00_Zombie_H_
#define CPP01_EX00_Zombie_H_

#include <string>

class Zombie {
private:
  std::string name_;

public:
  Zombie();
  const std::string &getName();
  void setName(std::string name);
  void announce(void);
};
#endif

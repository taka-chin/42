#include "Zombie.hpp"

Zombie *newZombie(std::string name);
void randomChump(std::string name);

int main() {
  std::string name1 = "Zombie1";
  std::string name2 = "Zombie2";
  std::string name3 = "Zombie3";
  Zombie zombie;
  Zombie *newzombie;

  zombie.setName(name1);
  zombie.announce();

  newzombie = newZombie(name2);
  newzombie->announce();
  delete newzombie;

  randomChump(name3);
}

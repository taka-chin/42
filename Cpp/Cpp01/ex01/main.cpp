#include "Zombie.hpp"
Zombie *zombieHorde(int N, std::string name);

int main() {
  std::string name1 = "田中";
  int i = 0;
  int zumbieNum = 10;
  Zombie *zombies = zombieHorde(zumbieNum, name1);

  while (i < zumbieNum) {
    zombies[i].announce();
    i++;
  }
  delete[] zombies;
}

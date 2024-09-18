#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name) {
  if (N <= 0)
    return (NULL);
  int i = 0;
  Zombie *newZombie = new Zombie[N];
  while (i < N) {
    newZombie[i].setName(name);
    i++;
  }
  return (newZombie);
}

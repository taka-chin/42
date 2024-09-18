#include "ClapTrap.hpp"
#include <iostream>

int main() {
  ClapTrap tanaka("田中");
  ClapTrap yamada("山田");
  int i = 0;

  while (tanaka.getHitPoints() && yamada.getHitPoints()) {
    std::cout << "Turn: " << i++ << std::endl;
    tanaka.attack("山田");
    yamada.takeDamage(1);
    yamada.beRepaired(1);

    yamada.attack("田中");
    tanaka.takeDamage(1);
    tanaka.beRepaired(1);
  }
}

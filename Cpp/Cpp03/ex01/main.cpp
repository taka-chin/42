#include "ScavTrap.hpp"
#include <iostream>

int main() {
  ScavTrap tanaka("田中");
  ScavTrap yamada("山田");
  int i = 0;

  while (tanaka.getHitPoints() && yamada.getHitPoints()) {
    std::cout << "Turn: " << i++ << std::endl;
    if (tanaka.getHitPoints()) {
      tanaka.attack("山田");
      yamada.takeDamage(20);
      yamada.beRepaired(1);
      yamada.guardGate();
    }
    if (yamada.getHitPoints()) {
      yamada.attack("田中");
      tanaka.takeDamage(20);
      tanaka.beRepaired(1);
      tanaka.guardGate();
    }
  }
}

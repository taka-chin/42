#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
  std::cout << "WrongAnimal Default constructor called" << std::endl;
  type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal() {
  std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) {
  std::cout << "WrongAnimal Copy constructor called" << std::endl;
  *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other) {
  std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->type = other.type;
  }
  return *this;
}

void WrongAnimal::makeSound() const {
  std::cout << "WrongAnimal make sound function called" << std::endl;
  std::cout << "We're the fuckin' wrong animals" << std::endl;
}

std::string WrongAnimal::getType() const { return type; }

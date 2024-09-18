#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  std::cout << "WrongCat Default constructor called" << std::endl;
  type = "WrongCat";
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other) {
  std::cout << "WrongCat Copy constructor called" << std::endl;
  *this = other;
}

WrongCat &WrongCat::operator=(const WrongCat &other) {
  std::cout << "WrongCat Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->type = other.type;
  }
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "WrongCat make sound function called" << std::endl;
  std::cout << "nya-nya-" << std::endl;
}

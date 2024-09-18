#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
  std::cout << "WrongCat Default constructor called" << std::endl;
  type = "WrongCat";
}

WrongCat::~WrongCat() {
  std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &f) : WrongAnimal(f) {
  std::cout << "WrongCat Copy constructor called" << std::endl;
  *this = f;
}

WrongCat &WrongCat::operator=(const WrongCat &f) {
  std::cout << "WrongCat Copy assignment operator called" << std::endl;
  this->type = f.type;
  return *this;
}

void WrongCat::makeSound() const {
  std::cout << "WrongCat make sound function called" << std::endl;
  std::cout << "nya-nya-" << std::endl;
}

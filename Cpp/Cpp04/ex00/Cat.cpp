#include "Cat.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat Default constructor called" << std::endl;
  type = "Cat";
}

Cat::~Cat() { std::cout << "Cat destructor called" << std::endl; }

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat Copy constructor called" << std::endl;
  *this = other;
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->type = other.type;
  }
  return *this;
}

void Cat::makeSound() const {
  std::cout << "Cat make sound function called" << std::endl;
  std::cout << "nya-" << std::endl;
}

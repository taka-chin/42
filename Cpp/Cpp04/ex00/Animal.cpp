#include "Animal.hpp"

Animal::Animal() {
  std::cout << "Animal Default constructor called" << std::endl;
  type = "Animal";
}

Animal::~Animal() { std::cout << "Animal destructor called" << std::endl; }

Animal::Animal(const Animal &other) {
  std::cout << "Animal Copy constructor called" << std::endl;
  *this = other;
}

Animal &Animal::operator=(const Animal &other) {
  std::cout << "Animal Copy assignment operator called" << std::endl;
  if (this != &other) {
    this->type = other.type;
  }
  return *this;
}

void Animal::makeSound() const {
  std::cout << "Animal make sound function called" << std::endl;
  std::cout << "We're the fuckin' animals" << std::endl;
}

std::string Animal::getType() const { return type; }

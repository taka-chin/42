#include "Cat.hpp"

Cat::Cat() : Animal() {
  std::cout << "Cat Default constructor called" << std::endl;
  type = "Cat";
  this->brain = new Brain();
}

Cat::~Cat() {
  std::cout << "Cat destructor called" << std::endl;
  delete this->brain;
}

Cat::Cat(const Cat &other) : Animal(other) {
  std::cout << "Cat Copy constructor called" << std::endl;
  this->type = other.type;
  this->brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other) {
  std::cout << "Cat Copy assignment operator called" << std::endl;
  if (this != &other) {
    Animal::operator=(other);
    this->type = other.type;
    delete this->brain;
    this->brain = new Brain(*other.brain);
  }
  return *this;
}

void Cat::makeSound() const {
  std::cout << "Cat make sound function called" << std::endl;
  std::cout << "nya-" << std::endl;
}

void Cat::strikeOn(std::string something, size_t index) const {
  if (index >= brain->getCount()) {
    throw std::out_of_range("Index out of range");
  }
  std::cout << "Cat strike on function called" << std::endl;
  this->brain->setIdea(something, index);
}

std::string Cat::showIdea(size_t index) const {
  if (index >= brain->getCount()) {
    throw std::out_of_range("Index out of range");
  }
  std::cout << "Cat show idea function called" << std::endl;
  return this->brain->getIdea(index);
}

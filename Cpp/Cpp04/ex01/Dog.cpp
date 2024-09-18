#include "Dog.hpp"

Dog::Dog() : Animal() {
  std::cout << "Dog Default constructor called" << std::endl;
  type = "Dog";
  this->brain = new Brain();
}

Dog::~Dog() {
  std::cout << "Dog destructor called" << std::endl;
  delete this->brain;
}

Dog::Dog(const Dog &other) : Animal(other) {
  std::cout << "Dog Copy constructor called" << std::endl;
  this->type = other.type;
  this->brain = new Brain(*other.brain);
}

Dog &Dog::operator=(const Dog &other) {
  std::cout << "Dog Copy assignment operator called" << std::endl;
  if (this != &other) {
    Animal::operator=(other);
    this->type = other.type;
    delete this->brain;
    this->brain = new Brain(*other.brain);
  }
  return *this;
}

void Dog::makeSound() const {
  std::cout << "Dog make sound function called" << std::endl;
  std::cout << "one" << std::endl;
}

void Dog::strikeOn(std::string something, size_t index) const {
  if (index >= brain->getCount()) {
    throw std::out_of_range("Index out of range");
  }
  std::cout << "Cat strike on function called" << std::endl;
  this->brain->setIdea(something, index);
}

std::string Dog::showIdea(size_t index) const {
  if (index >= brain->getCount()) {
    throw std::out_of_range("Index out of range");
  }
  std::cout << "Cat show idea function called" << std::endl;
  return this->brain->getIdea(index);
}

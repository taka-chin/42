#include "Brain.hpp"
#include <iostream>

Brain::Brain() { std::cout << "Brain Default constructor called" << std::endl; }

Brain::~Brain() { std::cout << "Brain destructor called" << std::endl; }

Brain::Brain(const Brain &other) {
  std::cout << "Brain Copy constructor called" << std::endl;
  *this = other;
}

Brain &Brain::operator=(const Brain &other) {
  std::cout << "Brain Copy assignment operator called" << std::endl;
  size_t i = 0;
  if (this != &other) {
    while (i < count) {
      this->idea[i] = other.idea[i];
      i++;
    }
  }
  return *this;
}

size_t Brain::getCount() { return count; }

std::string Brain::getIdea(size_t index) {
  if (index >= count) {
    throw std::out_of_range("Index out of range");
  }
  std::cout << "Brain get idea function called" << std::endl;
  return this->idea[index];
}

void Brain::setIdea(const std::string &something, size_t index) {
  if (index >= count) {
    throw std::out_of_range("Index out of range");
  }
  std::cout << "Brain set idea function called" << std::endl;
  this->idea[index] = something;
}

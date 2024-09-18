#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
  Dog();
  ~Dog();
  Dog(const Dog &f);
  Dog &operator=(const Dog &f);
  void makeSound() const;
};

#endif

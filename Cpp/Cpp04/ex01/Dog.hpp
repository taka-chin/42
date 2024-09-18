#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
  Brain *brain;

public:
  Dog();
  ~Dog();
  Dog(const Dog &f);
  Dog &operator=(const Dog &f);
  void makeSound() const;
  void strikeOn(std::string something, size_t index) const;
  std::string showIdea(size_t index) const;
};

#endif

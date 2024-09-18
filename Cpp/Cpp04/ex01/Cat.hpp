#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
  Brain *brain;

public:
  Cat();
  ~Cat();
  Cat(const Cat &f);
  Cat &operator=(const Cat &f);
  void makeSound() const;
  void strikeOn(std::string something, size_t index) const;
  std::string showIdea(size_t index) const;
};

#endif

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  const Animal *meta = new Animal();
  const Animal *j = new Dog();
  const Animal *i = new Cat();
  const WrongAnimal *k = new WrongCat();
  const Cat cat;
  const Cat copycat = cat;

  std::cout << j->getType() << " " << std::endl;
  std::cout << i->getType() << " " << std::endl;
  std::cout << k->getType() << " " << std::endl;
  std::cout << cat.getType() << " " << std::endl;
  std::cout << copycat.getType() << " " << std::endl;

  i->makeSound(); // will output the cat sound!
  delete i;
  j->makeSound();
  delete j;
  meta->makeSound();
  delete meta;
  k->makeSound();
  delete k;
  return 0;
}

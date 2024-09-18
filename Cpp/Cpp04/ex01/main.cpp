#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
  int N = 10;
  int i = 0;
  const Animal *animals[N];

  const Cat cat;
  try {
    cat.strikeOn("i am cat", 0);

    Cat copycat;
    copycat = cat;
    const Cat copycat1(cat);

    std::cout << "==============================" << std::endl;
    std::cout << cat.showIdea(0) << std::endl;
    std::cout << copycat.showIdea(0) << std::endl;
    std::cout << copycat1.showIdea(0) << std::endl;
    std::cout << "==============================" << std::endl;

    cat.strikeOn("i am dog", 0);

    std::cout << "==============================" << std::endl;
    std::cout << cat.showIdea(0) << std::endl;
    std::cout << copycat.showIdea(0) << std::endl;
    std::cout << copycat1.showIdea(0) << std::endl;
    std::cout << "==============================" << std::endl;
  } catch (const std::out_of_range &e) {
    std::cerr << "Exception: " << e.what() << std::endl;
    return (1);
  }
  std::cout << "==============================" << std::endl;

  while (i < N) {
    if (i < N / 2) {
      std::cout << "==============================" << std::endl;
      std::cout << i << std::endl;
      animals[i] = new Dog();
      animals[i]->makeSound();
    } else {
      std::cout << "==============================" << std::endl;
      std::cout << i << std::endl;
      animals[i] = new Cat();
      animals[i]->makeSound();
    }
    i++;
  }
  std::cout << "==============================" << std::endl;
  i = 0;
  while (i < N) {
    std::cout << "==============================" << std::endl;
    std::cout << i << std::endl;
    delete animals[i];
    i++;
  }
  std::cout << "==============================" << std::endl;
  return 0;
}

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <cstddef>
#include <string>

class Brain {
private:
  static const size_t count = 100;
  std::string idea[count];

public:
  Brain();
  virtual ~Brain();
  Brain(const Brain &other);
  Brain &operator=(const Brain &other);
  std::string getIdea(size_t index);
  void setIdea(const std::string &something, size_t index);
  size_t getCount();
};

#endif

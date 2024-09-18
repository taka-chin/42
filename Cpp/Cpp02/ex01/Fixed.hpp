#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>

class Fixed {
private:
  int fixedPointNum;
  static const int digits = 8;

public:
  Fixed();
  Fixed(const int inputNum);
  Fixed(const float inputNum);
  ~Fixed();
  Fixed(const Fixed &f);
  Fixed &operator=(const Fixed &f);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};
std::ostream &operator<<(std::ostream &output, const Fixed &f);
#endif

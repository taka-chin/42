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
  Fixed operator+(const Fixed &f);
  Fixed operator-(const Fixed &f);
  Fixed operator*(const Fixed &f);
  Fixed operator/(const Fixed &f);
  bool operator>(const Fixed &f);
  bool operator<(const Fixed &f);
  bool operator>=(const Fixed &f);
  bool operator<=(const Fixed &f);
  bool operator==(const Fixed &f);
  bool operator!=(const Fixed &f);
  Fixed &operator++();
  Fixed &operator--();
  Fixed operator++(int);
  Fixed operator--(int);
  static Fixed &min(Fixed &f1, Fixed &f2);
  static const Fixed &min(const Fixed &f1, const Fixed &f2);
  static Fixed &max(Fixed &f1, Fixed &f2);
  static const Fixed &max(const Fixed &f1, const Fixed &f2);
  int getRawBits(void) const;
  void setRawBits(int const raw);
  float toFloat(void) const;
  int toInt(void) const;
};

std::ostream &operator<<(std::ostream &output, const Fixed &f);
#endif

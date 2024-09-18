#include "Fixed.hpp"
#include <cmath>

#include <iostream>

Fixed::Fixed() : fixedPointNum(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int inputNum) {
  std::cout << "Int constructor called" << std::endl;
  fixedPointNum = inputNum << digits;
}

Fixed::Fixed(const float inputNum) {
  std::cout << "Float constructor called" << std::endl;
  fixedPointNum = roundf(inputNum * (1 << digits));
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }

Fixed::Fixed(const Fixed &f) {
  std::cout << "Copy constructor called" << std::endl;
  *this = f;
}

Fixed &Fixed::operator=(const Fixed &f) {
  std::cout << "Copy assignment operator called" << std::endl;
  this->fixedPointNum = f.getRawBits();
  return *this;
}

int Fixed::getRawBits(void) const {
  /* std::cout << "getRawBits member function called" << std::endl; */
  return this->fixedPointNum;
}

void Fixed::setRawBits(int const raw) {
  std::cout << "setRawBits member function called" << std::endl;
  this->fixedPointNum = raw;
}

float Fixed::toFloat(void) const {
  return static_cast<float>(fixedPointNum) / (1 << digits);
}

int Fixed::toInt(void) const { return fixedPointNum >> digits; }

std::ostream &operator<<(std::ostream &output, const Fixed &f) {
  output << f.toFloat();
  return output;
}

Fixed Fixed::operator+(const Fixed &f) {
  std::cout << "plus assignment operator called" << std::endl;
  Fixed ret;
  ret.setRawBits(this->getRawBits() + f.getRawBits());
  return ret;
}

Fixed Fixed::operator-(const Fixed &f) {
  std::cout << "minus assignment operator called" << std::endl;
  Fixed ret;
  ret.setRawBits(this->getRawBits() - f.getRawBits());
  return ret;
}

Fixed Fixed::operator*(const Fixed &f) {
  std::cout << "mlutiplication assignment operator called" << std::endl;
  Fixed ret;
  ret.setRawBits((this->getRawBits() * f.getRawBits()) >> digits);
  return ret;
}

Fixed Fixed::operator/(const Fixed &f) {
  std::cout << "division assignment operator called" << std::endl;
  Fixed ret;
  ret.setRawBits((this->getRawBits() << digits) / f.getRawBits());
  return ret;
}

bool Fixed::operator>(const Fixed &f) {
  std::cout << "greater than assignment operator called" << std::endl;
  return (this->getRawBits() > f.getRawBits());
}

bool Fixed::operator<(const Fixed &f) {
  std::cout << "less than assignment operator called" << std::endl;
  return (this->getRawBits() < f.getRawBits());
}

bool Fixed::operator>=(const Fixed &f) {
  std::cout << "greater than or equal to assignment operator called"
            << std::endl;
  return (this->getRawBits() >= f.getRawBits());
}

bool Fixed::operator<=(const Fixed &f) {
  std::cout << "less than or equal to assignment operator called" << std::endl;
  return (this->getRawBits() <= f.getRawBits());
}

bool Fixed::operator==(const Fixed &f) {
  std::cout << "equality assignment operator called" << std::endl;
  return (this->getRawBits() == f.getRawBits());
}

bool Fixed::operator!=(const Fixed &f) {
  std::cout << "not equality assignment operator called" << std::endl;
  return (this->getRawBits() != f.getRawBits());
}

Fixed &Fixed::operator++() {
  std::cout << "pre increment assignment operator called" << std::endl;
  this->fixedPointNum++;
  return (*this);
}

Fixed Fixed::operator++(int) {
  std::cout << "post increment assignment operator called" << std::endl;
  Fixed tmp(*this);
  ++(*this);
  return (tmp);
}

Fixed &Fixed::operator--() {
  std::cout << "pre decrement assignment operator called" << std::endl;
  this->fixedPointNum--;
  return (*this);
}

Fixed Fixed::operator--(int) {
  std::cout << "post decrement assignment operator called" << std::endl;
  Fixed tmp(*this);
  --(*this);
  return (tmp);
}

Fixed &Fixed::min(Fixed &f1, Fixed &f2) {
  return (f1.getRawBits() < f2.getRawBits()) ? f1 : f2;
}

const Fixed &Fixed::min(const Fixed &f1, const Fixed &f2) {
  return (f1.getRawBits() < f2.getRawBits()) ? f1 : f2;
}

Fixed &Fixed::max(Fixed &f1, Fixed &f2) {
  return (f1.getRawBits() > f2.getRawBits()) ? f1 : f2;
}

const Fixed &Fixed::max(const Fixed &f1, const Fixed &f2) {
  return (f1.getRawBits() > f2.getRawBits()) ? f1 : f2;
}

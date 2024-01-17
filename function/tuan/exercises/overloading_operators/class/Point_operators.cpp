#include <iostream>

#include "Point.h"

namespace OverloadingOperators {

// Operators
// +, -, *, /
Point Point::operator+(Point &p) {
  PointData _p = p.GetValue();

  return { this->_x_ + _p.x, this->_y_ + _p.y };
};

Point Point::operator-(Point &p) {
  PointData _p = p.GetValue();

  return { this->_x_ - _p.x, this->_y_ - _p.y };
};

Point Point::operator*(Point &p) {
  PointData _p = p.GetValue();

  return { this->_x_ * _p.x, this->_y_ * _p.y };
};

Point Point::operator/(Point &p) {
  PointData _p = p.GetValue();

  return { this->_x_ / _p.x, this->_y_ / _p.y };
};

// Postfix and Prefix ++, --
Point& Point::operator++() { // Prefix
  this->_x_ += 1;
  this->_y_ += 1;

  return *this;
};

Point Point::operator++(int) { // Postfix
  Point temp = *this;

  this->_x_ += 1;
  this->_y_ += 1;

  return temp;
};

Point& Point::operator--() { // Prefix
  this->_x_ -= 1;
  this->_y_ -= 1;

  return *this;
};

Point Point::operator--(int) { // Postfix
  Point temp = *this;

  this->_x_ -= 1;
  this->_y_ -= 1;

  return temp;
};

// =
Point& Point::operator=(Point &p) {
  PointData _p = p.GetValue();

  // Gán value của this bằng với p.
  this->_x_ = _p.x;
  this->_y_ = _p.y;

  return *this;
};

// ()
Point& Point::operator()(float dx, float dy) {
  this->_x_ += dx;
  this->_y_ += dy;

  return *this;
};

};

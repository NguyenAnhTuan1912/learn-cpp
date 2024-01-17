#include <iostream>

#include "Point.h"

namespace OverloadingOperators {

// Định nghĩa các hàm khởi tạo.
Point::Point() {
  this->_x_ = this->_y_ = 0;
}

Point::Point(float x, float y) {
  this->_x_ = x;
  this->_y_ = y;
}

Point::Point(PointData &p) {
  this->_x_ = p.x;
  this->_y_ = p.y;
}

// Định nghĩa hàm lấy value.
PointData Point::GetValue() {
  return { this->_x_, this->_y_ };
};

// Định nghĩa các hàm set value
void Point::SetValue(float x, float y) {
  this->_x_ = x;
  this->_y_ = y;
};

void Point::SetValue(PointData &p) {
  this->_x_ = p.x;
  this->_y_ = p.y;
};

void Point::PrintP() {
  std::cout << "Point: " << this->GetText() << std::endl;
};

std::string Point::GetText() {
  return "(" + std::to_string(this->_x_) + ", " + std::to_string(this->_y_) + ")";
};

};

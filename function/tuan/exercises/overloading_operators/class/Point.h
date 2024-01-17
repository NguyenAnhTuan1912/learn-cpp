#pragma once
#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

namespace OverloadingOperators {

struct PointData {
  float x;
  float y;
};

class Point {

public:
  // Constructor
  Point();
  Point(float x, float y);
  Point(PointData &p);

  PointData GetValue();
  void SetValue(float x, float y);
  void SetValue(PointData &p);
  void PrintP();
  std::string GetText();

  // Operators
  // +, -, *, /
  Point operator+(Point &p);
  Point operator-(Point &p);
  Point operator*(Point &p);
  Point operator/(Point &p);

  // Postfix and Prefix ++, --
  Point& operator++(); // Prefix
  Point operator++(int); // Postfix
  Point& operator--(); // Prefix
  Point operator--(int); // Postfix

  // =
  Point& operator=(Point &p);

  // ()
  Point& operator()(float dx, float dy);

private:
  float _x_;
  float _y_;

};

};

#endif // POINT_H_INCLUDED

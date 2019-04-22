#include "shape.h"

#include <cmath>

Circle::Circle(double radius) : Shape(), radius_(radius) {}

double Circle::area() const {
  return std::pow(radius_, 2) * M_PI;
}


Rectangle::Rectangle(double width, double height) : Shape(), width_(width), height_(height) {}

double Rectangle::area() const {
  return width_ * height_;
}


Trapezoid::Trapezoid(double upper_width, double lower_width, double height)
    : Shape(), upper_width_(upper_width), lower_width_(lower_width), height_(height) {}

double Trapezoid::area() const {
  return (upper_width_ + lower_width_) * height_ / 2;
}

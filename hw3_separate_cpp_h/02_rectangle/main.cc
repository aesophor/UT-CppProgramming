#include <iostream>

#include "shape.h"

using std::cout;
using std::endl;

int main() {
  // C++ Polymorphism ^_^
  Shape* circle = static_cast<Shape*>(new Circle(15));
  Shape* rect = static_cast<Shape*>(new Rectangle(20, 15));
  Shape* trapezoid = static_cast<Shape*>(new Trapezoid(5, 10, 15));

  cout << "Circle(15) area: " << circle->area() << endl;
  cout << "Rectangle(20, 15) area: " << rect->area() << endl;
  cout << "Trapezoid(5, 10, 15) area: " << trapezoid->area() << endl;
}

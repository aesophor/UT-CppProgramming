#include <iostream>
#include <memory>

#include "shape.h"

using std::cout;
using std::endl;
using std::shared_ptr;

int main() {
  // C++ Polymorphism ^_^
  shared_ptr<Shape> circle = std::make_shared<Circle>(15);
  shared_ptr<Shape> rect = std::make_shared<Rectangle>(20, 15);
  shared_ptr<Shape> trapezoid = std::make_shared<Trapezoid>(5, 10, 15);

  cout << "Circle(15) area: " << circle->area() << endl;
  cout << "Rectangle(20, 15) area: " << rect->area() << endl;
  cout << "Trapezoid(5, 10, 15) area: " << trapezoid->area() << endl;
}

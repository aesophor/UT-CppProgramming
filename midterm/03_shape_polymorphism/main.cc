#include <iostream>

#include "shape.h"

int main() {
  // Polymorphism using raw pointers.
  Shape* triangle = new Triangle();
  Shape* circle = new Circle();
  Shape* rectangle = new Rectangle();

  triangle->setDrag();
  circle->setDrag();
  rectangle->setDrag();

  delete triangle;
  delete circle;
  delete rectangle;
}

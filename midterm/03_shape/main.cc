#include <iostream>

#include "shape.h"

using namespace std;

int main() {
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

#include "shape.h"

double shape::getW() {
  return width;
}

double shape::getH() {
  return height;
}

void shape::setW(double w) {
  width = w;
}

void shape::setH(double h) {
  height = h;
}

double shape::getArea() {
  return width * height;
}

shape::shape() {
  std::cout << "This is the shape constructor" << std::endl;
  width = -1;
  height = -1;
  counter++;
}

shape::shape(double w, double h) {
  std::cout << "This is the shape constructor" << std::endl;
  width = w;
  height = h;
  counter++;
}

shape::~shape() {
  std::cout << "This is the shape destructor" << std::endl;
}

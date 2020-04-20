

#include "shape.h"
#include "rectangle.h"

int main() {
  // shape * s1 = new shape(4.6, 5.6);
  // shape * s1 = new shape();
  // std::cout << s1->getArea() << std::endl;

  // How do we use constructors when the base class has only a parametized constructor?
  // Derive a class where the

  rectangle * r1 = new rectangle();
  r1->setRectanglePattern(DOT);

  r1->setW(4.5);
  r1->setH(6.7);
  std::cout << r1->getArea() << std::endl;

  delete r1;


  triangle * t1 = new triangle();

  t1->setW(4);
  t1->setH(6);

  std::cout << t1->getArea() << std::endl;
  shape * s1 = dynamic_cast<shape *>(t1);
  std::cout << s1->getArea() << std::endl;
  delete t1;

  return 0;
}

#pragma once
#include <iostream>

/*
DOXYGEN(platform to generate class documentation)
This is a shape class with two data members, used to explain the class inheritance
*/

enum PATTERN { DASH, DOT };

class shape {
protected:
  double width, height;   // Double variables for the shape class
public:
  // static int counter;

  double getW();          // Accessor for width

  double getH();          // Accessor for height

  void setW(double);      // Mutator for width

  void setH(double);      // Mutator for height

  // Before calling this method make sure to set the width and height
  virtual double getArea();       // Function to compute shape's area


  shape();                // Empty constructor

  shape(double, double);  // Parametized constructor

  ~shape();               // Destructor
};

#endif

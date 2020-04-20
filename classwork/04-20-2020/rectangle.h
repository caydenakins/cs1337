#ifndef RECTANGLE_H
#define SHAPE_H
#include "shape.h"

enum PATTERN { DASH, DOT };

class rectangle : public shape {
  PATTERN rectanglePattern;
public:
  PATTERN getRectanglePattern();
  void setRectanglePattern(PATTERN);
  void setRectangleWidth(double);

  rectangle();
  ~rectangle();
};

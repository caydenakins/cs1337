#include <iostream>

using namespace std;

char str[10];
// element by element
// str[0] = 'h';
// str[1] = 'i';
// str[2] = '!';
// str[3] = '\0';

// initialization list
//

struct point {
  int x;
  int y;
  char* label;
}

int main() {

  point p1;
  p1.x = 456565;
  p1.y = 23232;
  p1.label = new char[21];

  cout << "The x coordinate is " << p1.x << " and the y coordinate is "
    << p1.y << endl;

  point * ptr;
  ptr = &p1;

  ptr -> x = 454545;
  ptr -> y = 5656565;

  cout << "The x coordinate is " << ptr->x << " and the y coordinate is "
    << ptr->y << endl;

  return 0;
}

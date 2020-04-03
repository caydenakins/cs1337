// write a program to find the largest of 3 ints entered by the user
#include <iostream>

using namespace std;

int main() {
  int valueOne, valueTwo, valueThree, greatestValue;

  cout << "What is the value of the first integer? ";
  cin >> valueOne;
  cout << endl;

  cout << "What is the value of the second integer? ";
  cin >> valueTwo;
  cout << endl;

  cout << "What is the value of the third integer? ";
  cin >> valueThree;
  cout << endl;

  if (valueOne > valueTwo && valueOne > valueThree)
    greatestValue = valueOne;
  else if (valueTwo > valueOne && valueTwo > valueThree)
    greatestValue = valueTwo;
  else
    greatestValue = valueThree;

  cout << "The greatest value of the three entered integers is " <<
  greatestValue << endl;

  return 0;
}

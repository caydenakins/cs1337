#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  // double length, width;
  //
  // cout << "What is the length and width of a rectangle?" << endl;
  //
  // cout << "Length: ";
  // cin >> length;
  // if (length < 0) {
  //   cout << "Length must be greater than 0" << endl;
  //   return -1;
  // }
  //
  // cout << "Width: ";
  // cin >> width;
  // if (width < 0) {
  //   cout << "Length must be greater than 0" << endl;
  //   return -2;
  // }
  //
  // double area = length * width;

  string firstName, lastName;
  double examOne,
         examTwo,
         examThree,
         average;
  const int SIZE = 3;

  cout << "What is your first name? ";
  cin >> firstName;

  cout << "What is your last name? ";
  cin >> lastName;

  cout << "What did you get on your first exam? ";
  cin >> examOne;

  cout << "What did you get on your second exam? ";
  cin >> examTwo;

  cout << "What did you get on your third exam? ";
  cin >> examThree;

  average = (examOne + examTwo + examThree) / SIZE;

  cout << "Your average over the three grades is: " << setw(6) << setprecision(2) << fixed << average << endl;


  return 0;
}

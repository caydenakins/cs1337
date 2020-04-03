#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void programOne();
void programTwo();
void programThree();
void programFour();

int main() {
  int programNumber;

  cout << "Which program do you want to run? 1, 2, 3, or 4?" << endl;
  cin >> programNumber;

  while (programNumber < 0 || programNumber > 4) {
    cout << endl;
    cout << "Please select a number 1-4."
    cout << "Which program do you want to run? 1, 2, 3, or 4?" << endl;
    cin >> programNumber;
  }

  if (programNumber == 1)
    programOne();
  else if (programNumber == 2)
    programTwo();
  else if (programNumber == 3)
    programThree();
  else
    programFour();

  return 0;
}

void programOne() {
  double area,
         perimeter,
         radius;

  cout << "What is the radius of the circle?" << endl;
  cin >> radius;

  while (radius <= 0) {
    cout << endl;
    cout << "Radius must be greater than 0" << endl;
    cout << "What is the radius of the circle?" << endl;
    cin >> radius;
  }
  cout << endl;

  area = M_PI * radius * radius;
  perimeter = M_PI * 2 * radius;

  cout << "Your circle's area is " << setw(5) << setprecision(2) << fixed << area << endl;
  cout << "Your circle's perimeter is " << setw(5) << setprecision(2) << fixed << perimeter << endl;
}

void programTwo() {
  const int TOTAL_STUDENTS = 20;
  int student[TOTAL_STUDENTS][2] = { };
  int groupID, age;

  for (int i = 0; i < TOTAL_STUDENTS; i++) {
    cout << "What is student " << i << "'s ID?" << endl;
    cin >> groupID;

    while (groupID < 0 || groupID > 19) {
      cout << endl;
      cout << "The student's group ID must be between 0 and 19." << endl;
      cout << "What is student " << i << "'s ID?" << endl;
      cin >> groupID;
    }
    cout << endl;

    cout << "What is student " << i << "'s age?" << endl;
    cin >> age;

    while (age < 0 || age > 102) {
      cout << endl;
      cout << "The student's age must be between 0 and 102" << endl;
      cout << "What is student " << i << "'s age?" << endl;
      cin >> age;
    }

    student[i][0] = groupID;
    student[i][1] = age;
  }

  for (int i = 0; i < TOTAL_STUDENTS; i++) {
    for (int k = 0; k < 2; k++) {
      if (k == 0)
        cout << "Student " << ( i + 1) << " ID: " << student[i][k] << endl;
      if (k == 1)
        cout << "Student " << ( i + 1) << " age: " << student[i][k] << endl;
    }
  }
}

void programFour() {
  float x1, y1, x2, y2;
  float distance;
  float slope;

  cout << "Enter the coordinates for P1: ";
  cin >> x1;
  cin >> x2;

  cout << "Enter the coordinates for P2: ";
  cin >> y1;
  cin >> y2;

  distance = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
  if ((x2-x1) != 0)
    slope = (y1 - y1) / (x2 - x1);
}

#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <string>

using namespace std;

int main() {
  int index = 0;
  const int TOTAL_STUDENTS = 4;
  int age[TOTAL_STUDENTS] = { 20, 19, 21, 20 };
  string name[TOTAL_STUDENTS] = { "LXT12345", "TRX23456",
                                  "MLK23987", "HTF10482" };
  double gpa[TOTAL_STUDENTS] = { 3.99, 3.89, 3.67, 3.55 };

  double minGPA = 0, maxGPA = 0, averageGPA;

  int youngestUser = 0; // Initialize the 0 index to the youngest
  for (int i = 1; i < TOTAL_STUDENTS; i++) {
    if (age[i] < age[youngestUser])
      youngestUser = i;
  }

  int oldestUser = 0; // Initialize the 0 index to the oldest
  for (int i = 1; i < TOTAL_STUDENTS; i++) {
    if (age[i] > age[oldestUser])
      oldestUser = i;
  }

  for (int i = 1; i < TOTAL_STUDENTS; i++) {
    if (gpa[i] > gpa[maxGPA])
      i = maxGPA;
    if (gpa[i] < gpa[minGPA])
      i = minGPA;
  }

  for (int i = 0; i < TOTAL_STUDENTS; i++) {
    double total += gpa[i];
  }

  averageGPA = total / TOTAL_STUDENTS;

  cout << "Youngest User -  Index: " << youngestUser;
  cout << ", User: " << name[youngestUser] << ", Age: " << age[youngestUser];
  cout << ", GPA: " << gpa[youngestUser] << endl;
  cout << endl;


  cout << "Oldest User -  Index: " << oldestUser;
  cout << ", User: " << name[oldestUser] << ", Age: " << age[oldestUser];
  cout << ", GPA: " << gpa[oldestUser] << endl;
  cout << endl;

  cout << "Minimum GPA: " << gpa[minGPA] << " by user " << name[minGPA];
  cout << endl;
  cout << "Minimum GPA: " << gpa[minGPA] << " by user " << name[minGPA];


  return 0;
}

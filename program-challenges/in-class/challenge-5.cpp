#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  const int TOTAL_STUDENTS = 19;
  int student[TOTAL_STUDENTS][2] = { };
  int groupID, age;

  for (int i = 0; i < TOTAL_STUDENTS; i++) {
    cout << "What is student " << (i + 1) << "'s ID?" << endl;
    cin >> groupID;

    while (groupID < 0 || groupID > 19) {
      cout << endl;
      cout << "The student's group ID must be between 0 and 19." << endl;
      cout << "What is student " << (i + 1) << "'s ID?" << endl;
      cin >> groupID;
    }
    cout << endl;

    cout << "What is student " << (i + 1) << "'s age?" << endl;
    cin >> age;

    while (age < 0 || age > 102) {
      cout << endl;
      cout << "The student's age must be between 0 and 102" << endl;
      cout << "What is student " << (i + 1) << "'s age?" << endl;
      cin >> age;
    }
    cout << endl;

    student[i][0] = groupID;
    student[i][1] = age;
  }

  cout << setw(27) << setfill('-') << " " << endl;
  cout << endl;

  for (int i = 0; i < TOTAL_STUDENTS; i++) {
    for (int k = 0; k < 2; k++) {
      if (k == 0)
        cout << "Student " << ( i + 1) << "'s ID: " << student[i][k] << endl;
      if (k == 1)
        cout << "Student " << ( i + 1) << "'s age: " << student[i][k] << endl;
    }
    cout << endl;
  }

  return 0;
}

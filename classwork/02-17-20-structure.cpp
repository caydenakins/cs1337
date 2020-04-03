#include <iostream>
#include <iomanip>
#include <string>
#define NUM 3

using namespace std;

struct studentInfo {
  string username;
  int         age;
  double      gpa;
};

// struct studentInfo {
//   string username;
//   int age;
//   double gpa;
//
//   void setUsername() {
//     username = u;
//   }
//
//   void setAge(int n) {
//     age = n;
//   }
//
//   int getAge() {
//     return age;
//   }
// };

// Access structure by `myInfo.username = "LXT123"`;
// struct * myInfo;
//  myInfo -> username = "LXT123";

int main() {
  struct studentInfo list[NUM]

  int counter = 0;

  for (; counter < NUM; counter++) {
    cout << "Enter username[ " << counter < " ]: ";
    cin >> list[counter].username;
    cout << "Enter age[ " << counter << " ]: ";
    cin >> list[counter].age;
    cout << "Enter gpa[ " << counter << " ]: ";
    cin >> list[counter].gpa;
  }

  cout.fill('_');
  cout.width(30);
  cout << " " << endl;
  cout.fill(' ');

  for (counter = 0; counter < NUM; counter++) {
    cout << setw(5) << "Index"
      << setw(10) << list[counter].username
      << setw(5) << list[counter].age
      << setw(5) << fixed << setprecision(2)
      << list[counter].gpa;
    cout << endl;
  }

  return 0;
}

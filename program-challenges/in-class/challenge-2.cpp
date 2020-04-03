// write a program to compute the average of 1000 random numbers between -100 and +100
// srand() and rand()
#include <iostream>
#include <ctime>

using namespace std;

int main() {
  int total = 0, average;
  const int TOTAL_RANDOM_NUMBERS = 1000;
  srand(time(0));

  for (int i = 0; i < TOTAL_RANDOM_NUMBERS; i++) {
    i = rand() % 201 + (-100);
    cout << i << endl;
    total += i;
  }

  cout << "#'s: " << TOTAL_RANDOM_NUMBERS << endl;
  cout << "TOTAL: " << total << endl;

  average = total / TOTAL_RANDOM_NUMBERS;
  cout << "The average of 1000 randomly generated numbers is: " << average << endl;

  return 0;
}

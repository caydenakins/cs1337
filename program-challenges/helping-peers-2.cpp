#include <iostream>

using namespace std;

int main() {
  double initialAmount, newTotal;
  int penniesConversion, totalDollars, totalQuarters, totalDimes, totalNickels,
      totalPennies;

  cout << "Enter the amount: ";
  cin >> initialAmount;

  while (initialAmount <= 0) {
    cout << endl;
    cout << "Please enter a value above 0" << endl;
    cout << "Enter the amount: ";
    cin >> initialAmount;
  }

  // Add 0.5 because of floating point decimal multiplication inconsistencies
  penniesConversion = (initialAmount * 100.0) + 0.5;

  totalDollars = penniesConversion / 100;
  totalQuarters = (penniesConversion - (totalDollars * 100)) / 25;
  totalDimes = ((penniesConversion - (totalDollars * 100)) -
    (totalQuarters * 25)) / 10;
  totalNickels = (((penniesConversion - (totalDollars * 100)) -
    (totalQuarters * 25)) - (totalDimes * 10)) / 5;
  totalPennies = ((((penniesConversion - (totalDollars * 100)) -
    (totalQuarters * 25)) - (totalDimes * 10)) - (totalNickels * 5));

  cout << endl;
  cout << "Change due: " << endl;
  cout << totalDollars << " dollars" << endl;
  cout << totalQuarters << " quarters" << endl;
  cout << totalDimes << " dimes" << endl;
  cout << totalNickels << " nickels" << endl;
  cout << totalPennies << " pennies" << endl;

  return 0;
}

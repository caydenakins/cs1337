/*
 * Author: Cayden Akins - CRA190000
 * Class: CS 1337.
 * Date: 1/27/20
 * Description: This program will calculate the average, standard deviation,
 * and variance based on a set of values requested by the user.
 */
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  double minValue, maxValue, standardDeviationNumerator,
         standardDeviation, average, totalSampleValue, variance,
         valueGenerator, increment;

  int numberOfSamples;

  double valueArray[1000] = { };     // Partially filled array

  // Ask for the minimum value
  cout << "What is the minimum value? ";
  cin >> minValue;
  cout << endl;

  // Ask for the maximum value
  cout << "What is the maximum value? ";
  cin >> maxValue;
  cout << endl;

  // Input validation for the minimum and maximum values
  while (maxValue < minValue) {
    cout << "Please enter a maximum value greater than the minimum value" << endl;
    cout << "What is the minimum value? ";
    cin >> maxValue;
    cout << endl;
  }

  // Ask for the number of samples
  cout << "What is the number of samples? ";
  cin >> numberOfSamples;
  cout << endl;

  // Input validation for the number of samples
  while (numberOfSamples <= 0 || numberOfSamples > 1000) {
    cout << "Please enter a number of samples greater than 0 and less than ";
    cout << "1000" << endl;
    cout << "What is the number of samples? ";
    cin >> numberOfSamples;
    cout << endl;
  }

  // Ask for the increment value
  cout << "What is the increment value? ";
  cin >> increment;
  cout << endl;

  // Input validation for the increment
  while (increment > (maxValue - minValue)) {
    cout << "Please enter an increment value that is less than the difference of the minimum and maximum values entered" << endl;
    cout << "What is the increment value? ";
    cin >> increment;
    cout << endl;
  }

  // Eye candy
  cout << "Calculating..." << endl;
  cout << endl;

  // Put items in array and get out once the items are greater than the max
  // value because we can't go any further without breaking a rule
  for (int i = 0; i < numberOfSamples; i++) {
    if (i == 0)                           // We use these 3 conditionals for
      valueGenerator = minValue;          // resetting the sample value back
    else if ((valueGenerator + increment) > maxValue)
      valueGenerator = minValue;          // to the minimum value once we reach
    else                                  // a generated value that would be
      valueGenerator += increment;        // greater than the maximum value

    valueArray[i] = valueGenerator;       // Assign the calculated value to
    totalSampleValue += valueArray[i];    // the array and add to the total
  }

  average = totalSampleValue / (maxValue - minValue);    // Calculate average

  // We have to go through one more for loop because we can only calculate the
  // average once past the first for loop, something we use when finding
  // standard deviation
  for (int i = 0; i < numberOfSamples; i++)
    standardDeviationNumerator += pow((valueArray[i] - average), 2.0);

  // Calculate standard deviation and variance
  standardDeviation = sqrt(standardDeviationNumerator / numberOfSamples);
  variance = standardDeviationNumerator / numberOfSamples;

  // Begin displaying output in table format
  cout << setw(13) << setfill(' ') << left << "Values";
  cout << setw(23) << left << "Standard Deviation";
  cout << "Variance" << endl;
  cout << setw(44) << setfill('-') << "" << endl;

  // Iterate through the array once each time to display all values
  for (int i = 0; i < numberOfSamples; i++) {
    cout << setfill(' ');
    cout << setw(7) << setprecision(4) << fixed << left << valueArray[i];
    cout << setw(5) << setfill(' ') << "";
    cout << "|";

    // For the first iteration, we want to display the standard deviation and
    // variance, but after that, we just insert spaces for them
    if (i == 0) {
      cout << setw(7) << setprecision(4) << fixed << left << standardDeviation;
      cout << setw(15) << setfill(' ') << "";
      cout << "|";
      cout << setw(7) << setprecision(4) << fixed << left << variance;
      cout << endl;
    }
    else {
      cout << setw(22) << setfill(' ') << "";
      cout << "|";
      cout << endl;
    }
  }

  return 0;
}

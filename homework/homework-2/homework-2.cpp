#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double findY(double);
const double PI = 3.141592653;

int main() {
  double xMinimum, xMaximum, increment, populateValue, xValue, yValue,
  minValue, maxValue, range, mean, total, median, mode;
  int minIndex, maxIndex;
  const int POINTS = 21;
  double dataPoints[POINTS] = { };

  // Prompt user for the min and max values they want to use for calculations
  cout << "What is the value of x minimum? ";
  cin >> xMinimum;
  cout << endl;

  cout << "What is the value of x maximum? ";
  cin >> xMaximum;
  cout << endl;

  // We round our increment to the nearest tenth place in order to match the
  // homework example we received using (-4, 4) as the range
  increment = round(10 * ((xMaximum - xMinimum) / POINTS)) / 10;

  // Header formatting for our table we will display
  cout << setw(8) << left << "X-Value" << "|" << right << setw(8)
    << "Y-Value" << endl;
  cout << setw(19) << setfill('-') << " ";
  cout << setfill(' ') << endl;

  xValue = xMinimum;   // We start our table at the smallest value, so x = min

  // For-loop used for populating our array and displaying our table
  for (int i = 0; i < POINTS; i++) {
    dataPoints[i] = (1.0/32.0) * 2.0 * PI * sin(6.036 * xValue) + (1.0/64.0)
      * PI * cos(24.44 * xValue);

    dataPoints[i] = round(dataPoints[i] * 1000) / 1000; // Round for the mode

    cout << setw(8) << setprecision(1) << fixed << left << xValue;
    cout << "|";
    cout << setw(8) << setprecision(3) << fixed << right << dataPoints[i];
    cout << endl;

    total += dataPoints[i];     // Used for our mean calculation
    xValue += increment;        // Increment our x-values in table
  }

  cout << endl;                 // Break between table and math functions

  minValue = dataPoints[0];     // We assign both minimum and maximum values to
  maxValue = dataPoints[0];     // the 0th index to compare later values to it

  // For-loop used for calculating our math functions after the table for-loop
  for (int j = 1; j < POINTS; j++) {
    if (dataPoints[j] > maxValue) {
      maxValue = dataPoints[j];
      maxIndex = j;
    }

    if (dataPoints[j] < minValue) {
      minValue = dataPoints[j];
      minIndex = j;
    }
  }

  range = maxValue - minValue;  // Used to find the range
  mean = total / POINTS;        // Used to find the mean

  // We use a bubble sort to make it easier to find the median and mode
  for (int maxElement = POINTS - 1; maxElement > 0; maxElement--) {
    for (int index = 0; index < maxElement; index++) {
      if (dataPoints[index] > dataPoints[index + 1]) {
        double temp = dataPoints[index];
        dataPoints[index] = dataPoints[index + 1];
        dataPoints[index + 1] = temp;
      }
    }
  }

  // Two nested for-loops used to find our mode of the array
  // We increase our count every time our second for-loop value equals the
  // first for-loop, assigning a mode index after nested loop finishes if true
  int count = 0;
  int modeIndex = -1;
  for (int i = 0; i < POINTS; i++) {
    for (int j = 0; j < POINTS; j++) {
      if (j == i)
        j += 1;
      if (dataPoints[j] == dataPoints[i])
        count++;
    }
    if (count > modeIndex + 1)
      modeIndex = i;
  }

  // Math functions display after our table display
  cout << "Minimum Value (X = " << dataPoints[minIndex] << "): "
    << minValue << endl;
  cout << "Maximum Value (X = " << dataPoints[maxIndex] << "): "
    << maxValue << endl;
  cout << "Range: " << range << endl;
  cout << "Mean: " << mean << endl;
  cout << "Median: " << dataPoints[11] << endl;     // 11 is in middle of 21
  if (modeIndex == -1)
    cout << "Mode: N/A" << endl;
  else
    cout << "Mode: " << dataPoints[modeIndex] << endl;

  return 0;
}

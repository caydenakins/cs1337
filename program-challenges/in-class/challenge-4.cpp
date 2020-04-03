#include <iostream>
#include <cmath>

using namespace std;

int randomNumber(int, int);
double getAverage(int, int);
int getMinimumValue(int, int);
int getMinimumValue(int, int);
void sortArray(int, int);

int main() {
  const int ARRAY_SIZE = 40;
  int minNumber, maxNumber, generatedNumber, minValue, maxValue;
  double average;
  int myArray[ARRAY_SIZE] = { };

  cout << "What is the minimum number for the random number generator range? ";
  cin >> minNumber;

  cout << "What is the minimum number for the random number generator range? ";
  cin >> maxNumber;

  for (int i = 0; i < ARRAY_SIZE; i++) {
    generatedNumber = randomNumber(minNumber, maxNumber);
    myArray[i] = generatedNumber;
  }

  average = arrayAverage(myArray, ARRAY_SIZE);
  minValue = getMinValue(myArray, ARRAY_SIZE);
  maxValue = getMaxValue(myArray, ARRAY_SIZE);
  sortArray(myArray, ARRAY_SIZE);

  return 0;
}

int randomNumber(int minimum, int maximum) {
  int rand = (rand() % (maximum - minimum)) + minimum;
  return rand;
}

double getAverage(int array, int size) {
  double arrayTotal = 0, arrayAverage = 0;
  for (int k = 0; k < size; k++) {
    arrayTotal += array[k];
  }
  arrayAverage = arrayTotal / size;
  return arrayAverage;
}

void sortArray(int array, int size) {

}

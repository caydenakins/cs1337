#include <iostream>

using namespace std;

void linearSearch(int[], int, int);
void binarySearch(int[], int, int);
void bubbleSort(double[], int);
void selectionSort(int[], int);

int main() {
  const int SIZE = 10;
  int array[SIZE] = { 82, 84, 90, 93, 78, 62, 99, 98, 91, 73 };
  int value = 99;

  for (int i = 0; i < SIZE; i++)
    cout << array[i] << " ";

  bubbleSort(array, SIZE);

  cout << "AFTER" << endl;

  for (int i = 0; i < SIZE; i++)
    cout << array[i] << " ";



  return 0;
}

void linearSearch(int myArray[], int size, int number) {
  int position = -1;
  int index = 0;
  bool found = false;

  while (!found && index < size) {
    if (myArray[index] == number) {
      position = index;
      found = true;
    }
    index++;
  }
}

void binarySearch(int myArray[], int size, int number) {
  int first = 0,
      middle,
      last = size - 1;
  bool found = false;
  int position = -1;

  while (!found && first <= last) {
    middle = (first + last) / 2;

    if (myArray[middle] == number) {
      position = middle;
      found = true;
    }

    else if (myArray[middle] > number)
      last = middle - 1;

    else
      first = middle + 1;
  }
}

void bubbleSort(double myArray[], int size) {
  int maxElement, index;

  for (maxElement = size - 1; maxElement > 0; maxElement--) {
    for (int index = 0; index < maxElement; index++) {
      if (myArray[index] > myArray[index + 1]) {
        int temp = myArray[index];
        myArray[index] = myArray[index + 1];
        myArray[index + 1] = temp;
      }
    }
  }
}

void selectionSort(int myArray[], int size) {
  int minValue, minIndex;

  for (int start = 0; start < size - 1; start++) {
    minValue = myArray[start];
    minIndex = start;
    for (int index = start + 1; index < size; index++) {
      if (myArray[index] < minValue) {
        minValue = myArray[index];
        minIndex = index;
      }
    }
    int temp = myArray[minIndex];
    myArray[minIndex] = myArray[start];
    myArray[start] = temp;
  }

}

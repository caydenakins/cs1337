#include <iostream>

using namespace std;

int main() {

  const int SIZE = 10;
  int array[SIZE] = { 82, 84, 90, 93, 78, 62, 99, 98, 91, 73 };
  int value = 99;

  // LINEAR SEARCH
  int position = -1;
  int index = 0;
  bool found = false;

  while (!found && index < size) {
    if (array[index] == value) {
      position = index;
      found = true;
    }
    index++;
  }

  // BINARY SEARCH
  int first = 0,
      middle,
      last = SIZE - 1;
  bool found = false;
  int position = -1;

  while (!found && first <= last) {
    middle = (first + last) / 2;

    if (array[middle] == value) {
      position = middle;
      found = true;
    }

    else if (array[middle] > value)
      last = middle - 1;

    else
      first = middle + 1;
  }

  // BUBBLE SORT
  int maxElement, index;

  for (maxElement = size - 1; maxElement > 0; maxElement--) {
    for (index = 0; index < maxElement; index++) {
      if (array[index] > array[index + 1]) {
        int temp = array[index];
        array[index] = array[index + 1];
        array[index + 1] = temp;
      }
    }
  }

  // SELECTION SORT
  int minValue, minIndex;

  for (int start = 0; start < size - 1; start++) {
    minValue = array[start];
    minIndex = start;
    for (int index = start + 1; index < size; index++) {
      if (array[index] < minValue) {
        minValue = array[index];
        minIndex = index;
      }
    }
    int temp = array[minIndex];
    array[minIndex] = array[start];
    array[start] = temp;


    // linear

    bool found = false;
    int position = -1;
    int index = 0;

    while (!found && index < size) {
      if (array[index] == value) {
        found = true;
        position = index;
      }
      index++;
    }

    // binary
    int first = 0,
        middle,
        last = size - 1;
    bool found = false;
    int position = -1;

    while (!found && first < last) {
      middle = (first + last) / 2;

      if (array[middle] == value) {
        found = true;
        position = middle;
      }

      else if (array[middle] > value)
        middle = last - 1;

      else
        middle = first + 1;
    }

    // bubble sort
    int maxElement, index;
    for (maxElement = size - 1; maxElement > 0; maxElement--) {
      for (index = 0; index < maxElement; index++) {
        if (array[index] > array[index + 1]) {
          int temp = array[index];
          array[index] = array[index + 1];
          array[index + 1] = temp;
        }
      }
    }

    // selection sort
    int minValue, minIndex;

    for (int start = 0; start < size; start++) {
      minValue = array[start];
      minIndex = start;
      for (int index = start + 1; index < size; index++) {
        if (array[index] < minValue) {
          minValue = array[index];
          minIndex = index;
        }
      }
      int temp = array[minIndex];
      array[minIndex] = array[start];
      array[start] = temp;
    }





  return 0;
}

#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int * globalArray = nullptr;

int *createArray(int &);
void findStats(int *, int, int &, int &, double &);
int *searchElement(int *, int, int);
void findSequence(int *, int);

int main() {
  srand(time(0));       // Seed for our random number generator

  double avg;           // Average for our switch case 'B'/'b'
  char choice;          // Keep track of the user's choice
  bool reminder = false, completeA = false, completeB = false,
       completeC = false, firstRun = true, leaveLoop;
  int size, minimum, maximum, key, lines = 0;
  int * array;          // Array pointer
  int * elementValue;   // Gets us the memory address of desired element

  while (choice != 'D' && choice != 'd') {
    // This will be the output when it is not our first time
    if (!firstRun) {
        cout << "A. Create and initialize a dynamic array" << endl;
      if (!completeB)
        cout << "B. Display statistics on the array" << endl;
      if (!completeC)
        cout << "C. Search for an element" << endl;
      cout << "D. Quit" << endl;
      cout << "E. BONUS" << endl;

      cout << endl;
      cin >> choice;
      cout << endl;

      // Because of our feature that removes items from the list after being
      // selected, we need to regenerate our items if we create a new array
      if (choice == 'A' || choice == 'a') {
        completeB = false;
        completeC = false;
      }
    }

    while (firstRun) {
      // Our reminder reminds the user they must select option 'A'/'a' before
      // anything else
      if (reminder) {
        cout << "You must select choice A. before you select choice " << choice
          << ". " << endl;
        cout << endl;
      }

      cout << "A. Create and initialize a dynamic array" << endl;
      cout << "B. Display statistics on the array" << endl;
      cout << "C. Search for an element" << endl;
      cout << "D. Quit" << endl;
      cout << "E. BONUS" << endl;

      cout << endl;
      cin >> choice;
      cout << endl;

      if (choice == 'A' || choice == 'a')
        firstRun = false;            // To know user picked A - leave loop

      if (!reminder)                 // Will remind the user if they can't get
        reminder = true;             // out of the while loop their first time
    }

    switch(choice) {
      // Case 'A'/'a' that includes the `createArray()` function
      case 'A':
      case 'a': {
        array = createArray(size);        // Call function to create array

        // Beginning output for showing the user their array
        cout << "Here are the contents of your generated array: " << endl;
        cout << endl;
        cout << setw(4) << " ";           // Add a small space for formatting

        // This is the for-loop which will output the contents of our array
        for (int i = 0; i < size; i++) {
          cout << array[i] << " ";
          lines++;                        // We add `lines` so we can create a
          if (lines > 8) {                // new line every 8 values
            cout << endl;
            cout << setw(4) << " ";       // Add a small space for formatting
            lines = 0;                    // Reset lines once we reach the if
          }
        }

        cout << endl;
        cout << endl;

        completeA = true;

        break;
      }

      // Case 'B'/'b' that includes the `findStats()` function
      case 'B':
      case 'b': {
        // Call function to find the statistics of the array
        findStats(array, size, minimum, maximum, avg);
        cout << "Average: " << avg << endl;     // Display average of array
        cout << "Min: " << minimum << endl;     // Display minimum of array
        cout << "Max: " << maximum << endl;     // Display maximum of array
        cout << endl;

        completeB = true;

        break;
      }

      // Case 'C'/'c' that includes the `searchElement()` function
      case 'C':
      case 'c': {
        cout << "What is the element key you would like to "
          << "search for in the array? ";
        cin >> key;
        cout << endl;
        // Call function to find if the key a user specifies exists and show
        // the user the memory location of the key if it does exist
        elementValue = searchElement(array, size, key);

        // If statements to display the element value's location
        if (elementValue != nullptr) {
          cout << "Your element " << *elementValue << " was found at "
            << elementValue << endl;
        }
        else
          cout << "Your element was not found in the array" << endl;

        cout << endl;
        completeC = true;

        break;
      }

      // Case 'D'/'d' exits the code
      case 'D':
      case 'd': {
        cout << "Exiting..." << endl;
        exit(EXIT_SUCCESS);
        break;
      }

      // Case 'E'/'e' that includes the `findSequence()` function
      case 'E':
      case 'e': {
        // Bonus function that finds if a user's desired sequence exists
        findSequence(array, size);
        break;
      }
    }
  }

  // Delete our array
  if (globalArray != nullptr)
    delete[] array;

  return 0;
}

// Function that creates and initializes our array using random numbers
int *createArray(int &N) {
  int randomNumber;                     // Used later to populate our array

  cout << "Enter the size of your array: ";
  cin >> N;
  cout << endl;

  int * globalArray = new int[N];       // Initialize our array with size N

  for(int i = 0; i < N; i++) {
    randomNumber = rand() % 981 + 80;
    globalArray[i] = randomNumber;
  }

  return globalArray;
}

// Function that finds the stats of the array (min, max, and average)
void findStats(int *arr, int N, int &min, int &max, double &average) {
  // Find min algorithm
  min = arr[0];

  for (int i = 1; i < N; i++) {
    if (arr[i] < min)
      min = arr[i];
  }

  // Find max algorithm
  max = arr[0];
  for (int i = 1; i < N; i++) {
    if (arr[i] > max)
      max = arr[i];
  }

  // Find average algorithm
  int total = 0;

  for (int i = 0; i < N; i++)
    total += arr[i];

  average = total / N;
}

// Find if the key a user specifies exists, then return its memory address
int *searchElement(int *arr, int N, int key) {
  bool found = false;
  int index = 0;

  while (index < N) {
    if (arr[index] == key)
      return &arr[index];
    index++;
  }

  //int * elementFound = arr[index];

  return nullptr;
}

// Function that finds if a desired sequence the user entered exists
void findSequence(int *arr, int N) {
  int integerOne, integerTwo, integerThree, integerFour, index = 0;
  bool sequenceFound = false;

  cout << "Enter 4 integers from the array to find their sequence" << endl;
  cout << endl;

  cout << "Integer 1: ";
  cin >> integerOne;

  cout << "Integer 2: ";
  cin >> integerTwo;

  cout << "Integer 3: ";
  cin >> integerThree;

  cout << "Integer 4: ";
  cin >> integerFour;
  cout << endl;

  while (index < N) {
    if (arr[index] == integerOne && arr[index + 1] == integerTwo &&
      arr[index + 2] == integerThree && arr[index + 3] == integerFour) {
          sequenceFound = true;
          cout << "The integers you input were correctly in the order you gave"
           << " them in." << endl;
    }
    index++;
  }

  if (!sequenceFound)
    cout << "The integers you input were not found in a sequence" << endl;

  cout << endl;
}

/*
 * Author: Cayden Akins - CRA190000
 * Class: CS 1337
 * Date: 03/06/20
 * Description: This program will read in values from a text file with the use of
 * a structured array and pointers. We utilize modular programming to create an
 * efficient and concise program that calculates the shortest distance between
 * a user and the nearest service they desire. It also takes into account the
 * call frequency each service receives.
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

enum SERVICE_TYPE {POLICE_DEPARTMENT, HOSPITAL, FIRE_STATION};

struct service {
  int serviceID;
  double x_coordinate;
  double y_coordinate;
  SERVICE_TYPE service;
  string city_name;
  int calls;
};

service *data;

int countLines(string);
int readFile(string, service *);
int findNearestService(service *, int, double, double);
int findNearestPoliceDepartment(service *, int, double, double);
int findNearestHospital(service *, int, double, double);
int findNearestFireStation(service *, int, double, double);
int compareValues(service *, int, double, double, bool, int);
void output(service *, int, double, double, string);
void sortByService(service *, int);
int outputList(service *, int, string);

int main() {
  string inputFileName = "serviceInfo.txt", outputFileName = "sortedServiceInfo.txt";
  string defaultService = "service",
      policeDepartment = "police department",
      hospital = "hospital",
      fireStation = "fire station";

  char inputOne, inputTwo;
  double x_coordinateUser, y_coordinateUser;
  int nearestService, nearestPoliceDepartment, nearestHospital, nearestFireStation, reminder = 0, outputCheck;

  int counter = countLines(inputFileName);  // Count number of lines in text file for array size

  // If we fail to count properly, we return 0
  if (counter <= 0)
    return -1;

  data = new service[counter];

  // If we can't read the file and fill the array properly, we return -1
  if (readFile(inputFileName, data) < 0)
    return -1;

  // Input validation, forcing the user to either exit or enter their coordinates before passing
  while (inputOne != 'a' && inputOne != 'f') {
    if (reminder > 0)
      cout << "You must select option a) before you select option " << inputOne << ")" << endl;

    cout << "a) Enter your location (x,y)" << endl;
    cout << "b) Find the nearest service" << endl;
    cout << "c) Find the nearest POLICE DEPARTMENT" << endl;
    cout << "d) Find the nearest HOSPITAL" << endl;
    cout << "e) Find the nearest FIRE STATION" << endl;
    cout << "f) Exit" << endl;
    cout << endl;
    cin >> inputOne;
    cout << endl;

    reminder++;
  }

  // Only have the user enter his coordinates if he selected a)
  if (inputOne == 'a') {
    cout << "X-coordinate: ";
    cin >> x_coordinateUser;
    cout << "Y-coordinate: ";
    cin >> y_coordinateUser;
  }

  // Display the menu for the user and enter the while loop to continue prompting the user
  while (inputTwo != 'f' && inputOne != 'f') {
    cout << endl;
    cout << "b) Find the nearest service" << endl;
    cout << "c) Find the nearest POLICE DEPARTMENT" << endl;
    cout << "d) Find the nearest HOSPITAL" << endl;
    cout << "e) Find the nearest FIRE STATION" << endl;
    cout << "f) Exit" << endl;
    cout << endl;

    cin >> inputTwo;
    cout << endl;

    switch (inputTwo) {
      case 'b': {
        nearestService = findNearestService(data, counter, x_coordinateUser, y_coordinateUser);
        output(data, nearestService, x_coordinateUser, y_coordinateUser, defaultService);
        break;
      }
      case 'c': {
        nearestPoliceDepartment = findNearestPoliceDepartment(data, counter, x_coordinateUser, y_coordinateUser);
        output(data, nearestPoliceDepartment, x_coordinateUser, y_coordinateUser, policeDepartment);
        break;
      }
      case 'd': {
        nearestHospital = findNearestHospital(data, counter, x_coordinateUser, y_coordinateUser);
        output(data, nearestHospital, x_coordinateUser, y_coordinateUser, hospital);
        break;
      }
      case 'e': {
        nearestFireStation = findNearestFireStation(data, counter, x_coordinateUser, y_coordinateUser);
        output(data, nearestFireStation, x_coordinateUser, y_coordinateUser, fireStation);
        break;
      }
      case 'f':
        cout << "Exiting..." << endl;
        break;
    }
  }

  cout << endl;

  sortByService(data, counter);

  outputCheck = outputList(data, counter, outputFileName);

  if (outputCheck == -1)
    cout << "The output value failed to open" << endl;

  delete [] data;
  data = nullptr;

  return 0;
}

// Function that will count the amount of lines the text file has, allowing for later functions
// to manipulate searches/sorts due to having access to the size of the index/array
int countLines(string inputFileName) {
  ifstream input;
  input.open(inputFileName);
  int totalLines;
  string dummy;

  if (!input.is_open())
    return -1;

  while (!input.eof()) {
    getline(input, dummy);
    totalLines++;
  }

  input.close();

  return totalLines;
}

// Function that will store every line of code into the structured format inside of our array
int readFile(string inputFileName, service *serviceData) {
  ifstream input;     // Define our input file stream
  int counter = 0;    // Define counter to increase index after every line
  int temp;           // Value used to convert to enum to find service type

  input.open(inputFileName);

  // If our input fails to open, we will return with an error code of -1
  if (!input.is_open())
    return -1;

  // Continue to input each line of code until the end of the input file is reached
  while (!input.eof()) {
    input >> serviceData[counter].serviceID >> serviceData[counter].x_coordinate
          >> serviceData[counter].y_coordinate;
    input >> temp;
    serviceData[counter].service = (SERVICE_TYPE) temp;
    input >> serviceData[counter].city_name >> serviceData[counter].calls;
    counter++;
  }

  input.close();

  return 0;
}

// Function that will find the nearest service by making use of the distance formula along
// with a for loop to test every single value in our array for the closest distance
int findNearestService(service *serviceData, int size, double userX, double userY) {
  bool findInitialValue = true;
  int nearestServiceIndex = 0, typeDefault = -1;

  nearestServiceIndex = compareValues(serviceData, size, userX, userY, findInitialValue, typeDefault);

  return nearestServiceIndex;
}

// Function that will find the nearest police department by making use of the distance formula
// and testing only police departments with a for loop to test every single value in our array
// for the closest distance
int findNearestPoliceDepartment(service *serviceData, int size, double userX, double userY) {
  bool findInitialValue = false;
  int nearestPoliceIndex, typePolice = 0;

  nearestPoliceIndex = compareValues(serviceData, size, userX, userY, findInitialValue, typePolice);

  return nearestPoliceIndex;
}

// Function that will find the nearest police department by making use of the distance formula
// and testing only hospitals with a for loop to test every single value in our array for the
// closest distance
int findNearestHospital(service *serviceData, int size, double userX, double userY) {
  bool initialValue = false;
  int nearestHospitalIndex, typeHospital = 1;

  nearestHospitalIndex = compareValues(serviceData, size, userX, userY, initialValue, typeHospital);

  return nearestHospitalIndex;
}

// Function that will find the nearest fire station by making use of the distance formula
// and testing only police departments with a for loop to test every single value in our array
// for the closest distance
int findNearestFireStation(service *serviceData, int size, double userX, double userY) {
  bool initialValue = false;
  int nearestFireStationIndex, typeFireStation = 2;

  nearestFireStationIndex = compareValues(serviceData, size, userX, userY, initialValue, typeFireStation);

  return nearestFireStationIndex;
}

// This function will be used for getting the nearest distance, which is referenced in every
// findNearest{SERVICE} function
int compareValues(service *serviceData, int size, double userX, double userY, bool initialValue, int type) {
  int serviceIndex;
  int counter = 0;

  // If statement will catch the boolean if it is coming from finding the nearest service, not
  // specifying the individual service
  if (initialValue)
    serviceIndex = counter;

  // We use this while loop to initialize our first found hospital as the nearest,
  // as it'll allow us to compare future police department distances to the first found
  while (!initialValue) {
    if (serviceData[counter].service == type) {
      serviceIndex = counter;
      initialValue = true;
    }
    counter++;
  }

  double nearestDistance = sqrt(pow((serviceData[serviceIndex].x_coordinate - userX),2) +
                                pow((serviceData[serviceIndex].y_coordinate - userY), 2));

  // We use our `compareDistance` with `nearestDistance` variables to keep track of the
  // nearest services available that pertain to the user's location
  for (int i = 1; i < (size - 1); i++) {
    // Only perform the service check if it is > type = -1, else compare every service
    if (type > -1) {
      int nearestCalls = serviceData[serviceIndex].calls;
      int compareCalls = serviceData[i].calls;

      if (serviceData[i].service == type) {
        double compareDistance = sqrt(pow((serviceData[i].x_coordinate - userX), 2) +
                                      pow((serviceData[i].y_coordinate - userY), 2));

        if (compareDistance < nearestDistance && compareCalls < nearestCalls) {
          nearestDistance = compareDistance;
          serviceIndex = i;
        }
      }
    } else {
      int nearestCalls = serviceData[serviceIndex].calls;
      int compareCalls = serviceData[i].calls;

      double compareDistance = sqrt(pow((serviceData[i].x_coordinate - userX), 2) +
                                    pow((serviceData[i].y_coordinate - userY), 2));

      if (compareDistance < nearestDistance && compareCalls < nearestCalls) {
        nearestDistance = compareDistance;
        serviceIndex = i;
      }
    }
  }

  return serviceIndex;
}

// This function is used for processing the output after a desired case is selected by the user
void output(service *serviceData, int index, double userX, double userY, string service) {
  cout << "The nearest " << service << " to your location " << "of X: " << userX << "," << endl
       << "Y: " << userY << " is in " << serviceData[index].city_name << " of Service ID "
       << serviceData[index].serviceID << " located" << endl << "at X: "
       << serviceData[index].x_coordinate << ", Y: " << serviceData[index].y_coordinate
       << " receiving " << data[index].calls << " calls per day." << endl;
}

// This function will sort our array in an increasing order depending on the service,
// using a selection sort to process it
void sortByService(service *serviceData, int size) {
  service temp;

  int minValue, minIndex;

  for (int start = 0; start < size - 1; start++) {
    minValue = serviceData[start].service;
    minIndex = start;
    for (int index = start + 1; index < size; index++) {
      if (serviceData[index].service < minValue) {
        minValue = serviceData[index].service;
        minIndex = index;
      }
    }
    temp = serviceData[minIndex];
    serviceData[minIndex] = serviceData[start];
    serviceData[start] = temp;
  }
}

// This function's purpose is to establish an output file stream and output all our data in our
// array to a text file in the same format we received it in ordered from least to greatest service
int outputList(service *serviceData, int size, string fileName) {
  ofstream outputFile;
  outputFile.open(fileName);

  if (!outputFile.is_open())
    return -1;

  for (int i = 0; i < (size - 1); i++) {
    outputFile << serviceData[i].serviceID << " ";
    outputFile << serviceData[i].x_coordinate << " ";
    outputFile << serviceData[i].y_coordinate << " ";
    outputFile << serviceData[i].service << " ";
    outputFile << serviceData[i].city_name << " ";
    outputFile << serviceData[i].calls << " ";
    outputFile << endl;
  }

  return 0;
}

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

enum COUNTRY{USA, CAN};

struct city {
  int id;
  double xCoordinate;
  double yCoordinate;
  COUNTRY cntry;
  string name;
}

city * citydata;

int countLines(string);
int readFile(string, city, int);
city findCityByID(city, int, int);

int main() {
  // city c1;
  // c1.id = 1;
  // c1.xCoordinate = 0.5;
  // c1.yCoordinate = 1.5;
  // c1.cntry = (COUNTRY)0;
  // c1.name = "Test, TX";
  // int dummy = 0;
  // c1.cntry = (COUNTRY)dummy;

  // ---------------------------

  string filename = "C:\\Temp\\cityInfo.txt";

  int counter = countLines(filename);

  if (counter <= 0)
    return -1;

  citydata = new city[counter];

  if (readFile(filename, citydata, counter) < 0)
    return -1;


  int city1ID;
  cin >> city1ID;

  city *city = findCityByID(citydata, counter, city1ID);

  if (city == nullptr)
    cout << "City ID was not found" << endl;

  return 0;
}

int countLines(string fileName) {
  ifstream input.open(filename);
  string buffer;
  int totalLines;

  if (!input.is_open())
    return -1;

  while (!input.eof()) {
    getline(cin, buffer);
    totalLines++;
  }

  input.close();

  return totalLines;
}

int readFile(string filename, city *cityData, int size) {
  ifstream input;
  int counter = 0;
  int dummy;
  input.open(filename.c_str());
  if (!input.is_open())
    return -1;

  while (!input.eof()) {
    input >> cityData[counter].id >> cityData[counter].xCoordinate
      >> cityData[counter].yCoordinate;
    input >> dummy;
    cityData[counter].cntry = (COUNTRY)dummy;
    getline(input, cityData[counter].name);
    counter++;
  }

  input.close();

  return 0;
}

city * findCityByID(city cityData[], int size, int key) {
  for (int i = 0; i < size; i++) {
    if (cityData[i].id == key) {
      return &cityData[i];
    }
  }
  return nullptr;
}

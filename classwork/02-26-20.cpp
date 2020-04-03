#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct {
  string firstName;
  string lastName;
  string major;
  double gpa;
} list[1000];

int main() {
  string headerName, headerMajor;
  double headerGpa;

  fstream input;
  input.open("fileLocation", in);

  if (!input.is_open())
    return 1;

  int counter = 0;

  while (!input.eof()) {
    input >> headerName;
    input >> list[counter].firstName;
    input >> list[counter].lastName;
    input >> headerMajor;
    input >> list[counter].major;
    input >> headerGpa;
    input >> list[counter].gpa;
    counter++;
  }

  return 0;
}

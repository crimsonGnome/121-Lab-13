// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include <iostream>
#include <vector>

#include "minimum.h"

using std::cin, std::cout, std::endl, std::vector;

// TODO: Include any necessary headers.

int main() {
  int size;
  std::cout << "How many elements? ";
  std::cin >> size;

  // TODO: Construct the vector and array.

  double array[size];
  vector<double> vect;
  double *arrayptr = array;

  // TODO: Prompt the user for the value of each element and populate the vector
  // and array.
  for (int i = 0; i < size; i++) {
    double temp;
    cout << "Element " << i << ": ";
    cin >> temp;

    // push values to array
    vect.push_back(temp);
    array[i] = temp;
  }
  // TODO: Call the IndexOfMin* functions using the vector or array as
  // appropriate, and display the output.
  cout << "Minimum index using vector: " << IndexOfMinWithVector(vect) << endl;
  cout << "Minimum index using array: " << IndexOfMinWithArray(array, size)
       << endl;
  cout << "Minimum index using pointer math: "
       << IndexOfMinWithPointer(arrayptr, size) << endl;
}

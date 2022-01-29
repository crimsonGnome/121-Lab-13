// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include "minimum.h"

#include <vector>

using std::vector;

int IndexOfMinWithVector(std::vector<double> input) {
  // First thing, check the size
  if (input.size() == 0) {
    return -1;
  }
  // set intial values to the first index
  double lowestvalue = input[0];
  int answer = 0;
  // Loop through to see lower value
  for (size_t i = 1; i < input.size(); i++) {
    if (input[i] < lowestvalue) {
      answer = i;
      lowestvalue = input[i];
    }
  }
  return answer;
}

int IndexOfMinWithArray(double input[], int size) {
  // First thing, check the size
  if (size == 0) {
    return -1;
  }
  // set intial values to the first index
  double lowestvalue = input[0];
  int answer = 0;
  // Loop through to see lower value
  for (int i = 1; i < size; i++) {
    if (input[i] < lowestvalue) {
      answer = i;
      lowestvalue = input[i];
    }
  }
  return answer;
}

int IndexOfMinWithPointer(double* input, int size) {
  // First thing, check the size
  if (size == 0) {
    return -1;
  }
  // set intial values to the first index
  double lowestvalue = *(input);
  int answer = 0;
  // Loop through to see lower value
  for (int i = 1; i < size; i++) {
    if (*(input + i) < lowestvalue) {
      answer = i;
      lowestvalue = *(input + i);
    }
  }
  return answer;
}

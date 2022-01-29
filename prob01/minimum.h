// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include <vector>

// Gets the index of the smallest element in the vector or returns -1 if the
// vector is empty.
int IndexOfMinWithVector(std::vector<double> input);

// Gets the index of the smallest element in the array or returns -1 if the size
// is 0.
int IndexOfMinWithArray(double input[], int size);

// Gets the index of the smallest element in the array using pointer arithmatic,
// or returns -1 if the size is 0.
int IndexOfMinWithPointer(double* input, int size);

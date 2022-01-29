// Name: Joseph Eggers
// CWID: 885939488
// Email: joseph.eggers@csu.fullerton.edu

#include <fstream>
#include <iostream>
#include <string>

#include "maze.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main() {
  // Gets a filename from the user.
  string filename;
  cout << "Enter the filename of your maze map: ";
  cin >> filename;

  Maze my_maze(filename);
  my_maze.Start();
  return 0;
}

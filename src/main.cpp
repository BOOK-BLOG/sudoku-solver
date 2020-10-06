#include <array>
#include <cstdio>
#include <iostream>
#include <vector>

#include "sudoku.h"

#define DEBUG

using namespace std;

#ifdef DEBUG
void debug() {
  Sudoku sudoku = Sudoku();

  cout << endl << "command_line_input()" << endl;
  sudoku.command_line_input();

  cout << endl << "print()" << endl;
  sudoku.print();

  cout << endl << "to_string()" << endl;
  cout << sudoku.to_string();

  cout << endl << "get(1, 5)" << endl;
  cout << sudoku.get(1, 5);

  cout << endl << "set(1, 5, -)" << endl;
  cout << sudoku.set(1, 5, '-');

  cout << endl << "print()" << endl;
  sudoku.print();
}
#endif

int main(int argc, char *argv[]) {
  std::ios::sync_with_stdio(
      false); // Disable Cin/Cout Sync to make the program faster
#ifdef DEBUG
  debug();
#endif

  return 0;
}

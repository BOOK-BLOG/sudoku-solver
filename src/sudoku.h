#ifndef SUDOKU_H
#define SUDOKU_H

#include <array>
#include <cstdio>
#include <fstream>
#include <iostream>

using namespace std;

class SudokuBlock {
public:
  char data;

  char get() { return data; }

  char set(char val) {
    int valInt = val - '0';
    if (0 <= valInt <= 9 || val == '-') {
      data = val;
      return data;
    }
    return '!';
  }
};

class Sudoku {
public:
  array<array<SudokuBlock, 9>, 9> data;

  Sudoku() {}

  Sudoku solve() { return Sudoku(); }

  // Utils
  const string thick_horizontal_divider =
      "|===================================|\n";
  const string horizontal_divider = "|-----------------------------------|\n";

  char get(int x, int y) { return data.at(x).at(y).get(); }

  void set(int x, int y, char val) { data.at(x).at(y).set(val); }

  void command_line_input() {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char input;
        cin >> input;
        data.at(i).at(j).set(input);
      }
    }
  }

  void read_file(string path) {
    ifstream file;
    file.open(path, ios::out | ios::in);
  }

  void print() { cout << to_string(); }

  string to_string() {
    string str = thick_horizontal_divider;

    for (int i = 0; i < 9; i++) {
      if (i != 0) {
        str = str + horizontal_divider;
      }

      for (int j = 0; j < 9; j++) {

        char current_item = data.at(i).at(j).get();

        if (j == 0) {
          str = str + "| ";
        }

        str = str + current_item;
        str = str + " | ";
      }
      str = str + "\n";
    }
    str = str + thick_horizontal_divider;

    return str;
  }
};

#endif

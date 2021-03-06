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
    bool available = false;
    int availableCount = 11;
    char availableVal[availableCount] = {'1', '2', '3', '4', '5', '6',
                                         '7', '8', '9', '-', '!'};

    for (int i = 0; i < availableCount; i++) {
      if (val == availableVal[i]) {
        available = true;
      }
    }

    if (available) {
      data = val;
    } else {
      data = '!';
    }

    return data;
  }
};

class Sudoku {
public:
  array<array<SudokuBlock, 9>, 9> data;

  Sudoku() {}

  const string thick_horizontal_divider =
      "|===================================|\n";
  const string horizontal_divider = "|-----------------------------------|\n";

  // Utils

  Sudoku solve() { return Sudoku(); }

  char get(int row, int col) { return data.at(row).at(col).get(); }

  array<SudokuBlock, 9> get_row(int index) {
    array<SudokuBlock, 9> row;
    for (int i = 0; i < 9; i++) {
      row.at(i).set(SudokuBlock().set(get(index, i)));
    }
    return row;
  }

  array<SudokuBlock, 9> get_col(int index) {
    array<SudokuBlock, 9> col;
    for (int i = 0; i < 9; i++) {
      col.at(i).set(SudokuBlock().set(get(i, index)));
    }
    return col;
  }

  char set(int row, int col, char val) {
    data.at(row).at(col).set(val);
    return data.at(row).at(col).get();
  }

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
    file.open(path, ios::in);

    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        char block;
        file >> block;
        data.at(i).at(j).set(block);
      }
    }

    file.close();
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

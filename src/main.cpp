#include <iostream>
#include <cstdio>
#include <vector>
#include <array>

#include "sudoku.h"

#define DEBUG

using namespace std;

#ifdef DEBUG
void debug()
{
    Sudoku sudoku = Sudoku();
    sudoku.command_line_input();
    sudoku.print();
    cout << endl << "to_string()" << endl;
    cout << sudoku.to_string();
}
#endif

int main(int argc, char* argv[])
{
    std::ios::sync_with_stdio(false); // Disable Cin/Cout Sync to make the program faster
    #ifdef DEBUG
    debug();
    #endif

    

    return 0;
}


#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iostream>
#include <cstdio>
#include <array>
#include <fstream>

using namespace std;

class Sudoku
{
public:
    array<array<char, 9>, 9> data;
    
    Sudoku()
    {
        
    }
    
    // Utils
    string thick_horizontal_divider = "|===================================|\n";
    string horizontal_divider = "|-----------------------------------|\n";

    void command_line_input()
    {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cin >> data.at(i).at(j);
            }
        }
    }

    void read_file(string path)
    {
        ifstream file;
        file.open(path, ios::out | ios::in);
        
    }

    void print()
    {
        cout << thick_horizontal_divider;
        for(int i = 0; i < 9; i++)
        {
            if (i != 0)
            {
                cout << horizontal_divider;
            }
            
            for(int j = 0; j < 9; j++)
            {

                if (j == 0)
                {
                    cout << "| ";
                }
                
                cout << data.at(i).at(j) << " | ";
            }
            cout << endl;
        }
        cout << thick_horizontal_divider;
    }

    string to_string()
    {
        string str = thick_horizontal_divider;

        for(int i = 0; i < 9; i++){
            if (i != 0)
            {
                str = str + horizontal_divider;
            }

            for(int j = 0; j < 9; j++){

                char current_item = data.at(i).at(j);

                if (j == 0)
                {
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
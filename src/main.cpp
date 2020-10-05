#include <iostream>
#include <cstdio>
#include <vector>
#include <array>

#define DEBUG

using namespace std;

class Sudoku
{
public:
    array<array<char, 9>, 9> data;
    
    Sudoku()
    {
        
    }
    
    // Utils
    void read()
    {
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cin >> data.at(i).at(j);
            }
        }
    }

    void print()
    {
        for(int i = 0; i < 9; i++)
        {
            cout << "-------------------------------------\n";
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
        cout << "-------------------------------------\n";
    }

    string to_string()
    {
        string str = "";

        for(int i = 0; i < 9; i++){
            str = str + "-------------------------------------\n";

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
        str = str + "-------------------------------------\n";

        return str;
    }
};

#ifdef DEBUG
void debug()
{
    Sudoku sudoku = Sudoku();
    sudoku.read();
    sudoku.print();
    cout << "to_string()" << endl;
    cout << sudoku.to_string();
}
#endif

int main(int argc, char* agrv[])
{
    std::ios::sync_with_stdio(false); // Disable Cin/Cout Sync to make the program faster
    #ifdef DEBUG
    debug();
    #endif
	return 0;
}


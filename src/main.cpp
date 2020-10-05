#include <iostream>
#include <cstdio>
#include <vector>
#include <array>

#define DEBUG

using namespace std;

class Sudoku{
public:
    array<array<int, 9>, 9> data;
    
    Sudoku(){
        
    }
    
    // Utils
    void read(){
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                cin >> data.at(i).at(j);
            }
        }
    }
    void print(){
        for(int i = 0; i < 9; i++){
            cout << "-------------------------------------\n";
            for(int j = 0; j < 9; j++){

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
};

#ifdef DEBUG
void debug(){
    Sudoku sudoku = Sudoku();
    sudoku.read();
    sudoku.print();
}
#endif

int main(int argc, char* agrv[]){
    std::ios::sync_with_stdio(false); // Disable Cin/Cout Sync to make the program faster
    #ifdef DEBUG
    debug();
    #endif
	return 0;
}


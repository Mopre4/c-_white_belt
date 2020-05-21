#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
int main(){
    ifstream input("input.txt");
    int row, column, value;
    if(input){
        input >> row;
        input.ignore(1);
        input >> column;
        for(int i = 0  ; i < row; i++){
            for(int j = 0; j < column; j++){
                input >> value;
                cout << setw(10) << value;
                if( j != column -1) {
                    input.ignore(1);
                    cout << " ";
                }

            }
            if (i != row-1) {
                cout << endl;
            }
        }


    }
    return 0;
}
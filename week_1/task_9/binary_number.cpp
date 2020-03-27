#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    int remainder;
    vector <int> binary_number;
    while (N > 0){
        remainder = N % 2;
        binary_number.push_back(remainder);
        N = N / 2;
    }
    for(int i = binary_number.size()-1; i >= 0; --i){
        cout << binary_number[i];
    }
    return 0;
}

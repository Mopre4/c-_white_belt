#include <iostream>
#include <vector>
#include "algorithm"

using namespace std;

void Print_numbers(vector<int> &numbers){
    for(auto &number: numbers){
        cout << number << " ";
    }
}
int main(){
    int N;
    cin >> N;
    vector <int> numbers;
    for(int i = 0; i < N; ++i){
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    sort(begin(numbers), end(numbers),[](int x, int y){
        return abs(x) < abs(y);
    });

    Print_numbers(numbers);


    return 0;
}
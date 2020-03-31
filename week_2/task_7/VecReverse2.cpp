#include "iostream"
#include "vector"

using namespace std;

void Reverse(vector <int> &v){
    int size = v.size();
    for(int i =0; i < size/2; ++i){
        int tmp = v[i];
        v[i] = v[size - 1 - i];
        v[size-1 - i] = tmp;
    }

}

int main(){
    vector<int> numbers = {1, 5, 3, 4, 2};
    Reverse(numbers);
    for(auto &x: numbers){
        cout << x << " ";
    }

    return 0;
}
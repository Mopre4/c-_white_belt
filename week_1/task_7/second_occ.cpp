#include <iostream>

using namespace std;

int main(){
    int count = 0;
    string str;
    cin >> str;
    for(int i = 0; i < str.size(); ++i){
        if (str[i] == 'f'){
           ++count;
           if (count == 2){
               cout << i << endl;
               break;
           }
        }
    }
    if (count == 1){
        cout << -1 << endl;
    } else if (count == 0) {
        cout << -2 << endl;
    }

    return 0;
}

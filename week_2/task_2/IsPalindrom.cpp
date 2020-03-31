#include <iostream>
using namespace std;
bool IsPalindrom(string &str){
    int size = str.size()-1; // т.к индекс с нуля.
    for(size_t i = 0; i != str.size()/2; i++){
        if (str[i] != str[size-i]){
            return false;
        }
    }
    return true;
}
int main(){
    string str;
    cin >> str;
    if (IsPalindrom(str)){
        cout << "true" << endl;
    } else cout << "false" << endl;
    return 0;
}

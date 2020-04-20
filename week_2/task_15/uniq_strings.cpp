#include <iostream>
#include "set"

using namespace std;
int main(){
    int n;
    string str;
    cin >> n;
    set<string> unique_strings;
    for(int i = 0; i < n ; ++i){
        cin >> str;
        unique_strings.insert(str);
    }
    cout <<unique_strings.size() <<endl;
    return 0;
}
#include "iostream"
#include "map"
using namespace std;

map<char,int> BuildCharCounters(string word){
    map<char,int> m;
    for(auto &symbol : word){
        ++m[symbol];
    }
    return m;
}

int main(){
    int N;
    string first_word, second_word;
    cin >> N;
    for(size_t i = 0; i  < N; ++i){
        cin >> first_word >> second_word;
        if (BuildCharCounters(first_word) == BuildCharCounters(second_word)){
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
    return 0;
}
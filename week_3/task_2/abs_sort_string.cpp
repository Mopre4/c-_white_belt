#include <iostream>
#include <vector>
#include "algorithm"

using namespace std;

int main(){
    int N;
    vector<string> strings;
    cin >> N;
    string str;
    for(auto i = 0; i < N; ++i){
        cin >> str;
        strings.push_back(str);
    }
    sort(begin(strings), end(strings), [](string left, string right){
        string first_word;
        string second_word;

        for(auto &letter: left){
            first_word += tolower(letter);
        }
        for(auto &letter: right){
            second_word += tolower(letter);
        }
        return second_word > first_word;
    });

    for(const auto &word : strings){
        cout << word << " ";
    }
    return 0;
}
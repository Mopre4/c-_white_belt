#include <iostream>
#include <vector>
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

vector <string> PalindromFilter(vector <string> &words, int minLength){
    vector <string> Palindroms;
    for(auto &word : words){
        if(IsPalindrom(word) && word.size() >= minLength){
            Palindroms.push_back(word);
        }
    }
    return Palindroms;
}


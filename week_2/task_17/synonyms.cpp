#include <iostream>
#include "set"
#include "map"
using namespace std;
int main(){
   map <string, set<string>>synonyms; // слово и его синонимы
   int q;
   string request;
   cin >> q;
   for(int i = 0; i < q; ++i){
       cin >> request;
       if (request == "ADD"){
           string syn1, syn2;
           cin >> syn1 >> syn2;
           synonyms[syn1].insert(syn2); // если есть - добавить, если нет - создать.
           synonyms[syn2].insert(syn1);
       } else if (request == "COUNT"){
           string word;
           cin >> word;
           if(synonyms.count(word) == 0){
               cout << 0 << endl;
           } else cout << synonyms[word].size() << endl;
       } else if (request == "CHECK"){
           string word1, word2;
           cin >> word1 >> word2;
           if (synonyms[word1].count(word2)){
               cout << "YES" << endl;
           } else cout << "NO"<< endl;
       }
   }
   return 0;
}
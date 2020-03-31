#include "iostream"
#include <vector>

using namespace std;

void MoveStrings(vector <string> &source, vector<string> &destination){
  for(auto &item : source){
      destination.push_back(item);
  }
  source.clear();
}

int main(){
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);

    for (auto &item : source){
        cout << item <<endl;
    }

    for(auto &item : destination){
        cout << item << " ";
    }
    return 0;
}
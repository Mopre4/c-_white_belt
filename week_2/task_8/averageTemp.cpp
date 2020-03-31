#include "iostream"
#include "vector"

using namespace std;


int main(){
    int n, t, average, sum;
    cin >> n;
    vector<int> temperatures;
    for(int i = 0; i < n; i++){
        cin >> t;
        temperatures.push_back(t);
        sum +=t;
    }
    average = sum / n;
    vector <int> days;
    for(int i = 0; i < temperatures.size();++i){
        if (temperatures[i] > average){
            days.push_back(i);
        }
    }
    cout << days.size() << endl;
    for(auto &day :days){
        cout << day << " ";
    }
    return 0;
}
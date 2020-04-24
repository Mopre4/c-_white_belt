#include <iostream>
#include <map>
#include <set>

using namespace std;
int main(){
    int q;
    cin >> q;
    map <set<string>, int> stops;
    set<string> stops_name;
    for(int i = 0; i < q; ++i){
        string stop;
        int num_stop;
        cin >> num_stop;
        for(int j = 0; j < num_stop; ++j){
            cin >> stop;
            stops_name.insert(stop);
        }
        if(stops.count(stops_name)){
            cout << "Already exists for " <<
                 stops[stops_name] << endl;
        } else {
            int new_size = stops.size()+1;
            stops[stops_name] = new_size;
            cout << "New bus " << new_size <<endl;
        }
        stops_name.clear();
    }
    return 0;
}
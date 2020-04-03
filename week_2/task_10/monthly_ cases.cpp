#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
int main(){
    vector<int> day_per_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int current_month = 0;
    vector<vector<string>> businesses(day_per_month[current_month]+1);
    int q;
    string s;
    cin >> q;
    for(int i = 0; i < q; ++i){
        cin >> s;
        if (s=="ADD"){
            int day;
            string business;
            cin >> day >> business;
            businesses[day].push_back(business);
        }

        if (s=="NEXT") {
            int early_month = current_month;
            ++current_month;

            if (current_month == 12) {
                current_month = 0;
            }

            int days_previous_month = day_per_month[early_month];
            int days_current_month = day_per_month[current_month];

            if (day_per_month[current_month] >= day_per_month[early_month]) {
                businesses.resize(day_per_month[current_month] + 1);
            } else
                for (days_previous_month;
                     days_previous_month != days_current_month;
                     days_previous_month--) {
                    businesses[days_current_month].
                    insert(end(businesses[days_current_month]),
                            begin(businesses[days_previous_month]),
                            end(businesses[days_previous_month]));
                }
                businesses.resize(day_per_month[current_month]+1);
        }
        if (s == "DUMP"){
            int day;
            cin >> day;
            cout << businesses[day].size() <<" ";
            for(auto &item : businesses[day]){
                cout << item << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
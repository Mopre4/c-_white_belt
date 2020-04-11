#include "iostream"
#include "string"
#include "map"
using namespace std;

int main(){
    int q;
    string request;
    string country, capital;
    cin >> q;
    map <string, string> country_capital;

    for(int i = 0 ; i < q; i++) {
       cin >> request;

       if(request == "CHANGE_CAPITAL"){
           cin >> country >> capital;
           if (country_capital.count(country) == 0){ // если страны раньше не существовало
                country_capital[country] = capital;
                cout << "Introduce new country " << country
                     << " with capital " << capital << endl;
           } else {
               if (capital == country_capital[country]){
                   cout << "Country " << country << " hasn't changed its capital" << endl;
               } else {
                   cout << "Country " <<  country << " has changed its capital from "
                   << country_capital[country] << " to " << capital  << endl;
                   country_capital[country] = capital;
               }
           }
       }
       if (request == "RENAME"){
           string old_country_name, new_country_name;
           cin >> old_country_name >> new_country_name;

           if(new_country_name == old_country_name ||
              country_capital.count(old_country_name) == 0 ||
              country_capital.count(new_country_name) == 1){
               cout << "Incorrect rename, skip " << endl;
           } else {
               cout << "Country " << old_country_name << " with capital "
                    << country_capital[old_country_name]<< " has been renamed to " << new_country_name << endl;
               country_capital[new_country_name] = country_capital[old_country_name];
               country_capital.erase(old_country_name);
           }
       }
       if (request == "ABOUT"){
        cin >> country;
        if(country_capital.count(country) == 0){
            cout << "Country " << country << " doesn't exist" << endl;
        } else
            cout << "Country " << country << " has capital " << country_capital[country] << endl;
       }
       if (request == "DUMP"){
           if(country_capital.empty()){
               cout <<"There are no countries in the world " << endl;
           } else
               for(auto &country : country_capital){
                   cout << country.first << "/" << country.second << " ";
               }
       }
    }
    return 0;
}
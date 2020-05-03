#include "iostream"
#include "map"
#include "algorithm"
using namespace std;
class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        year_name[year] = first_name;
    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        year_surname[year] = last_name;
    }
    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        //map по дефолту сортирует ключи по возрастанию.
        int date_current_name = 0;
        int date_current_surname = 0;

        for(auto &years : year_name){
            if (year >= years.first){
                date_current_name = years.first;
            }
        }
        for(auto & years : year_surname){
            if(year >= years.first){
                date_current_surname = years.first;
            }
        }
        if (date_current_name == 0 && date_current_surname == 0){
            return "Incognito";
        }else if(date_current_name == 0  && date_current_surname != 0){
            return year_surname[date_current_surname] +
                " with unknown first name";
        }else if(date_current_name != 0 && date_current_surname == 0){
            return year_name[date_current_name] +
            " with unknown last name";
        } else{
            return year_name[date_current_name] + " " +
            year_surname[date_current_surname];
        }
    }
private:
    // приватные поля
    map<int, string> year_name;
    map<int, string> year_surname;

};
int main() {
    Person person;
    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }
    return 0;
}

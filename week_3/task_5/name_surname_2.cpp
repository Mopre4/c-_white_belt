#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
	string name;  // изначально имя неизвестно

	// перебираем всю историю по возрастанию ключа словаря, то есть в хронологическом порядке
	for (const auto& item : names) {
		// если очередной год не больше данного, обновляем имя
		if (item.first <= year) {
			name = item.second;
		}
		else {
			// иначе пора остановиться, так как эта запись и все последующие относятся к будущему
			break;
		}
	}

	return name;
}
// получаем вектор с именами 
vector<string> FindHistory( const map <int, string> &names, const int year) {
	vector<string>full_names;
	string current_name = "";
	for (const auto& name : names) { // избегаем повторов
		if (name.first <= year && name.second != current_name) { //если год меньше переданного и имя не равно текущему пушбэчим
			full_names.push_back(name.second);
		}
		current_name = name.second;
	}
	reverse(full_names.begin(), full_names.end());
	return full_names;
}

string Build_Full_Name_with_History(const vector<string> & full_names) {
	string name_with_history = "";
	if (full_names.empty()) {
		return ""; // или name_with_history;
	}
	else {
		name_with_history = full_names[0];
		if (full_names.size() > 1) {
			name_with_history += " (";
			for (int i = 1; i < full_names.size(); i++) {
				name_with_history += full_names[i];
				if (i != full_names.size()-1) {
					name_with_history += ", ";
				}
			} name_with_history += ")";
		}
	} return name_with_history;
}

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		first_names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		last_names[year] = last_name;
	}
	string GetFullName(int year) {
		// получаем имя и фамилию по состоянию на год year
		const string first_name = FindNameByYear(first_names, year);
		const string last_name = FindNameByYear(last_names, year);

		// если и имя, и фамилия неизвестны
		if (first_name.empty() && last_name.empty()) {
			return "Incognito";

			// если неизвестно только имя
		}
		else if (first_name.empty()) {
			return last_name + " with unknown first name";

			// если неизвестна только фамилия
		}
		else if (last_name.empty()) {
			return first_name + " with unknown last name";

			// если известны и имя, и фамилия
		}
		else {
			return first_name + " " + last_name;
		}
	}
	string GetFullNameWithHistory(int year) {  // не нужная функция, но ребятам из яндекса именно так нужно.
		// получить все имена и фамилии по состоянию на конец года year

		string Full_first_names = Build_Full_Name_with_History(FindHistory(first_names, year));
		string Full_last_names = Build_Full_Name_with_History(FindHistory(last_names, year));

		if (Full_first_names.empty() && Full_last_names.empty()) {
			return "Incognito";
			// если неизвестно только имя
		}
		else if (Full_first_names.empty()) {
			return Full_last_names + " with unknown first name";

			// если неизвестна только фамилия
		}
		else if (Full_last_names.empty()) {
			return Full_first_names + " with unknown last name";

			// если известны и имя, и фамилия
		}
		else {
			return Full_first_names + " " + Full_last_names;
		}

	}

private:
	map<int, string> first_names;
	map<int, string> last_names;
};
int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;

	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;

	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;

	return 0;
}

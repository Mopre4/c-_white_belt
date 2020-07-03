#include "iostream"
#include "map"
#include "set"
#include "sstream"
#include "vector"
#include <iomanip>

using namespace std;

class Date {
public:
	Date(int new_year, int new_month, int new_day) {
		year = new_year;
		if (new_month < 1 || new_month > 12) {
			throw runtime_error("Month value is invalid: " + to_string(new_month));
		}
		else month = new_month;

		if (new_day < 1 || new_day > 31) {
			throw runtime_error("Day value is invalid: " + to_string(new_day));
		}
		else day = new_day;
	}
	int GetYear() const {
		return year;
	};
	int GetMonth() const {
		return month;
	};
	int GetDay() const {
		return day;
	};

private:
	int year;
	int month;
	int day;
};

bool operator < (const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear()) {
		if (lhs.GetMonth() == rhs.GetMonth()) {
			if (lhs.GetDay() < rhs.GetDay()) {
				return 1;
			}
			else return 0;
		}
		else if (lhs.GetMonth() < rhs.GetMonth()) {
			return 1;
		}
		else return 0;
	}
	return lhs.GetYear() < rhs.GetYear();
}

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.GetYear() <<
		"-" << setw(2) << setfill('0') << date.GetMonth() <<
		"-" << setw(2) << setfill('0') << date.GetDay();
	return stream;
}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
	//	cout << date.GetYear() << " " << date.GetMonth() << " " << date.GetDay() << endl;
		//cout << event << endl;
		date_event[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event) {
		if (date_event.count(date) > 0 && date_event[date].count(event) > 0) { //если такая дата есть и в ней есть собыите
			date_event[date].erase(event);
			return 1;
		}
		else return 0;
	} 

	int  DeleteDate(const Date& date) {
		int count_events = date_event[date].size();
		date_event.erase(date);
		return count_events;
	};

	void Find(const Date& date) const {
		if (date_event.count(date) > 0) {
			set <string> events = date_event.at(date);
			for (auto& e : events) {
				cout << e << endl;
			}
		}
	};

	void Print() const {
		for (auto& d : date_event) {
			for (auto& e : d.second) {
				cout << d.first << " ";
				cout << e;
				cout << endl;
			}
		}
	};

private:
	map <Date, set<string>> date_event;
};

Date ParceDate(const string& date) {
	stringstream ss(date);
	int year, month, day;
	ss >> year;
	if (ss.peek() != '-') {
		throw runtime_error("Wrong date format: " + date);
	}
	ss.ignore();
	ss >> month;
	if (ss.peek() != '-') {
		throw runtime_error("Wrong date format: " + date);
	}
	ss.ignore();
	//ss >> day;
	if (!(ss >> day)) { //если в поток не считалось вернет 0 
		throw runtime_error("Wrong date format: " + date);
	}
	if (ss.peek()!= EOF){
		throw runtime_error("Wrong date format: " + date);
	}
	return Date(year, month, day);
}
int main() {
	Database db;
	string command;
	try {
		while (getline(cin, command)) {
			stringstream ss(command);
			ss >> command;
			if (command.empty()) { //пустые строки следует игнорировать
				continue; 
			}
			else if (command == "Add") {
				string date, event;
				ss >> date >> event;
				if (event.empty()) { //пустое событие не обрабатывается
					continue;
				}
				Date d = ParceDate(date);
				db.AddEvent(d, event);
			}
			else if (command == "Del") {
				string date, event;
				ss >> date; //считали дату
				Date d = ParceDate(date);
				if (ss.peek() != EOF) {//если след. символ не конец строки
					ss >> event; //считали событие
					if (db.DeleteEvent(d, event)) {
						cout << "Deleted successfully" << endl;
					}
					else cout << "Event not found" << endl; ;
				}else {  // если следующий символ после даты конец строки значит нужно удалить все события даты
					cout << "Deleted " << db.DeleteDate(d) << " events" << endl;
				}
			}
			else if (command == "Find") {
				string date;
				ss >> date;
				Date d = ParceDate(date);
				db.Find(d);
			}
			else if (command == "Print") {
				db.Print();
			}

			else {
				throw runtime_error("Unknown command: " + command);
			}
		}
	}
	catch (exception & ex) {
		cout << ex.what() << endl;
	}

	return 0;
}
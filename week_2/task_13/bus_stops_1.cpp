#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main()
{
	int q;
	cin >> q;
	string request,stop,bus;
	map <string, vector<string>> bus_to_stop;
	map <string, vector<string>> stop_to_bus;
	for (int i = 0; i < q; i++) {
		cin >> request;
		if (request == "NEW_BUS") {
			int stop_count;
			cin >> bus >> stop_count;
			for (auto j = 0; j < stop_count; j++) {
				cin >> stop;
				bus_to_stop[bus].push_back(stop);
				stop_to_bus[stop].push_back(bus);
			}
		}
		if (request == "BUSES_FOR_STOP") {
			cin >> stop;
			if (stop_to_bus.count(stop) == 0) {
				cout << "No stop" << endl;
			}
			else {
				for (auto &bus : stop_to_bus[stop]) {
						cout << bus << " ";
				}
				cout << endl;
			}
		}
		if (request == "STOPS_FOR_BUS") {
			cin >> bus;
			if (bus_to_stop.count(bus)==0) {
				cout << "No bus" << endl;
			}
			else{
				for (auto& stop : bus_to_stop[bus]) {
					cout <<"Stop "<< stop << ": ";

					if (stop_to_bus[stop].size() == 1) {
						cout << "no interchange ";
					}
					for (auto &buses : stop_to_bus[stop]) {
						if (buses != bus) {
							cout << buses << " ";
						} 
					}
					cout << endl;
				}
			}
		}
		if (request == "ALL_BUSES") {
			if (bus_to_stop.empty()) {
				cout << "No buses " << endl;;
			} else 
			for (auto &bus : bus_to_stop) {
				cout << "Bus " << bus.first << ": ";
				for (auto& buses : bus.second) {
					cout << buses << " ";
				}
				cout << endl;
			}
		}
	}
	return 0;
}

#include <iostream>
#include <fstream>
using namespace std;

int main() {
	// stores the days so the program knows what day is next
	string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	string line, firstDay;
	int day;

	ifstream file_days;
	file_days.open(".tree_FINAL.txt");

	// quits the program if the file didn't open
	if(!file_days.is_open()) {
		cout << "No .tree_FINAL.txt\n";
		return 1;
	}

	getline(file_days, line);

	// have to add a period
	line = "." + line;

	ifstream first;
	first.open(line.c_str());

	getline(first, firstDay);

	first.close();

	for(int i=0; i<7; i++) {
		if(firstDay == days[i]) {
			day = i;
			break;
		}
	}

	ofstream output;
	while(!file_days.eof()) {
		getline(file_days, line);

		line = "." + line;
		if(line == ".") {
			return 3;
		}

		output.open(line.c_str());

		if(output.is_open()) {
			if(day < 7) {
				day++;
			} else {
				day = 0;
			}

			output << days[day];
		} else {
			cout << line << " did not open.\n";
			return 1;
		}

		output.close();
	}

	file_days.close();
	return 0;
}

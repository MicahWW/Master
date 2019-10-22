#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// arguments should be passed as "a.out previousDay dayOfWeek##"
int main(int argc, char* argv[]) {
	// stores the days so the program knows what day is next
	string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	string line, startDay;
	int day;

	if(argc == 2) {
		startDay = argv[1];

		// find the day of week ##
		for(int i=0; i<7; i++) {
			if(startDay == days[i]) {
				day = i;
				break;
			}
		}
	} else if(argc == 3) {
		startDay = argv[1];
		day = atoi(argv[2]);
	// program must have at least the start day passed
	} else {
		cout << "ERROR: No start day agrument passed.\n";
		return 1;
	}

	// holds text of all the differnt days within that month ex: 01.day
	ifstream file_days;
	file_days.open(".tree_FINAL.txt");

	// quits the program if the file didn't open
	if(!file_days.is_open()) {
		cout << "No file '.tree_FINAL.txt\n";
		return 1;
	}


	ofstream output;
	while(!file_days.eof()) {
		getline(file_days, line);

		line = "." + line;

		// I think this means that there is no more files
		if(line == ".") {
			return 3;
		}

		output.open(line.c_str());

		// advances to the next day
		if(output.is_open()) {
			if(day < 6) {
				day++;
			// if day >= 6 then the week starts over
			} else {
				day = 0;
			}

			// outputs to the selected day
			output << days[day];
		// the day file did not open
		// not sure if this can happen with before safeguards unless
		// operating error
		} else {
			cout << line << " did not open.\n";
			return 1;
		}

		output.close();
	}

	file_days.close();

	cout << days[day];

	return 0;
}

#include <iostream>
#include <string>

using namespace std;

string userDate(string year, int month, int day);
string userDateNextYear(string year, int month, int day);

int main() {
	string userYear;
	string nextYear;

	string **year = new string*[24];

	// January
	year[0] = new string[31];
	year[12] = new string[31];
	// February
	year[1] = new string[28];
	year[13] = new string[28];
	// March
	year[2] = new string[31];
	year[14] = new string[31];
	// April
	year[3] = new string[30];
	year[15] = new string[30];
	// May
	year[4] = new string[31];
	year[16] = new string[31];
	// June
	year[5] = new string[30];
	year[17] = new string[30];
	// July
	year[6] = new string[31];
	year[18] = new string[31];
	// August
	year[7] = new string[31];
	year[19] = new string[31];
	// September
	year[8] = new string[30];
	year[20] = new string[30];
	// October
	year[9] = new string[31];
	year[21] = new string[31];
	// November
	year[10] = new string[30];
	year[22] = new string[30];
	// December
	year[11] = new string[31];
	year[23] = new string[31];


	// finds the current working year
	cout << "What year? ";
	cin >> userYear;

	// finds the next working year for when it reaches the end of december
	nextYear = to_string(stoi(userYear) + 1);

	// January
	for(int i=0; i<31; i++) {
		if(i < 9) {
			year[0][i] = userYear + "010" + to_string(i+1);
			year[12][i] = nextYear + "010" + to_string(i+1);
		} else {
			year[0][i] = userYear + "01" + to_string(i+1);
			year[12][i] = nextYear + "01" + to_string(i+1);
		}
	}

	// February
	for(int i=0; i<28; i++) {
		if(i < 9) {
			year[1][i] = userYear + "020" + to_string(i+1);
			year[13][i] = nextYear + "020" + to_string(i+1);
		} else {
			year[1][i] = userYear + "02" + to_string(i+1);
			year[13][i] = nextYear + "02" + to_string(i+1);
		}
	}

	// March
	for(int i=0; i<31; i++) {
		if(i < 9) {
			year[2][i] = userYear + "030" + to_string(i+1);
			year[14][i] = nextYear + "030" + to_string(i+1);
		} else {
			year[2][i] = userYear + "03" + to_string(i+1);
			year[14][i] = nextYear + "03" + to_string(i+1);
		}
	}

	// April
	for(int i=0; i<30; i++) {
		if(i < 9) {
			year[3][i] = userYear + "040" + to_string(i+1);
			year[15][i] = nextYear + "040" + to_string(i+1);
		} else {
			year[3][i] = userYear + "04" + to_string(i+1);
			year[15][i] = nextYear + "04" + to_string(i+1);
		}
	}

	// May
	for(int i=0; i<31; i++) {
		if(i < 9) {
			year[4][i] = userYear + "050" + to_string(i+1);
			year[16][i] = nextYear + "050" + to_string(i+1);
		} else {
			year[4][i] = userYear + "05" + to_string(i+1);
			year[16][i] = nextYear + "05" + to_string(i+1);
		}
	}

	// June
	for(int i=0; i<30; i++) {
		if(i < 9) {
			year[6][i] = userYear + "060" + to_string(i+1);
			year[17][i] = nextYear + "060" + to_string(i+1);
		} else {
			year[5][i] = userYear + "06" + to_string(i+1);
			year[17][i] = nextYear + "06" + to_string(i+1);
		}
	}

	// July
	for(int i=0; i<31; i++) {
		if(i < 9) {
			year[6][i] = userYear + "070" + to_string(i+1);
			year[18][i] = nextYear + "070" + to_string(i+1);
		} else {
			year[6][i] = userYear + "07" + to_string(i+1);
			year[18][i] = nextYear + "07" + to_string(i+1);
		}
	}

	// August
	for(int i=0; i<31; i++) {
		if(i < 9) {
			year[7][i] = userYear + "080" + to_string(i+1);
			year[19][i] = nextYear + "080" + to_string(i+1);
		} else {
			year[7][i] = userYear + "08" + to_string(i+1);
			year[19][i] = nextYear + "08" + to_string(i+1);
		}
	}

	// September
	for(int i=0; i<30; i++) {
		if(i < 9) {
			year[8][i] = userYear + "090" + to_string(i+1);
			year[20][i] = nextYear + "090" + to_string(i+1);
		} else {
			year[8][i] = userYear + "09" + to_string(i+1);
			year[20][i] = nextYear + "09" + to_string(i+1);
		}
	}

	// October
	for(int i=0; i<31; i++) {
		if(i < 9) {
			year[9][i] = userYear + "100" + to_string(i+1);
			year[21][i] = nextYear + "100" + to_string(i+1);
		} else {
			year[9][i] = userYear + "10" + to_string(i+1);
			year[21][i] = nextYear + "10" + to_string(i+1);
		}
	}

	// November
	for(int i=0; i<30; i++) {
		if(i < 9) {
			year[10][i] = userYear + "110" + to_string(i+1);
			year[22][i] = nextYear + "110" + to_string(i+1);
		} else {
			year[10][i] = userYear + "11" + to_string(i+1);
			year[22][i] = nextYear + "11" + to_string(i+1);
		}
	}

	// December
	for(int i=0; i<31; i++) {
		if(i < 9) {
			year[11][i] = userYear + "120" + to_string(i+1);
			year[23][i] = nextYear + "120" + to_string(i+1);
		} else {
			year[11][i] = userYear + "12" + to_string(i+1);
			year[23][i] = nextYear + "12" + to_string(i+1);
		}
	}


	int month, day, count = 0;

	cout << "Start month? ";
	cin >> month;
	month--;

	cout << "Start day? ";
	cin >> day;
	day--;

	cout << "\n\nStart Date:\n";
	cout << "http://www.espn.com/nhl/schedule/_/date/" << year[month][day] << endl;

	// 38 beause that should get through the season
	for(int i=0; i<38; i++) {
		for(int j=0; j<7; j++) {
			day++;
			//cout << month << "\t" << day << endl;
			if(year[month][day] != userDate(userYear, month, day) && year[month][day] != userDateNextYear(nextYear, month, day)) {
				//cout << "if\n";
				month++;
				day = 0;
			}
			//cout << "expected " << year[month][day] << endl;
		}

		// I know the key word colloring on this looks weird but it works trust me
		cout << i+2 << ":\nhttp://www.espn.com/nhl/schedule/_/date/" << year[month][day] << endl;
	}

	return 0;
}


string userDate(string year, int month, int day) {
	string output = year;

	if(month < 9) {
		output += "0" + to_string(month + 1);
	} else {
		output += to_string(month + 1);
	}

	if(day < 9) {
		output += "0" + to_string(day + 1);
	} else {
		output += to_string(day + 1);
	}

	return output;
}

string userDateNextYear(string year, int month, int day) {
	string output = year;

	// moths for the new year continue counting makeing them go past 12
	month = month - 12;

	if(month < 9) {
		output += "0" + to_string(month + 1);
	} else {
		output += to_string(month + 1);
	}

	if(day < 9) {
		output += "0" + to_string(day + 1);
	} else {
		output += to_string(day + 1);
	}

	//cout << output << "\t\toutput\n";
	return output;
}

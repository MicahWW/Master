#include <iostream>
#include <fstream>

using namespace std;

void print_day(int, int);

int main(int argc, char* argv[]) {
	ifstream first_day;
	first_day.open("01.day");

	string day_one_day_of_week;
	int day_of_week_num;

	if(first_day.is_open()) {
		getline(first_day, day_one_day_of_week);

	} else {
		cout << "ERROR:: 01.day did not open";
		return 1;
	}

	print_day(1, 1);

	return 0;
}

void print_day(int number, int day_of_week) {
	cout << "___________________________________________________________________________________________________" << endl;
	cout << "|             |             |             |             |             |             |             |" << endl;
	cout << "| " << number << "           |" << endl;
	cout << "|             |" << endl;
	cout << "|             |" << endl;
	cout << "|             |" << endl;

}

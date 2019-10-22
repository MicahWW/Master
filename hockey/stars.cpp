#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream scores;
	scores.open("scores.txt");

	string line;
	int search_team_position;
	int start_team_other_position, end_team_other_position;
	int choice;

	// if open
	if(scores.is_open()) {

		do {
		cout << "Please select what you want to do:" << endl;
		cout << "0: Games in order" << endl;
		cout << "1: Seprate home and away" << endl;
		cin >> choice;
		} while(!(choice == 0 || choice == 1));

		// while in the body of the file
		while(!scores.eof()) {
			// grabes line
			getline(scores, line);

			search_team_position = line.find("dallas-stars");

			// if the string isn't found then it returns string::npos
			if(search_team_position != string::npos) {
				// if at the begining then it means it is a home game
				if(search_team_position == 0) {
					// finds the position of the away team
					start_team_other_position = line.find(",") + 1;
					end_team_other_position = line.find(",", start_team_other_position);

					cout << "Stars at home against ";
					cout << line.substr(start_team_other_position, (end_team_other_position-start_team_other_position)) << endl;
				} else {
					start_team_other_position = 0;
					end_team_other_position = line.find(",");

					cout << "Stars on road against ";
					cout << line.substr(start_team_other_position, (end_team_other_position-start_team_other_position)) << endl;
				}
			}

		}
	} else {
		cout << "File did not open.\n";
		return 1;
	}

	return 0;
}

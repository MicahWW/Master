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

	if(scores.is_open()) {
		while(!scores.eof()) {
			getline(scores, line);

			search_team_position = line.find("dallas-stars");

			if(search_team_position != string::npos) {
				// if at the begining then it means it is a home game
				if(search_team_position == 0) {
					// finds the position of the away team
					start_team_other_position = line.find(",") + 1;
					end_team_other_position = line.find(",", start_team_other_position);

					cout << line.substr(start_team_other_position, (end_team_other_position-start_team_other_position));
					cout << 
				} else {
					start_team_other_position = 0;
					end_team_other_position = line.find(",");

					cout << line.substr(start_team_other_position, (end_team_other_position-start_team_other_position));
			}

		}
	} else {
		cout << "File did not open.\n";
		return 1;
	}

	return 0;
}

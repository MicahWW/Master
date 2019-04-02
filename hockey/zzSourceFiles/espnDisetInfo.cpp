#include <iostream>
#include <fstream>
#include <string>
#include <locale>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream games;
	games.open(argv[1]);

	// have to have this for tolower, I have no idea what it does
	locale loc;

	string line;
	string away, home, winner;
	string abr_away, abr_home;
	int score_away, score_home = -1;

	bool found = false;

	int start;

	bool overTime, shootOut;
	string gameHolder;

	if(games.is_open()) {
		while(!games.eof()) {
			getline(games, line);

			// once this line is found the next contains the away team
			if(line == "<span class=\"Table2__Team away\">") {
				getline(games, line);
				// remove everything up to the abr
				line = line.substr(96, line.length() - 96);

				// grab abr
				abr_away = line.substr(0, 3);

				// some of the abrs are only 2 with the next character beting '/'
				// depending on length it will alter the numbers of where to start
				if(abr_away[2] == '/') {
					// grabs the team name removing the abr and '">' at the end
					away = line.substr(3, line.length() - 5);
					// removes the '/'
					abr_away = abr_away.substr(0, 2);
				} else {
					// grabs the team name removing the abr and '">' at the end
					away = line.substr(4, line.length() - 6);
				}

		///////////////////////////////////////////////////////////////

				// goes through the lines inbetween away team and home
				for(int i=0; i<20; i++) {
					getline(games, line);
				}

				// remove everything up to the abr
				line = line.substr(96, line.length() - 96);

				// grab abr
				abr_home = line.substr(0, 3);

				// some of the abrs are only 2 with the next character beting '/'
				// depending on length it will alter the numbers of where to start
				if(abr_home[2] == '/') {
					// grabs the team name removing the abr and '">' at the end
					home = line.substr(3, line.length() - 5);
					// removes the '/'
					abr_home = abr_home.substr(0, 2);
				} else {
					// grabs the team name removing the abr and '">' at the end
					home = line.substr(4, line.length() - 6);
				}


		///////////////////////////////////////////////////////////////

				// goes through lines inbetween home and score
				for(int i=0; i<17; i++) {
					getline(games, line);
				}

				// if a match for the scores, when the final score is shown, has been found
				found = false;
				// where to start looking for the abr
				start = 0;

				// sees if it matches the home team abr
				// if statment is for when the abr is 3 char and else is for 2 char
				if(abr_home.length() == 3) {
					// compares chars
					if(abr_home[0] == tolower(line[start], loc) && abr_home[1] == tolower(line[start+1], loc) && abr_home[2] == tolower(line[start+2], loc)) {
						// match found so score is saved under home score
						score_home = stoi(line.substr(4, 1));
						// the first score has been found, second should be okay so setting true now
						// error handeling for if the second doesn't match is taken care of later
						found = true;
					}
				// read comments from above
				} else {
					if(abr_home[0] == tolower(line[start+0], loc) && abr_home[1] == tolower(line[start+1], loc)) {
						score_home = stoi(line.substr(3, 1));
						found = true;
					}
				}

				// the first score has been found so find the second
				if(found) {
					// moves the looking spot to the second team abr
					start = abr_home.length() + 4;

					// double checks that the next abr is actually the correct
					if(abr_away.length() == 3) {
						if(abr_away[0] == tolower(line[start], loc) && abr_away[1] == tolower(line[start+1], loc) && abr_away[2] == tolower(line[start+2], loc)) {
							score_away = stoi(line.substr(start + 4, 1));
						// the second team should match by defaut but this handles if they don't
						} else { cout << "SECOND TEAM, AWAY, DIDN'T MATCH.\t" << abr_away << "\t" << line << endl; games.close(); return 1; }
					} else {
						if(abr_away[0] == tolower(line[start], loc) && abr_away[1] == tolower(line[start+1], loc)) {
							score_away = stoi(line.substr(start + 3, 1));
						 // the second team should match by defaut but this handles if they don't
						} else { cout << "SECOND TEAM, AWAY, DIDN'T MATCH.\t" << abr_away << "\t" << line << endl; games.close(); return 1; }
					}
				}

				// no matching team yet so see if the first is the away team
				if(!found) {
					// reset start, shouldn't be needed but just in case
					start = 0;

					if(abr_away.length() == 3) {
						if(abr_away[0] == tolower(line[0], loc) && abr_away[1] == tolower(line[1], loc) && abr_away[2] == tolower(line[2], loc)) {
							score_away = stoi(line.substr(4, 1));
							found = true;
						}
					} else {
						if(abr_away[0] == tolower(line[start], loc) && abr_away[1] == tolower(line[start+1], loc)) {
							score_away = stoi(line.substr(3, 1));
							found = true;
						}
					}

					if(found) {
						// moves the looking spot to the second team abr
						start = abr_away.length() + 4;

	        	                        if(abr_home.length() == 3) {
							if(abr_home[0] == tolower(line[start], loc) && abr_home[1] == tolower(line[start+1], loc) && abr_home[2] == tolower(line[start+2], loc)) {
								score_home = stoi(line.substr(start + 4, 1));
							// the second team should match by defaut but this handles if they don't
                                	                } else { cout << "SECOND TEAM, HOME, DIDN'T MATCH.\t" << abr_away << "\t" << line << endl; games.close(); return 1; }
						} else {
							if(abr_home[0] == tolower(line[start+0], loc) && abr_home[1] == tolower(line[start+1], loc)) {
								score_home = stoi(line.substr(start + 3, 1));
							// the second team should match by defaut but this handles if they don't
        	                                        } else { cout << "SECOND TEAM, HOME, DIDN'T MATCH.\t" << abr_away << "\t" << line << endl; games.close(); return 1; }
						}
					}
				}

			///////////////////////////////////////////////////////////////

				// if it still hasn't been found then there is no score to be reported
				// 	aka game is in progress or in the future
				if(found) {
					// reset gameholder
					gameHolder = "";

					// checks to see if the game went into overtime or a shootout
					// checks by seeing if the string is long enough to hold the info saying if it did
					if(line.length() > (abr_home.length() + abr_away.length() + 10)) {
						// exctract which
						gameHolder = line.substr((abr_home.length() + abr_away.length() + 8), 2);
					}

					overTime = (gameHolder == "OT");
					shootOut = (gameHolder == "SO");

					if(score_home > score_away) {
						winner = home;
					} else {
						winner = away;
					}
				} else {
					overTime = false;
					shootOut = false;
					winner = "NA";
					score_home = 111;
					score_away = 111;
				}

			///////////////////////////////////////////////////////////////

				// display scores
				cout << home << "," << away << "," << winner << ",";

				// checks to see if the game has been played
				//	games that haven't been played are defaulted to 111
				if(score_home != 111) {
					cout << score_home << "," << score_away << "," << overTime << "," << shootOut << endl;
				} else {
					cout << "NA,NA,NA,NA" << endl;
				}
			}
		}
	} else { cout << "File did not open, try again\n"; }

	games.close();
	return 0;
}

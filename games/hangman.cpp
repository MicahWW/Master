#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
/* draw functions
#################################################################################################*/

// outputs the words with the characters that user has guessed
// those that have not been guess are shown as "_"
int drawWord(string word, char used[]) {
	// keeps track where it is at in the word
	int wordPosition = 0;
	// word length
	int wordLength = word.length();
	// keps track where it is in used list
	int usedPosition = 0;
	// stores the output
	string output = "  ";

	while(wordPosition < wordLength) {
		if(word[wordPosition] == used[usedPosition]) {
			output = output + word[wordPosition] + ' ';
			// advance and reset
			wordPosition += 1;
			usedPosition = 0;
		} else if(used[usedPosition+1] != '0') {
			usedPosition += 1;
		} else {
			output += "_ ";
			wordPosition += 1;
		}
	}

	// outputs the word with the letter showing that they have guessed
	cout << output << endl;

	// reset
	usedPosition = 0;
	while(used[usedPosition] != '0') {
		cout << used[usedPosition] << " ";
		usedPosition += 1;
	}
	cout << endl;
	return 0;
}

// draws the man and stand
int drawPerson(int missed) {
	int remainingLines = 4;

	cout << "\n\n\n ______" << endl;
	cout << "|      |" << endl;

	if(missed >= 1) {
		cout << "|      O" << endl;
		remainingLines = 3;
	}
	if(missed >= 2) {
		cout << "|      +" << endl;
		remainingLines = 2;
	}
	if(missed == 3) {
		cout << "|      |" << endl;
		remainingLines = 2;
	}
	if(missed == 4) {
		cout << "|     /|" << endl;
		remainingLines = 2;
	}
	if(missed >= 5) {
		cout << "|     /|\\" << endl;
		remainingLines = 2;
	}
	if(missed >= 6) {
		cout << "|      |" << endl;
		remainingLines = 1;
	}
	if(missed == 7) {
		cout << "|     /" << endl;
		remainingLines = 0;
	}
	if(missed >= 8) {
		cout << "|     / \\" << endl;
		remainingLines = 0;
	}

	while(remainingLines > 0) {
		cout << "|" << endl;
		remainingLines -= 1;
	}

	cout << "|___________";

	return 0;
}

// runs both draw funcions for ease of use in main()
int draw(int missed, string word, char used[]) {
	drawPerson(missed);
	drawWord(word, used);

	return 0;
}

/*#########################################################################################
draw functions*/

char userInput() {
	char output;

	cout << "What is your guess? ";
	cin >> output;

	return output;
}


int main() {
	// words that will be used for the game
	string words[] = {"computer", "physics"};
	// amount of letters that were incorect
	int missed = 0;

	// stores the letters that were used
	// start with filling everthing with 0
	char used[26];
	//stores where at in used
	int usedPosition = 0;
	while(usedPosition < 26) {
		used[usedPosition] = '0';
		usedPosition += 1;
	}
	// reset usedPosition for futher use
 	usedPosition = 0;
/*	// picks random word from words[]
	srand(time(NULL));
	string word = words[rand() % sizeof(words)];
*/

	string word = words[0];

/*
	// test
	used[usedPosition] = 'o';
	usedPosition += 1;
	used[usedPosition] = 'c';
*/
	draw(missed, word, used);

	used[usedPosition] = userInput();

	draw(missed, word, used);

	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std;
/* draw functions
#################################################################################################*/

// outputs the words with the characters that user has guessed
// those that have not been guess are shown as "_"
bool drawWord(string word, char used[]) {
	// keeps track where it is at in the word
	int wordPosition = 0;
	// word length
	int wordLength = word.length();
	// keps track where it is in used list
	int usedPosition = 0;
	// stores the output
	string output = "  ";
	// keeps track how many letters entered are correct
	// later on it is used to tell if the word has been completed
	int correct = 0;

	while(wordPosition < wordLength) {
		if(word[wordPosition] == used[usedPosition]) {
			output = output + word[wordPosition] + ' ';
			// advance and reset
			wordPosition += 1;
			usedPosition = 0;
			correct += 1;
		} else if(used[usedPosition+1] != '0') {
			usedPosition += 1;
		} else {
			output += "_ ";
			wordPosition += 1;
			usedPosition = 0;
		}
	}

	// outputs the word with the letter showing that they have guessed
	cout << output << endl;

	// reset
	usedPosition = 0;
	// outputs the word
	while(used[usedPosition] != '0') {
		cout << used[usedPosition] << " ";
		usedPosition += 1;
	}
	cout << endl;

	// checks if the word has been compleated
	if(correct == (wordLength)) {
		return true;
	}
	return false;
}


// draws the man and stand
int drawPerson(string word, char used[]) {
	// keeps track on how many lines are left when drawing the body
	// allows it to keep the stand (the '|' on the left) the same size/number of occurances
	int remainingLines = 4;
	int usedPosition = 0, wordPosition = 0, wordLength = word.length();
        int missed = 0, correct = 0, lettersUsed = 0;

        usedPosition = 0;
        while(used[usedPosition] != '0') {
                lettersUsed += 1;
                usedPosition += 1;
        }

	if(lettersUsed != 0) {
		while(wordPosition < wordLength) {
			if(word[wordPosition] == used[usedPosition]) {
				correct += 1;
				wordPosition += 1;
				usedPosition += 1;
			} else if(used[usedPosition+1] != '0') {
				usedPosition += 1;
			} else {
				wordPosition += 1;
				usedPosition += 1;
			}
		}
	}

	missed = lettersUsed - correct;


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
bool draw(string word, char used[]) {
	drawPerson(word, used);
	if(drawWord(word, used)) {
		return true;
	}
	return false;
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

	// picks random word from words[]
	// size of words[]
	int size = sizeof(words) / sizeof(words[0]);
	string word = words[rand() % size];

	bool cont = true;

	draw(word, used);
	while(cont) {
                used[usedPosition] = userInput();
                usedPosition += 1;

		if(draw(word, used)) {
			cout << "Congralations" << endl;
			cont = false;
		}
	}
	return 0;
}

#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

/* draw functions
#################################################################################################*/

// outputs the words with the characters that user has guessed
// those that have not been guess are shown as "_"
int drawWord(string word, char used[], int missed) {
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

	int lives = 8 - missed;
	cout << endl << "Correct: " << correct << "\tLives: " << lives << endl;

	// checks if the word has been compleated
	if(correct == (wordLength)) {
		return 1;
	} else if(lives == 0) {
		return 2;
	}
	return 0;
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


	// will count the number of correct to find the number of missed
	usedPosition = 0;
	if(lettersUsed != 0) {
		while(wordPosition < wordLength) {
			if(word[wordPosition] == used[usedPosition]) {
				correct += 1;
				wordPosition += 1;
				usedPosition = 0;
			// not the end of the list
			} else if(used[usedPosition+1] != '0') {
				usedPosition += 1;
			// reached the end of the list without finding the letter in list used
			// advaces to the next letter in the word
			} else {
				wordPosition += 1;
				usedPosition = 0;
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

	return missed;
}

// runs both draw funcions for ease of use in main()
int draw(string word, char used[]) {
	int missed = drawPerson(word, used);
	// tells if the word has been finished correctly or if no lives are left
	// 	0 for not done
	//	1 for word found correctly
	// 	2 for no more lives
	return drawWord(word, used, missed);
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
	string words[] = {"computer", "physics", "school", "study", "english", "something", "anything", "blah", "deskop", "laptop", "youtube", "google"};

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

	srand(time(0));
	// picks random word from words[]
	// size of words[]
	int size = sizeof(words) / sizeof(words[0]);
	string word = words[rand() % size];

	int cont = 0;

	cout << "Guess the word!\n\tYou have eight lives,\n\tguessing a letter that is used more than once gives you more lives" << endl;
	draw(word, used);
	while(!cont) {
                used[usedPosition] = userInput();
                usedPosition += 1;
		cont = draw(word, used);
	}

	if(cont == 1) {
		cout << "Congralations" << endl << endl;
	} else if(cont == 2) {
		cout << "You lose" << endl << "The word was " << word << endl << endl;
	} else {
		cout << "ERROR ERROR" << endl;
	}


	cout << "Enter 'q' to exit ";
	string end;
	// waits till the user hit a letter/number to close
	cin >> end;
	return 0;
}

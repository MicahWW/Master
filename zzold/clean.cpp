#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string moveLeft(string line) {
	int length = line.length();
	int count = 1;
	string output;

//	cout << "moveLeft funcion called" << endl;
	while(count < length) {
		output += line[count];
		count += 1;
	}

	return output;
}

int main() {
	ifstream file;
	file.open("tree.txt");

	string line;
	int count = 0, length;
	int letter;
	bool firstTime;

	// don't need the first line
	getline(file, line);
	while(!file.eof()) {
		getline(file, line);
		length = line.length();
		count = 0;
		firstTime = 1;
		// goes though the length of the string
		while(count < length) {
			letter = static_cast<int>(line[count]);
			// while not a normal character
			if(letter > 126 || letter < 32) {
				line = moveLeft(line);
			}
			count += 1;
//			if(count == length && firstTime) {
//				count = 0;
//				firstTime = 0;
//			}
		}
		cout << line << endl;
	}

}


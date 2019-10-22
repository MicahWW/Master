#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {
	// open the file passed in through comand line
	fstream file;
	file.open(argv[1]);

	// will continue while loop
	bool cont = true;
	// holds the current working line
	string line;
	int found;
	string tab = "^I";

	// continues until it reaches the end of the file
	while(!file.eof()) {
		getline(file, line);

		found = line.find(tab);
		while(found != string::npos) {
			line.replace(line.find(tab), 2, "\t");
			found = line.find(tab);
		}
		cout << line << endl;
	}

	file.close();
	return 0;
}

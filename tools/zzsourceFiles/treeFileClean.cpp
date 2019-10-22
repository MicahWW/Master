// This will get rid of any strange chars that tree outputs
// 	the first line, should be current dir "." will be removed
// 	the lines displaying how many dirs and files there are will be removed

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	// takes input from comand line
	string fileName = argv[1], line;

	// opens file
	fstream file;
	// c_str() because .open is picky on how file name is inputed
	file.open(fileName.c_str());

	// index for first and second "
	int index0, index1;
	bool cont = true;

	// don't need the first line so this skips it
	getline(file, line);
	while(cont) {
		getline(file, line);

		// once it reaches an empty line there should be no need for anything after
		if(line.length() != 0) {
			// add one to get rid of period
			index0 = line.find('"') + 1;
			index1 = line.find('"', index0+1);

			cout << line.substr(index0+1, index1-index0-1) << endl;
		} else {
			cont = false;
		}
	}
	file.close();

	return 0;
}

// This will get rid of any strange chars that tree outputs
// 	the first line, should be current dir "." will be removed
// 	the lines displaying how many dirs and files there are will be removed

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	string fileName = argv[1], line;

	fstream file;
	file.open(fileName.c_str());

	int index0, index1;
	bool cont = true;

	// don't need the first line so this skips it
	getline(file, line);
	while(cont) {
		getline(file, line);

		// once it reaches an empty line there should be no need for anything after
		if(line.length() != 0) {
			index0 = line.find('"');
			index1 = line.find('"', index0+1);

			cout << line.substr(index0+1, index1-index0-1) << endl;
		} else {
			cont = false;
		}
	}
	file.close();

	return 0;
}

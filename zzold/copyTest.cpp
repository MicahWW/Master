#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {

	string fileName = argv[1];
	string line;

	ifstream file;
	file.open(fileName.c_str());

	while(!file.eof()) {
		getline(file, line);
		cout << line << endl;
	}

	file.close();
	return 0;
}

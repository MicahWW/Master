#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]) {
	ifstream page;
	page.open(argv[1]);

	string line;

	getline(page, line);

	istringstream pageLine(line);

	while(getline(pageLine, line, '>')) {
		cout << line << ">" << endl;
	}

	page.close();
	return 0;
}

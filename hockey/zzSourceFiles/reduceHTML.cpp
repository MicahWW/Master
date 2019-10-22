#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
	ifstream page;
	page.open(argv[1]);

	string line;

	if(page.is_open()) {
		for(int i=0; i<772; i++) {
			getline(page, line);
		}

		cout << line << endl;

	} else { cout << "ERROR: file did not open"; page.close(); return 1; }

	page.close();
	return 0;
}

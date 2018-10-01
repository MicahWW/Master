#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	fstream dirTree;
	dirTree.open(".dirTree_CLEAN.txt");

	string line;
	string dirTreeArray[];
	int count = 0;

	while(!dirTree.eof()) {
		getline(dirTree, line);

		dirTreeArray[count] = line;
		count++;
	}
	return 0;
}

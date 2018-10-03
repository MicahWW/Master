#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	fstream dirTree;
	dirTree.open(".dirTree_CLEAN.txt");

	string line;
	string dirTreeArray[50];
	int count = 0;

	while(!dirTree.eof()) {
		getline(dirTree, line);

		dirTreeArray[count] = line;
		count++;
	}
	dirTree.close();

	fstream tree;
	tree.open(".tree_CLEAN.txt");

	count = 0;

	while(!tree.eof()) {
		getline(tree, line);

		if(line != dirTreeArray[count]) {
			cout << line << endl;
		} else {
			count++;
		}
	}

	return 0;
}

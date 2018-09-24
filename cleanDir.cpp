#include <iostream>
#include <fstream>
using namespace std;

int main() {
	bool segFaultTest = false;

	string line;
	int count = 0;

	fstream dirs;
///////////////////////////////////////////////////////////////////////////////////
	dirs.open(".dirstree.txt");
	if(segFaultTest) {
                cout << "Opend first time" << endl;
	}

	while(!dirs.eof()) {
		getline(dirs, line);
		count += 1;
	}
	// minus 3 for getting rid of
	// 1) extra line counted
	// 2) where tree says the amount of dirs
	// 3) an extra line inbetween
	int dirLength = count - 3;
	dirs.close();
	if(segFaultTest) {
		cout << "Closed first time" << endl;
	}

	string dirsArray[dirLength];
/////////////////////////////////////////////////////////////////////////////////////
	dirs.open(".dirstree.txt");
        if(segFaultTest) {
                cout << "Opend second time" << endl;
	}

	count = 0;
	while(count < dirLength) {
//		cout << count << endl;
		getline(dirs, line);
		dirsArray[count] = line;
		count += 1;
	}
	dirs.close();
	if(segFaultTest) {
		cout << "Closed second time" << endl;
	}

	fstream all;
///////////////////////////////////////////////////////////////////////////////////////
	all.open(".tree.txt");
        if(segFaultTest) {
                cout << "Opend third time" << endl;
	}

	// counts the number of lines in .trees.txt file
	count = 0;
	while(!all.eof()) {
		getline(all, line);
		count += 1;
	}
	int fileLength = count;
	all.close();
	if(segFaultTest) {
		cout << "Closed third time" << endl;
	}

//////////////////////////////////////////////////////////////////////////////////////////
	all.open(".tree.txt");
        if(segFaultTest) {
                cout << "Opend fourth time" << endl;
	}

	count = 0;
	while(!all.eof()) {
		getline(all, line);

		count = 0;
		while(count < dirLength) {
			if(line == dirsArray[count]) {
				// exits while loop because if they equal we don't want it
				count == dirLength;
			}// else if(count == dirLength-1) {
				cout << line << endl;
			//}
			count += 1;
		}
	}
	all.close();
	if(segFaultTest) {
		cout << "Closed fourth time" << endl;
	}

	return 0;
}

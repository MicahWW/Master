#include <iostream>
#include <string>
using namespace std;

int encode(char inArray[], int length) {
	int outArray[length];
	int count = 0;

	int list1[] = {37, 41, 43, 53, 61, 71, 73, 79, 83, 101, 103, 113, 121, 127};
	int list2[] = {34, 38, 46, 47, 58, 62, 74, 82, 86, 89,  94,  106, 118, 122};
	int list3[] = {33, 39, 51, 57, 69, 81, 87, 93, 99, 109, 111, 117, 123, 128};
	

	outArray = inArray;
	return outArray[];
}


int main() {
	string start, end;
	int length;

	cout << "Start: ";
	cin >> start;

	length = start.length();

	char startCharArray[length];
	int  startIntArray[length];
	char endCharArray[length];
	int  endIntArray[length];

	int count = 0;
	while(count < length) {
		startCharArray[count] = start[count];
		count += 1;
	}

	count = 0;
	while(count < length) {
		startIntArray[count] = startCharArray[count];
		count += 1;
	}

//	endIntArray[] = encode(startIntArray[], length);

	count = 0;
	while(count < length) {
		endIntArray[count] = startIntArray[count] + 10;
		count += 1;
	}

	count = 0;
	while(count < length) {
		endCharArray[count] = endIntArray[count];
		count += 1;
	}

	count = 0;
	while(count < length) {
		end += endCharArray[count];
		count += 1;
	}

	cout << end << endl;

//	cout << startIntArray[0] << startIntArray[1] << endl;

	return 0;
}

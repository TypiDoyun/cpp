#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	int time;

	cin >> time;

	string* phoneNumberList = new string[time];

	for (int i = 0; i < time; i++) {
		int first, second, last, before;

		cin >> first;
		cin >> second;
		cin >> last;

		before = second;

		if (first == 11) {
			if (second >= 200 && second <= 499) second += 5000;
			else if (second >= 500 && second <= 899) second += 3000;
			else if (second >= 9500 && second <= 9999) second -= 1000;
			else if (second >= 1700 && second <= 1799) second += 5400;
		}
		else if (first == 16) {
			if (second >= 200 && second <= 499) second += 3000;
			else if (second >= 500 && second <= 899) second += 2000;
			else if (second >= 9000 && second <= 9499) second -= 2000;
		}
		else if (first == 19) {
			if (second >= 200 && second <= 499) second += 2000;
			else if (second >= 500 && second <= 899) second += 5000;
			else if (second >= 9000 && second <= 9499) second -= 1000;
			else if (second >= 9500 && second <= 9999) second -= 2000;
		}

		if (before == second) phoneNumberList[i] = "입력 오류";
		else phoneNumberList[i] = "010 " + to_string(second) + " " + to_string(last);
	}

	for (int i = 0; i < time; i++) {
		cout << phoneNumberList[i] << endl;
	}

	delete[] phoneNumberList;
}
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(string data, string word) {
	vector<string> output;
	int end = data.find(word);

	if (end == -1) {
		output.push_back(data);
		return output;
	}

	while (end != -1) {
		output.push_back(data.substr(0, end));
		data.erase(data.begin(), data.begin() + end + 1);
		end = data.find(word);
	}

	output.push_back(data.substr(0));

	return output;
}

int main(void) {
	short line;
	short total = 0;
	short team = 0;
	int fine = 0;
	short illegal = 0;
	short cause = -1;
	vector<string> beforeTime;

	cin >> line;

	for (int index = 0; index < line; index++) {
		string type;
		short amount;
		string timeFormat;

		cin >> type;
		cin >> amount;
		cin >> timeFormat;

		auto splitedFormat = split(timeFormat, ":");

		if ((illegal > 0 || team > 6 || total > 20) && index != 0) {
			fine += ((stoi(splitedFormat.at(0)) * 60 + stoi(splitedFormat.at(1))) - (stoi(beforeTime.at(0)) * 60 + stoi(beforeTime.at(1)))) * 10000;
		}

		if (type == "in") {
			if (amount > 4) illegal++;
			total += amount;
			team++;
		}
		else {
			if (amount > 4) illegal--;
			total -= amount;
			team--;
		}

		beforeTime = splitedFormat;
	}

	cout << fine;
}
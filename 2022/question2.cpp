#include <iostream>
#include <array>
#include <regex>

using namespace std;

int main(void) {
	string locationTemplate;
	int width, height, landmine;

	cin >> width;
	cin >> height;
	cin >> landmine;

	int** board = new int* [height];

	for (int y = 0; y < height; y++) {
		board[y] = new int[width];
		memset(board[y], 0, sizeof(int) * width);
	}

	regex regexp(R"(\((\d+),\s*(\d+)\))");
	smatch match;

	for (int index = 0; index < landmine; index++) {

		cin >> locationTemplate;

		if (!regex_match(locationTemplate, match, regexp)) throw "Location Input Error.";

		int x = stoi(match[1]);
		int y = stoi(match[2]);

		board[y][x] = -1;

		for (int areaY = y - 1; areaY <= y + 1; areaY++) {
			if (areaY < 0 || areaY >= height) continue;
			for (int areaX = x - 1; areaX <= x + 1; areaX++) {
				if (areaX < 0 || areaX >= width) continue;
				if (board[areaY][areaX] == -1) continue;
				board[areaY][areaX]++;
			}
		}
	}

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < height; x++) {
			if (board[y][x] == -1)
				cout << "X";
			else
				cout << board[y][x];
		}
		cout << endl;
	}


}
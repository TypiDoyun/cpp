#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n;
	bool impossible = false;

	cin >> n;

	vector<vector<int>> blueprint(n, vector<int> (2, 0));
	vector<vector<int>> result;

	for (int repeat = 0; repeat < n; repeat++) {
		cin >> blueprint.at(repeat).at(0);
		cin >> blueprint.at(repeat).at(1);
	}

	for (int y = 0; y < n - 1; y++) {
		if (impossible) break;
		for (int x = y + 1; x < n; x++) {
			int tail = blueprint.at(y).at(1);
			if (blueprint.at(x).at(0) == tail || blueprint.at(x).at(1) == tail) {
				swap(blueprint.at(y + 1), blueprint.at(x));
				if (blueprint.at(y + 1).at(1) == tail)
					reverse(blueprint.at(y + 1).begin(), blueprint.at(y + 1).end());
				break;
			}
			if (x == n - 1) impossible = true;
		}
	}

	if (blueprint.at(0).at(0) != blueprint.at(n - 1).at(1)) impossible = true;

	if (impossible) {
		cout << "impossible";
		return 0;
	}

	for (int repeat = 0; repeat < n; repeat++) {
		cout << blueprint.at(repeat).at(0) << " " << blueprint.at(repeat).at(1) << endl;
	}
}
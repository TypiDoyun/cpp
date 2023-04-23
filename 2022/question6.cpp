#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int partition_(vector<int>& arr, int left, int right) {
	int pivot = arr[right];
	int i = left - 1;

	for (int j = left; j <= right - 1; j++) {
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[right]);

	return i + 1;
}

void quickSort(vector<int>& arr, int left, int right) {
	if (left < right) {
		int p = partition_(arr, left, right);

		quickSort(arr, left, p - 1);
		quickSort(arr, p + 1, right);
	}
}

int main() {
	int n, total = 0, before = 0;
	vector<int> card;

	cin >> n;

	for (int repeat = 0; repeat < n; repeat++) {
		int amount;
		cin >> amount;

		card.push_back(amount);
	}

	quickSort(card, 0, n - 1);

	before = card.at(0);
	
	for (int right = 1; right < n; right++) {
		total += before + card.at(right);
		before += card.at(right);
	}

	cout << total;
}
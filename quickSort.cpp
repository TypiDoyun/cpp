#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

template <size_t L>
int partition_(array<int, L>& arr, int left, int right) {
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

template <size_t L>
void quickSort(array<int, L>& arr, int left, int right) {
	if (left < right) {
		int p = partition_(arr, left, right);

		quickSort(arr, left, p - 1);
		quickSort(arr, p + 1, right);
	}
}

int main() {
	array<int, 5> arr = { 1, 5, 4, 2, 3 };

	quickSort(arr, 0, 4);

	for (int item : arr) {
		cout << item << " ";
	}
}
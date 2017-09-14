#include <iostream>

#define N 10

using namespace std;

void printArr(int arr[N]) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int partition(int arr[N], int s, int e) {
	int l = s + 1;
	int r = e;
	while (l < r) {
		while (arr[s] > arr[l]) { l++;}
		while (arr[s] < arr[r]) { r--;}
		if (l < r) {
			swap(arr[l], arr[r]);
		}
	}
	// * make a note of this condition check *
	if (arr[s] > arr[r]) {
		swap(arr[s], arr[r]);
	}
	return r;
}

void qsort(int arr[N], int s, int e) {
	if (s > e) {
		return;
	}
	int pi = partition(arr, s, e);
	qsort(arr, s, pi - 1);
	qsort(arr, pi + 1, e);
}

int main() {
	int arr[N] = {7, 9, 2, 5, 1, 90, 29, 10, 3, 5};
	printArr(arr);

	qsort(arr, 0, 9);
	printArr(arr);
	return 0;
}

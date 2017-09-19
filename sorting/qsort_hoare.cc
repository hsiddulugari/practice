#include <iostream>

#define N 10

using namespace std;

void printArr(int arr[N]) {
	for (int i = 0; i < N; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int partitionS(int arr[N], int s, int e) {
	int pivot = arr[s];
	int l = s + 1;
	int r = e;
	while (l <= r) {
		while (arr[l] <= pivot) { l++;}
		while (arr[r] > pivot) { r--;}
		if (l <= r) {
			swap(arr[l], arr[r]);
		}
	}
	swap(arr[s], arr[r]);
	return r;
}

void qsort(int arr[N], int s, int e) {
	if (s > e) {
		return;
	}
	int pi = partitionS(arr, s, e);
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

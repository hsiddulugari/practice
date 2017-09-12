#include <iostream>

using namespace std;

void printPermutations(char *arr, int n, int k) {
	if (k == n-1) {
		cout << arr << endl;
		return;
	}

	for (int j = k; j < n; j++) {
		swap(arr[k], arr[j]);
		printPermutations(arr, n, k+1);
		swap(arr[k], arr[j]);
	}
}

int main() {
	char arr[] = "abcd";
	printPermutations(arr, strlen(arr), 0);
	return 0;
}

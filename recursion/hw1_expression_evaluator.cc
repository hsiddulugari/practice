#include <iostream>
#include <string>

using namespace std;

void printEvalExp

void printEvalExp(string arr, int n, int k) {
	if (k == n) {
		return;
	}
	
	cout << arr.substr(0, k) << " " << arr.substr(k, n) << endl;
	printEvalExp(arr, n, k+1);
	cout << arr.substr(0, k) << "+" << arr.substr(k, n) << endl;
	printEvalExp(arr, n, k+1);
	cout << arr.substr(0, k) << "*" << arr.substr(k, n) << endl;
	printEvalExp(arr, n, k+1);
}

int main() {
	string arr = "1234";
	printEvalExp(arr, arr.size(), 1);

	return 0;
}

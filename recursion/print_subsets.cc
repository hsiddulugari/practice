#include <iostream>
#include <set>
#include <iterator>

using namespace std;

void printSet(set <char> setSoFar) {
	set <char> ::iterator itr;
	for (itr = setSoFar.begin(); itr != setSoFar.end(); itr++) {
		cout << "\t" << *itr;
	}
	cout << endl;
}

void printAllSubsets(char *arr, int k, int n, set <char> setSoFar) {
	if (k == n) {
		printSet(setSoFar);
		return;	
	}

	char elem = arr[k];
	printAllSubsets(arr, k + 1, n, setSoFar);
	setSoFar.insert(elem);
	printAllSubsets(arr, k + 1, n, setSoFar);
	setSoFar.erase(elem);
}

int main() {
	char arr[] = "ade";
	set <char> setSoFar;
	int n = strlen(arr);

	printAllSubsets(arr, 0, n, setSoFar);

	return 0;
}

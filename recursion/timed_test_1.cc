#include <iostream>
#include <set>
#include <vector>

using namespace std;

void printSubset(set <int> subset) {
	set <int> ::iterator itr;
	for (itr = subset.begin(); itr != subset.end(); itr++) {
		cout << *itr << "\t";
	}
	cout << endl;
}

bool subsetExists(vector <int> v, int n, int i, int k, int sum, set <int> subsetSoFar) {
	if (sum == k) {
		printSubset(subsetSoFar);
		return true;
	}
	if (i == n) {
		return false;
	}

	int t = v.at(i);
	bool exists;

	exists = subsetExists(v, n, i+1, k, sum, subsetSoFar);
	if (!exists) {
		subsetSoFar.insert(t);
		sum += t;
		exists = subsetExists(v, n, i+1, k, sum, subsetSoFar);
		subsetSoFar.erase(t);
		sum -= t;
	}
	return exists;
}

int
main()
{
	int n;
	cout << "Enter size: ";
	cin >> n;
	cout << "Enter numbers: ";
	
	vector <int> v;
	v.clear();
	int t;

	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}
	cout << "Enter sum: ";
	int k;
	cin >> k;

	set <int> subsetSoFar;
	subsetSoFar.clear();

	cout << subsetExists(v, n, 0, k, 0, subsetSoFar) << endl;
	
	return 0;
}

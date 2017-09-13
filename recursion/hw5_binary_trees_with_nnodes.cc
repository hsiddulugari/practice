#include <iostream>

using namespace std;

int countTrees(int iNodeCount) {
	if (iNodeCount == 0 || iNodeCount == 1) {
		return 1;
	}

	int res = 0;
	int lnum;
	int rnum;
	for (int i = 0; i < iNodeCount; i++) {
		lnum = countTrees(i);
		rnum = countTrees(iNodeCount - 1 - i);
		res += lnum * rnum;
	}
	return res;
}

int main() {
	int n;
	cout << "Enter a number: ";
	cin >> n;
	cout << countTrees(n) << endl;
	
	return 0;
}

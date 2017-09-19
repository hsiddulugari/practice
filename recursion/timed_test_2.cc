#include <iostream>

using namespace std;

void
printValidParensHelper(string s, int n, int k, int nopen, int nclose)
{
	if (nclose == n) {
		cout << s << " ";
		return;
	}

	if (nopen < n) {
		printValidParensHelper(s+'(', n, k+1, nopen+1, nclose);
	}
	if (nopen > nclose) {
		printValidParensHelper(s+')', n, k+1, nopen, nclose+1);
	}
}

void
printValidParens(int n)
{
	string s = "";
	if (n > 0) {
		printValidParensHelper(s, n, 0, 0, 0);
		cout << endl;
	}
}

int
main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;

	printValidParens(n);
	return 0;
}

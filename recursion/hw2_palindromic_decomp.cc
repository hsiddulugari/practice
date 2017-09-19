#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool
isPalindrome(string s, int b, int e)
{
	int l = b;
	int r = e;
	while (l < e) {
		if (s.at(l++) != s.at(e--)) {
			return false;
		}
	}
	return true;
}

string
getSubstr(string s, int b, int e)
{
	string ss = "";
	for (int i = b; i <= e; i++) {
		ss.push_back(s.at(i));
	}
	ss.push_back('|');
	return ss;
}

string
getEachSingle(string s, int b, int e)
{
	string ess = "";
	for (int i = b; i < e; i++) {
		ess.push_back(s.at(i));
		ess.push_back('|');
	}
	return ess;
}

void
PD(string s, int n, int k, vector <string> &pds)
{
	if (k == n) {
		return;
	}

	for (int i = k+1; i < n; i++) {
		if (isPalindrome(s, k, i)) {
			string d = "";
			d.append(getEachSingle(s, 0, k));
			d.append(getSubstr(s, k, i));
			d.append(getEachSingle(s, i+1, n));
			pds.push_back(d);
		}
	}
	PD(s, n, k+1, pds);
}

vector <string> palindromicDecomposition(string strInput) {
	int n = strInput.length();
	vector <string> pds;
	pds.clear();

	pds.push_back(getEachSingle(strInput, 0, n));
	PD(strInput, n, 0, pds);
	return pds;
}

int
main()
{
	string s;
	cin >> s;

	vector <string> pds = palindromicDecomposition(s);
	vector <string> ::iterator iter;
	for (iter = pds.begin(); iter != pds.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}

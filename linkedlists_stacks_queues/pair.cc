#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

int
main()
{
	vector < pair <int, int> > pairs;
	pairs.push_back(make_pair(1,2));
	pairs.push_back(make_pair(1,1));
	pairs.push_back(make_pair(2,2));
	pairs.push_back(make_pair(2,1));

	sort(pairs.begin(), pairs.end());

	for (auto p:pairs) {
		cout << p.first << "  " << p.second << endl;
	}
	return 0;
}

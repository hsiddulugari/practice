#include <iostream>
#include <vector>
#include <string>

using namespace std;

string sortCharacters(string inString) {
    string result = "";
    vector <int> ascii(256, 0);
    for (auto c : inString) {
        ascii[c]++;
    }
    for (int i = 0; i < 256; i++) {
	if (ascii[i]) {
		for (int j = 0; j < ascii[i]; j++) {
			result.push_back(i);
		}
	}
    }
    return result;
}

int
main()
{
	cout << sortCharacters("abracadabra") << endl;
	
	return 0;
}

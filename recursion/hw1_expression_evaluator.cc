#include <iostream>
#include <string>
#include <stack>

using namespace std;

void printStack(const stack <string> &operands)
{
	string temp = "";
	for (stack <string> t = operands; !t.empty(); t.pop()) {
		temp = t.top() + " " + temp;
	}
	cout << temp << endl;
}

void printEvalExp(string arr, int n, int k, stack <string> &operands) {
	if (k == n) {
		printStack(operands);
		return;
	}
	
	for (int i = k; i < n; i++) {
		cout << "----------------------->" << k << " " << i << endl;
		operands.push(arr.substr(k, i-k+1));
		printEvalExp(arr, n, i+1, operands);
		operands.pop();
		if (!operands.empty()) {
			operands.push("*");
		}
		operands.push(arr.substr(k, i-k+1));
		printEvalExp(arr, n, i+1, operands);
		operands.pop();
		if (!operands.empty()) {
			operands.pop();
		}
		if (!operands.empty()) {
			operands.push("+");
		}
		operands.push(arr.substr(k, i-k+1));
		printEvalExp(arr, n, i+1, operands);
		operands.pop();
		if (!operands.empty()) {
			operands.pop();
		}
	}
}

int main() {
	string arr = "1234";
	stack <string> operands;

	printEvalExp(arr, arr.size(), 0, operands);

	return 0;
}

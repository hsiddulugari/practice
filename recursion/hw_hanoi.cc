#include <iostream>
#include <stack>

using namespace std;

void
printRod(stack <int> s)
{
	for (stack <int> copy = s; !copy.empty(); copy.pop()) {
		cout << copy.top() << " ";
	}
	cout << endl;
}

static stack <int> s1;
static stack <int> s2;
static stack <int> s3;
static int cnt = 0;

void
moveTower(stack <int> &main, stack <int> &temp, stack <int> &temp1) {
	cnt++;
	if (cnt > 100) {
		return;
	}

	printRod(s1);
	printRod(s2);
	printRod(s3);
	cout << "------------" << endl;

	int top = main.top();
	main.pop();
	if (top == 5) {
		temp.push(top);
	} else {
		moveTower(main, temp1, temp);
		top = main.top();
		temp.push(top);
		moveTower(temp1, temp, main);
	}
}

int
main()
{
	s1.push(5);
	s1.push(4);
	s1.push(3);
	s1.push(2);
	s1.push(1);

	moveTower(s1, s2, s3);
	return 0;
}

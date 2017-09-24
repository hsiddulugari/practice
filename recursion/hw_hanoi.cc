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
moveTower(int disk, stack <int> &main, stack <int> &dest, stack <int> &spare) {

	if (disk == 0) {
		int top = main.top();
		main.pop();
		dest.push(top);
	} else {
		moveTower(disk - 1, main, spare, dest);
		int top = main.top();
		main.pop();
		dest.push(top);
		moveTower(disk - 1, spare, dest, main);
	}
	printRod(s1);
	printRod(s2);
	printRod(s3);
	cout << "------------" << endl;

}

int
main()
{
	s1.push(5);
	s1.push(4);
	s1.push(3);
	s1.push(2);
	s1.push(1);

	moveTower(4, s1, s2, s3);
	return 0;
}

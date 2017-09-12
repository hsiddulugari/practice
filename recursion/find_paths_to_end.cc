#include <iostream>

using namespace std;

#define MAX_COLS 9

int pathsToEnd(int a[][MAX_COLS], int rows, int cols, int row, int col) {
	if (row == rows - 1 && col == cols - 1) {
		return 1;
	}

	int right = 0;
	int down = 0;
	if (row < rows - 1) {
		down = pathsToEnd(a, rows, cols, row + 1, col);
	}
	if (col < cols - 1) {
		right = pathsToEnd(a, rows, cols, row, col + 1);
	}
	return (down + right);
}

int pathsToEndOpt(int a[][MAX_COLS], int rows, int cols, int row, int col) {
	if (row == rows - 1 || col == cols - 1) {
		return 1;
	}

	int right = pathsToEndOpt(a, rows, cols, row + 1, col);
	int down = pathsToEndOpt(a, rows, cols, row, col + 1);
	return right + down;
}

int main() {
	int a[][MAX_COLS] = {{5, 6, 7, 8}, {4, 3, 2, 8}, {9, 4, 2, 2}};
	cout << "Number of paths = " << pathsToEnd(a, (int)sizeof(a)/sizeof(a[0]), 4, 0, 0) << endl;
	cout << "Number of paths = " << pathsToEndOpt(a, (int)sizeof(a)/sizeof(a[0]), 4, 0, 0) << endl;
	
	return 0;
}

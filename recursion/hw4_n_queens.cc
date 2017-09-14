#include <iostream>

using namespace std;

#define N 4

bool isPlaceable(bool squares[N][N], int n, int row, int col) {
	for (int i = 0; i < n; i++) {
		//Check horizontally and vertically
		if (squares[row][i] ||
		    squares[i][col]) {
			return false;
		}
		//Check diagonally
		if (i > 0) {
			if ((col - i >= 0 && row - i >= 0 && squares[row - i][col - i]) ||
			    (col + i < n && row + i < n && squares[row + i][col + i]) ||
			    (col - i >= 0 && row + i < n && squares[row + i][col - i]) ||
			    (col + i < n && row - i >= 0 && squares[row - i][col + i])) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	bool squares[N][N] = {};
	squares[2][1] = true;
	cout << isPlaceable(squares, N, 3, 3) << endl;

	return 0;
}

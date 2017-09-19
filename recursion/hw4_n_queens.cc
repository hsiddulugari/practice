#include <iostream>
#include <array>

using namespace std;

bool isSafe(bool **board, int n, int row, int col) {
	for (int i = 0; i < col; i++) {
		//Check horizontally
		if (board[row][i]) {
			return false;
		}
	}

	//Check diagonally down
	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j]) {
			return false;
		}
	}

	//Check diagonally up
	for (int i = row, j = col; i < n && j >= 0; i++, j--) {
		if (board[i][j]) {
			return false;
		}
	}
	return true;
}

void prettyPrint(bool **board, int n) {
	for (int j = 0; j < n; j++) {
		cout << "+-";
	}
	cout << "+" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board[i][j] ? cout << "|*" : cout << "| ";
		}
		cout << "|" << endl;
		for (int j = 0; j < n; j++) {
			cout << "+-";
		}
		cout << "+" << endl;
	}
	cout << endl;
}

void printValidAr(bool **board, int n, int ps, int col) {
	cout << ps << endl;
	if (ps == n) {
		prettyPrint(board, n);
	}

	if (col == n) {
		return;
	}

	for (int i = 0; i < n; i++) {
		if (isSafe(board, n, i, col)) {
			board[i][col] = true;
			ps++;
			printValidAr(board, n, ps, col + 1);
			board[i][col] = false;
			ps--;
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	bool **board = new bool * [n];
	for (int i = 0; i < n; i++) {
		board[i] = new bool[n]();
	}
	printValidAr(board, n, 0, 0);

	for (int i = 0; i < n; i++) {
		delete[] board[i];
	}
	delete[] board;
	return 0;
}

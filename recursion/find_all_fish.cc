int BP(int arr[N][N], int n, int r, int d) {
	int res = 0;
	if (r == n-1 && d == n-1) {
		res = arr[r][d];
	} else if (r == n-1) {
		res = BP(r, d+1);
	} else if (d == n-1) {
		res = BP(r+1, d);
	} else {
		res = MAX(BP(arr, n, r, d+1), BP(arr, n, r+1, d));
	}
	return arr[r][d] + res;
}

int minC()

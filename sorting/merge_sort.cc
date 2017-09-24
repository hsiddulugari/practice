#include <iostream>
#include <vector>

using namespace std;

void
printV(const vector <int> &output)
{
	for (auto v: output) {
		cout << v << " ";
	}
	cout << endl;
}

void
merge(vector <int> &input, vector <int> &output, int b, int mid, int e)
{
	int i = b;
	int l = b, r = mid+1;
	while (l <= mid && r <= e) {
		if (input[l] <= input[r]) {
			output[i++] = input[l++];
		} else {
			output[i++] = input[r++];
		}
	}
	while (l <= mid) {
		output[i++] = input[l++];
	}
	while (r <= e) {
		output[i++] = input[r++];
	}
}

void
MergeSortHelper(vector <int> &input, vector <int> &output, int b, int e)
{
	if (b >= e) {
		return;
	}

	int mid = b + (e - b)/2;
	MergeSortHelper(input, output, b, mid);
	MergeSortHelper(input, output, mid+1, e);
	merge(input, output, b, mid, e);
	for (int i = b; i <= e; i++) {
		input[i] = output[i];
	}
}

vector <int> MergeSort(vector <int> intArr) {
	vector <int> input = intArr;
	vector <int> output(intArr.size());
	MergeSortHelper(input, output, 0, intArr.size() - 1);
	return output;
}

int
main()
{
	vector <int> nums = {8,4,3,2,6,1,8,9,5,3};
	printV(nums);
	vector <int> output = MergeSort(nums);
	printV(output);
	return 0;
}

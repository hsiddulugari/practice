#include <iostream>

using namespace std;

void findMissing(int nums[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum ^= nums[i];
	}

	int nsum = 0;
	for (int i = 1; i <= n+1; i++) {
		nsum ^= i;	
	}

	cout << "Missing num: " << (sum ^ nsum) << endl;
}

void findMissingRepeating(int nums[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum ^= nums[i];
	}

	int nsum = 0;
	for (int i = 1; i <= n; i++) {
		nsum ^= i;
	}

	int missRepeat = sum ^ nsum;
	int fs = missRepeat & ~(missRepeat - 1);

	int mr1 = 0;
	int mr2 = 0;
	for (int i = 0; i < n; i++) {
		if (nums[i] & fs) { 
			mr1 ^= nums[i];
		} else {
			mr2 ^= nums[i];
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i & fs) { 
			mr1 ^= i;
		} else {
			mr2 ^= i;
		}
	}
	
	int i;
	for (i = 0; i < n; i++) {
		if (mr1 == nums[i]) {
			printf("Missing: %d, Repeating: %d\n", mr2, mr1);
			break;
		}
	}
	if (i == n) {
		printf("Missing: %d, Repeating: %d\n", mr1, mr2);
	}
}

int main() {
	int arr1[] = {2, 3, 5, 4};
	findMissing(arr1, 4);
	int arr2[] = {1, 1, 2, 3, 4};
	findMissingRepeating(arr2, 5);
	return 0;
}

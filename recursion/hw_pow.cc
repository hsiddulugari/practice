#include <iostream>

float pow(float d, int p) {
	if (p == 0) {
		return 1;
	} else if (p > 0) {
		return d * pow(d, p - 1);
	} else {
		return 1 / pow(d, -1 * p);
	}
}

int
main()
{
	printf("%f\n", pow(3, 4));
	printf("%f\n", pow(3, -4));
	return 0;
}

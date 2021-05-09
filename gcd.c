// GCD.C: find the greatest common denominator of two ints
#include <stdio.h>
#include <stdlib.h>

int gcd(int, int); // forwarding recursion magick

int main(int argc, char *argv[]) {
	if (argc - 1 != 2) {
		fprintf(stderr, "Usage: gcd <number> <number>\n");
		exit(0);
	}

	// argv[0] is the argument to run the file, so account for that
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	if (a < 1 || b < 1) {
		fprintf(stderr, "ERROR: numbers must be greater than 1\n");
		exit(1);
	}

	printf("GCD of %d & %d: %d\n", a, b, gcd(a, b));
	return 0;
}

int gcd(int a, int b) {
	if (b < a) {
		int x = a;
		a = b;
		b = x;
	}
	if (a) {
		return gcd((b % a), a);
	} else {
		return b;
	}
}

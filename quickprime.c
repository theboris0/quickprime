#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int is_prime(int number) {
	int maxdivider, divider, mod;
	maxdivider = number / 2;
	for (divider = 2; divider <= maxdivider; divider++) {
		mod = number % divider;
		if (mod == 0) {
			return 0;
		}
	}
	return 1;
}

int main(int argc, char *argv[]) {
	int output_count, number, divider, maxdivider, mod, cycle_count;
	bool prime = false;
	
	if (argc > 1) {
		number = atoi(argv[1]);
		if (argc == 2) {
			output_count = 1;
		} else if (argc == 3) {
			output_count = atoi(argv[2]);
		} else {
			printf("too many inputs");
			return 2;
		}
	} else {
		printf("no input");
		return 1;
	}
	
	for (cycle_count = 0; cycle_count < output_count; number++) {
		if (is_prime(number) == 1) {
			printf("%d\n", number);
			cycle_count++;
		}
	}
	
	return 0;
}
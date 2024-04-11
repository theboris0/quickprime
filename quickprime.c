#include <stdio.h>
#include <stdlib.h>

//convert launch arguments to numbers, also checks whether input is number
int input_conversion(char input[]) {
	int number;
	for (int i = 0; input[i] != '\0'; i++) { 
        if((input[i] - 48)>=0 && (input[i] - 48)<10 ){
			number = number * 10 + (input[i] - 48);
		} else {
			printf("invalid input - not a number\n");
			exit(3);
		}
	return number;
	}
}

//check whether number is a prime number
int is_prime(int number) {
	int maxdivider, divider, mod;
	if (number == 1 || number == 0) {
		return 0;
	}
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
	int output_count, number, cycle_count;
	
	if (argc > 1) {
		number = input_conversion(argv[1]);
		if (argc == 2) {
			output_count = 1;
		} else if (argc == 3) {
			output_count = input_conversion(argv[2]);
		} else {
			printf("too many inputs\n");
			return 2;
		}
	} else {
		printf("no input\n");
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
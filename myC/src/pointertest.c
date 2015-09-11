#include <stdio.h>

//int main() {
int fun() {
	int my_array[] = { 5, 8, 34, 23, 77 };
	int *ptr;

	for (int i = 0; i < 5; i++) {
		printf("Array: array[%d] - %d\n", i, my_array[i]);
		printf("Pointer at: %d - %d\n", i, *(ptr + i));
	}

	return 1;
}

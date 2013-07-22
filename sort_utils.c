#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int verify_sorted(int* array, int size) {
	int sorted = 1;
	int i;
	for (i = 0; i < size - 2; i++) {
		if (array[i] > array[i+1]) {
			sorted = 0;
			//printf("unsorted: [%d]: %d !< [%d]: %d\n", i, array[i], i+1, array[i+1]);
		}
	}
	return sorted;
}

void swap(int* array, int i, int j) {
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

void populate_random_array(int* array, int size) {
	srand(time(NULL));
	int i;
	for (i = 0; i < size; i++) {
		int r = rand() % 10;
		array[i] = r;
	}
}

int *copy_array(int *array, int size) {
	int i;
	int *copy = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++) {
		copy[i] = array[i];
	}
	return copy;
}

void array_print(int* array, int size, char* name) {
	int i;	
	for (i = 0; i < size; i++) {
		printf("%10s[%d]: %d\n", name, i, array[i]);
	}
}
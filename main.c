#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "sort_utils.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "merge_sort.h"

time_t start_time;
time_t finish_time;

int size = 40000;

void start() {
	start_time = time(NULL);
}

void finish() {
	finish_time = time(NULL);
	printf("time taken: %ld sec\n", finish_time - start_time);
}

void test_merge_sort() {
	puts("----------");
	printf("testing merge sort on %d size array\n", size);
	int array[size];
	populate_random_array(array, size);
	//array_print(array, size, "array");
	start();
	int* sorted = merge_sort(array, size);
	finish();
	assert(verify_sorted(sorted, size));
	//array_print(sorted, size, "sorted");		
}

void test_selection_sort() {
	puts("----------");
	printf("testing selection sort on %d size array\n", size);
	int array[size];
	populate_random_array(array, size);
	start();
	selection_sort(array, size);
	finish();
	assert(verify_sorted(array, size));
}

void test_insertion_sort() {
	puts("----------");
	printf("testing insertion sort on %d size array\n", size);
	int array[size];
	populate_random_array(array, size);
	start();
	selection_sort(array, size);
	finish();
	assert(verify_sorted(array, size));
}

int main() {
	test_selection_sort();
	test_insertion_sort();
	test_merge_sort();
	return 0;
}
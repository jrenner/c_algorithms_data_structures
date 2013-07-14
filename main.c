#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "sort_utils.h"
#include "merge_sort.h"

time_t start;
time_t finish;

int main() {
	int size = 1000000;
	int unsorted[size];
	populate_random_array(unsorted, size);
	//array_print(unsorted, size, "unsorted");
	puts("---------------");
	start = time(NULL);
	int* sorted = merge_sort(unsorted, size);
	finish = time(NULL);
	assert(verify_sorted(sorted, size));
	printf("proper sorting verified OK\n");
	//array_print(sorted, size, "sorted");	
	printf("time taken: %ld s\n", finish - start);
	return 0;
}
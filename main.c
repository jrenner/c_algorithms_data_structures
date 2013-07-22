#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "sort_utils.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "bubble_sort.h"
#include "merge_sort.h"
#include "quick_sort.h"
#define SEC_TO_NANO   1000000000
#define MILLI_TO_NANO 1000000
#define MICRO_TO_NANO 1000

struct timespec start_time;
struct timespec finish_time;

extern int comparisons;

char *human_time(long tm) {	
	// original time should be in nanoseconds
	long remaining;

	long seconds = tm / SEC_TO_NANO;
	remaining = tm % SEC_TO_NANO;
	long millis = remaining / MILLI_TO_NANO;
	remaining = remaining % MILLI_TO_NANO;
	long micros = remaining / MICRO_TO_NANO;
	//long nanos = remaining % MICRO_TO_NANO;

	char *time_text = malloc(128 * sizeof(char));
	int n = 0;
	if (seconds > 0) {
		n = sprintf(time_text, " %lds", seconds);
	}
	if (millis > 0) {
		n += sprintf(time_text + n, " %ldms", millis);
	}
	if (micros > 0) {
		n += sprintf(time_text + n, " %ldus", micros);
	}
	return time_text;
}

void start() {
	clock_gettime(CLOCK_REALTIME, &start_time);
}

void finish() {
	clock_gettime(CLOCK_REALTIME, &finish_time);
	long start_ns = start_time.tv_sec * SEC_TO_NANO + start_time.tv_nsec;
	long finish_ns = finish_time.tv_sec * SEC_TO_NANO + finish_time.tv_nsec;
	long total = finish_ns - start_ns;
	printf("time taken: %s\n", human_time(total));
}

void confirm_array_is_sorted(int *array, int size) {
	if (verify_sorted(array, size)) {
		printf("array sort verified\n");
	} else {
		printf("WARNING: array not sorted properly!\n");
	}
}

void test_selection_sort(int *original, int size) {
	int *array = copy_array(original, size);
	puts("---------- selection sort");	
	start();
	selection_sort(array, size);
	finish();
	confirm_array_is_sorted(array, size);
}

void test_insertion_sort(int *original, int size) {
	int *array = copy_array(original, size);
	puts("---------- insertion sort");
	start();
	selection_sort(array, size);
	finish();
	confirm_array_is_sorted(array, size);
}

void test_bubble_sort(int *original, int size) {
	int *array = copy_array(original, size);
	puts("---------- bubble sort");
	start();
	bubble_sort(array, size);
	finish();
	confirm_array_is_sorted(array, size);
}

void test_merge_sort(int *original, int size) {
	int *array = copy_array(original, size);
	puts("---------- merge sort");
	start();
	int* sorted = merge_sort(array, size);
	finish();
	confirm_array_is_sorted(sorted, size);
}

typedef enum {
	NAIVE_FIRST,
	NAIVE_LAST,
	MEDIAN,
	MIDDLE,
	RANDOM,
	OPTIMIZED
} pivot_type;

void test_quick_sort(int *original, int size, pivot_type p_type) {
	int *array = copy_array(original, size);	
	start();
	int left = 0;
	int right = size - 1;
	printf("---------- quick sort : ");		
	switch (p_type) {
		case NAIVE_FIRST:
			puts("NAIVE_FIRST");
			comparisons = 0;
			naive_quick_sort_first(array, left, right); break;
		case NAIVE_LAST:
			puts("NAIVE_LAST");
			comparisons = 0;
			naive_quick_sort_last(array, left, right); break;
		case MEDIAN:
			puts("MEDIAN");
			comparisons = 0;
			median_quick_sort(array, left, right); break;
		case MIDDLE:
			puts("MIDDLE");
			comparisons = 0;
			middle_quick_sort(array, left, right); break;
		case RANDOM:
			puts("RANDOM");
			comparisons = 0;
			random_quick_sort(array, left, right); break;
		case OPTIMIZED:
			puts("OPTIMIZED");
			comparisons = 0;
			optimized_quick_sort(array, left, right); break;
		default:
			puts("unhandled p_type in test_quick_sort");
			exit(55);
	}
	printf("comparisons: %d\n", comparisons);
	finish();	
	confirm_array_is_sorted(array, size);
	//array_print(array, size, "qsort");
}

int main(int argc, char **argv) {
	int size = 5000;
	if (argc > 1) {
		size = atoi(argv[1]);
	}
	printf("random unsorted array size is: %d\n", size);
	int *array = malloc(sizeof(int) * size);
	populate_random_array(array, size);
	//int test[8] = {3, 2, 5, 1, 4, 8, 6, 7};

	//test_selection_sort(array, size);
	//test_insertion_sort(array, size);
	//test_bubble_sort(array, size);	

/*	size = 10000;
	FILE* fin = fopen("integers.txt", "r");
	if (fin == NULL) {
		puts("FILE OPEN ERROR");
		exit(2);
	}
	array = malloc(sizeof(int) * size);
	char buf[256];
	int i = 0;
	int lines = 0;
	while (fgets(buf, 256, fin) != NULL) {
		lines++;
		array[i++] = atoi(buf);
	}
	printf("read %d lines from files\n", lines);
	array_print(array, size, "1000.txt");*/

	test_merge_sort(array, size);
	test_quick_sort(array, size, MEDIAN);
	test_quick_sort(array, size, RANDOM);
	test_quick_sort(array, size, MIDDLE);
	test_quick_sort(array, size, NAIVE_FIRST);
	test_quick_sort(array, size, NAIVE_LAST);
	test_quick_sort(array, size, OPTIMIZED);

	return 0;
}
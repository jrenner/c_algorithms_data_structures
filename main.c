#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include "sort_utils.h"
#include "selection_sort.h"
#include "insertion_sort.h"
#include "bubble_sort.h"
#include "merge_sort.h"
#define SEC_TO_NANO   1000000000
#define MILLI_TO_NANO 1000000
#define MICRO_TO_NANO 1000

struct timespec start_time;
struct timespec finish_time;

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

int main() {
	int size = 1000;
	int *array = malloc(sizeof(int) * size);
	populate_random_array(array, size);
	test_selection_sort(array, size);
	test_insertion_sort(array, size);
	test_bubble_sort(array, size);
	test_merge_sort(array, size);
	return 0;
}
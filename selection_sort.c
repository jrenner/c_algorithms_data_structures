#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

struct timeval start_time;
struct timeval finish_time;
long elapsed_times[256];
int times_measured = 0;

void create_test_array(int array[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		int r = rand() % 100000;
		array[i] = r;
	}
}

void array_print(int* array, int size) {
	int i;	
	for (i = 0; i < size; i++) {
		printf("[%d]: %d\n", i, array[i]);
	}
}

void swap(int* array, int i, int j) {
	int tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

// returns the index of the lowest element in the array
int find_lowest_element(int* array, int size, int position) {
	int i = position;
	int lowest_index = -1;
	int lowest_value = -1;
	for(; i < size - 1; i++) {
		if (array[i] < lowest_value || lowest_value == -1) {
			lowest_index = i;
			lowest_value = array[i];
		}
	}
	if (lowest_index < 0) {
		printf("ERROR: couldn't find lowest element!\n");
		exit(55);
	}
	return lowest_index;
}

void elapsed_time_print(char* name, struct timeval* start, struct timeval* finish) {
	// calculate elapsed time in milliseconds
	long millis = (finish->tv_sec - start->tv_sec) * 1000;
	millis += (finish->tv_usec - start->tv_usec) / 1000;
	printf("elapsed time for %s: %ld ms\n", name, millis);

	elapsed_times[times_measured++] = millis;
}

void average_elapsed_time(char* name) {
	long total = 0;
	int i;
	for(i = 0; i < times_measured; i++) {
		total += elapsed_times[i];
	}
	puts("-------------------------------");
	printf("average elapsed time for %s: %ld ms\n", name, total / times_measured);
	puts("-------------------------------");
	// reset to be ready for next set of operations
	times_measured = 0;
}

void selection_sort(int* array, int size) {
	gettimeofday(&start_time, NULL);
	int i, j;
	int iMin;
	for (j = 0; j < size - 1; j++) {
		iMin = find_lowest_element(array, size, j);
//		printf("lowest element: %d\n", array[iMin]);
		for (i = j + 1; i < size; i++) {
			if (array[i] < array[iMin]) {
				iMin = i;
			}
		}
		if (iMin != j) {
			swap(array, j, iMin);
		}
	}
	gettimeofday(&finish_time, NULL);
	elapsed_time_print("selection sort", &start_time, &finish_time);
//	printf("start time: %ld\nfinish time: %ld\n", (start_time, finish_time);
//	printf("selection sort elapsed time: %ld\n", finish_time - start_time);	
//	printf("Selection Sort Results:\n");
//	array_print(array, size);
}

void verify_sorted(int* array, int size) {
	int i;
	for (i = 0; i < size - 2; i++) {
		if (array[i] > array[i+1]) {
			printf("FATAL ERROR - SORT NOT OK: array[%d]: %d, array[%d]: %d\n", i, array[i], i+1, array[i+1]);
			exit(55);
		}
	}
//	printf("SORT VERIFIED OK\n");
}

int main() {
	int num_cycles = 20;
	srand(1);
	int cycle = 0;
	while (cycle < num_cycles) {
		cycle++;
		int size = 5000;
		int test_array[size];
		create_test_array(test_array, size);
//		printf("Starting Array:\n");
		selection_sort(test_array, size);
		verify_sorted(test_array, size);
//		array_print(test_array, size);
	}
	average_elapsed_time("selection sort");	
	return 0;
}
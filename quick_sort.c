#include <stdio.h>
#include <stdlib.h>
#include "sort_utils.h"
#include "insertion_sort.h"

int comparisons = 0;

int get_middle_pivot(int *array, int left, int right) {
	int diff = right - left;
	int p = left + diff / 2;
	return p;
}

int get_random_pivot(int *array, int left, int right) {
	int size = (right - left) + 1;
	int r = rand();
	return left + (r % size);
}

int is_mid_median(int a, int b, int c) {
	int result = 0;
	if (a >= b && c <= b)
		result = 1;
	if (c >= b && a <= b)
		result = 1;
	return result;
}

int verify_median(int x, int median, int y) {
	int x_greater_y = x >= median && median >= y;
	int y_greater_x = y >= median && median >= x;
	int median_OK = x_greater_y || y_greater_x;
	if (!median_OK) {
		printf("median not OK!");
		exit(55);
	}
	return median_OK;
}

int get_median_of_three_pivot(int *array, int left, int right) {
	int size = (right - left) + 1;
	int middle = size % 2 == 0 ? size / 2 - 1 : size / 2;
	middle += left;
	int a = array[left];
	int b = array[middle];
	int c = array[right];
	// calc median
	int median;
	if (is_mid_median(a,b,c)) {
		median = middle; // b
	} else if (is_mid_median(b,c,a)) {
		median = right; // c
	} else {
		median = left; // a
	}
	//printf("a,b,c: %d, %d, %d ---> median: %d\n", a, b, c, median);
	return median;

}

void random_quick_sort(int* array, int left, int right) {		
	if (left >= right) {
		// base case
		return;
	}
	comparisons += right - left;
	int p_idx = get_random_pivot(array, left, right);
	//verify_median(array[left], array[p_idx], array[right]);
	int p = array[p_idx];

	// put the pivot in the leftmost spot
	swap(array, p_idx, left);	

	int i = left + 1;	
	int j;
	for (j = i; j <= right; j++) {		
		if (array[j] < p) {
			swap(array, i, j);
			i++;
		}
	}
	swap(array, left, i - 1);
	random_quick_sort(array, left, i - 2);
	random_quick_sort(array, i, right);
}

void middle_quick_sort(int* array, int left, int right) {		
	if (left >= right) {
		// base case
		return;
	}
	comparisons += right - left;
	int p_idx = get_middle_pivot(array, left, right);
	int p = array[p_idx];

	// put the pivot in the leftmost spot
	swap(array, p_idx, left);	

	int i = left + 1;	
	int j;
	for (j = i; j <= right; j++) {
		if (array[j] < p) {
			swap(array, i, j);
			i++;
		}
	}
	swap(array, left, i - 1);
	middle_quick_sort(array, left, i - 2);
	middle_quick_sort(array, i, right);
}

void naive_quick_sort_first(int* array, int left, int right) {		
	if (left >= right) {
		// base case
		return;
	}
	comparisons += right - left;
	int p_idx = left;
	int p = array[p_idx];

	int i = left + 1;	
	int j;
	for (j = i; j <= right; j++) {
		if (array[j] < p) {
			swap(array, i, j);
			i++;
		}
	}
	swap(array, left, i - 1);	
	naive_quick_sort_first(array, left, i - 2);
	naive_quick_sort_first(array, i, right);
}

void naive_quick_sort_last(int *array, int left, int right) {
	if (left >= right) {
		// base case
		return;
	}
	comparisons += right - left;
	int p_idx = right;
	int p = array[p_idx];

	// put the pivot in the leftmost spot
	swap(array, p_idx, left);	

	int i = left + 1;	
	int j;
	for (j = i; j <= right; j++) {
		if (array[j] < p) {
			swap(array, i, j);
			i++;
		}
	}
	swap(array, left, i - 1);	
	naive_quick_sort_last(array, left, i - 2);
	naive_quick_sort_last(array, i, right);	
}

void median_quick_sort(int *array, int left, int right) {
	if (left >= right) {
		// base case
		return;
	}
	comparisons += right - left;
	int p_idx = get_median_of_three_pivot(array, left, right);
	int p = array[p_idx];

	// put the pivot in the leftmost spot
	swap(array, p_idx, left);	

	int i = left + 1;	
	int j;
	for (j = i; j <= right; j++) {
		if (array[j] < p) {
			swap(array, i, j);
			i++;
		}
	}
	swap(array, left, i - 1);	
	median_quick_sort(array, left, i - 2);
	median_quick_sort(array, i, right);
}

void optimized_quick_sort(int *array, int left, int right) {
	if (left >= right) {
		// base case
		return;
	}
	int size = (right - left) + 1;
	if (size < 64) {
		insertion_sort(array+left, size);
		return;
	}
	//comparisons += right - left;
	int p_idx = get_median_of_three_pivot(array, left, right);
	int p = array[p_idx];

	// put the pivot in the leftmost spot
	swap(array, p_idx, left);	

	int i = left + 1;	
	int j;
	for (j = i; j <= right; j++) {
		if (array[j] < p) {
			swap(array, i, j);
			i++;
		}
	}
	swap(array, left, i - 1);	
	optimized_quick_sort(array, left, i - 2);
	optimized_quick_sort(array, i, right);	
}
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sort_utils.h"

int* merge(int* a, int a_len, int* b, int b_len) {	
	int i = 0;
	int j = 0;
	int k = 0;
	int r_len = a_len + b_len;
	int* result = malloc(sizeof(int) * r_len);
	// at least some elements left to deal with
	while (i < a_len || j < b_len) {
		assert(k < r_len);
		// both sublists have elements, let's compare
		if (i < a_len && j < b_len) {
			if (a[i] < b[j]) {
				result[k++] = a[i++];
			} else {
				result[k++] = b[j++];
			}
		} else if (i < a_len) {
			result[k++] = a[i++];
		} else if (j < b_len) {
			result[k++] = b[j++];
		}
	}
	return result;

}

int* merge_sort(int* array, int size) {
	if (size == 0 || size == 1) {
		// alread sorted
		return array;
	}
	// for odd numbers, sublist a is larger. e.g. 9 -> a:5, b:4
	int a_len = size/2 + size % 2;
	int b_len = size/2;
	int* a = malloc(sizeof(int) * a_len);
	int* b = malloc(sizeof(int) * b_len);
	//printf("a: %d, b: %d\n", a_len, b_len);
	int i;
	int j = 0;
	for (i = 0; i < a_len; i++) {
		a[i] = array[j++];
	}
	for (i = 0; i < b_len; i++) {
		b[i] = array[j++];
	}
	//puts("------------------");
	a = merge_sort(a, a_len);
	b = merge_sort(b, b_len);
	return merge(a, a_len, b, b_len);
}
#include <stdio.h>
#include "sort_utils.h"

void selection_sort(int* array, int size) {
	int i, j;
	int iMin;
	for (j = 0; j < size - 1; j++) {
		iMin = j;
		for (i = j + 1; i < size; i++) {
			if (array[i] < array[iMin]) {
				iMin = i;
			}
		}
		if (iMin != j) {
			swap(array, j, iMin);
		}
	}
}
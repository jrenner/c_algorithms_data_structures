#include <stdio.h>
#include "sort_utils.h"

// 1 2 6 7 8  - 3 9 11 13 10 12

void insertion_sort(int* array, int size) {
	int i;
	int insert_val;
	int hole_pos;
	for (i = 0; i < size; i++) {
		insert_val = array[i];
		hole_pos = i;
		while (hole_pos > 0 && insert_val < array[hole_pos - 1]) {
			array[hole_pos] = array[hole_pos - 1];
			hole_pos--;
		}
		array[hole_pos] = insert_val;
	}
}
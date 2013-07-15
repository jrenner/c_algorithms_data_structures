#include "sort_utils.h"
#define TRUE 1
#define FALSE 0

void bubble_sort(int *array, int size) {
	int i;
	int swapped = TRUE;
	while (swapped) {		
		swapped = FALSE;
		for (i = 1; i < size; i++) {
			if (array[i-1] > array[i]) {				
				//printf("swapping [%d]: %d and [%d]: %d\n", i-1, array[i-1], i, array[i]);
				swap(array, i-1, i);
				swapped = TRUE;
			}
		}
	}
}
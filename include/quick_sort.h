#ifndef _quick_sort_h
#define _quick_sort_h
#include "insertion_sort.h"

extern int comparisons;

void naive_quick_sort_first(int* array, int left, int right);
void naive_quick_sort_last(int* array, int left, int right);
void middle_quick_sort(int* array, int left, int right);
void random_quick_sort(int* array, int left, int right);
void median_quick_sort(int* array, int left, int right);
void optimized_quick_sort(int *array, int left, int right);
int get_median_of_three_pivot(int *array, int left, int right);

#endif
#ifndef _merge_sort_h
#define _merge_sort_h

extern long inversions;

int* merge(int* a, int a_len, int* b, int b_len);
int* merge_sort(int* array, int size);

#endif
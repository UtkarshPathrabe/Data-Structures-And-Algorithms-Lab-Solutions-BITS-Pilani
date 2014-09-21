#ifndef _BOOLEAN
#define _BOOLEAN
typedef enum {FALSE=0, TRUE=1} Boolean;
#endif

extern void insertionSort_R(int arr[], int first, int last);
extern Boolean subsetSum_R(int arr[], int size, int sum);
extern void insertionSort_L(int arr[], int first, int last);
extern Boolean subsetSum_L(int arr[], int size, int sum);  

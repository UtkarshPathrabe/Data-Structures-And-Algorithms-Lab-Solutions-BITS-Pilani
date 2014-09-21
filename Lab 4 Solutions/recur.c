#include <stdio.h>
#include <stdlib.h>
#include "MyFuns.h"
#include "stops.h"

void insert_R(int arr[], int x, int size);
Boolean issubsetSum_R(int arr[], int size, int sum);

void insertionSort_R(int arr[], int first, int last){
	if(last - first > 0){
		insertionSort_R(arr, first, last - 1);
		insert_R(arr, arr[last], last - first);
	}
}

void insert_R(int arr[], int x, int size){
	int i, j, temp;
	for (j = 0; j < size; j++){
          	if (arr[j] > x)
              		break;
//          	if (arr[j] == x)
//              		return;
     	}
    	for (i = size - 1; i >= j; i--)
      	{
         	 arr[i + 1] = arr[i];
      	}
    	arr[j] = x;
}

Boolean issubsetSum_R(int arr[], int size, int sum){
	if(sum == 0){
		return TRUE;
	}
	if(sum != 0 && size == 0){
		return FALSE;
	}
	if(arr[size - 1] > sum){
		return issubsetSum_R(arr, size -1, sum);
	}
	return issubsetSum_R(arr, size - 1, sum) || issubsetSum_R(arr, size - 1, sum - arr[size - 1]);
}

Boolean subsetSum_R(int arr[], int size, int sum){
//	int size;
	Boolean x;
	if(arr != NULL){
//		size = (sizeof(arr))/(sizeof(arr[0]));
		x = issubsetSum_R(arr, size, sum);
	}else{
		x = FALSE;
	}
	return x;
}

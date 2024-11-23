#include <stdio.h>
#include "lib-J.h"
#define max_array 100000

void selectionSort(int arr[], int n);

int main() {
  int arr[max_array],n;

  printf("Inserire quanti numeri inserire:");
  n=leggi_compreso(0,max_array);
  
  for(int i=0; i<max_array; i++){
	arr[i]=cas_compreso(-100,100);
  }
	

  printf("Array non ordinato:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  selectionSort(arr, n);

  printf("Array ordinato:\n");
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

void selectionSort(int arr[], int n) {
  int i, j, min_idx;

  for (i = 0; i < n - 1; i++) {
    min_idx = i;
    for (j = i + 1; j < n; j++) {
      if (arr[j] < arr[min_idx]) {
        min_idx = j;
      }
    }
    int temp = arr[min_idx];
    arr[min_idx] = arr[i];
    arr[i] = temp;
  }
}

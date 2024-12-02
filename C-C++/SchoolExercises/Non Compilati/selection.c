void selectionSort(int arr[], int n);

int main() {
  int arr[] = {5, 2, 9, 1, 7, 4, 8, 3, 10, 6};
  int n = sizeof(arr) / sizeof(arr[0]);

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
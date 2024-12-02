#include <stdio.h>


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
  int i, j, min_indice; // dichiarazione delle variabili

  for (i=0; i<n-1; i++) { // ciclo per scorrere l'array dall'inizio alla fine
    min_indice=i; // assumo che l'elemento corrente sia il minimo
    for (j=i+1; j<n; j++) { // ciclo per trovare il minimo fra gli elementi restanti
      if (arr[j]<arr[min_indice]) { // se l'elemento corrente è minore del minimo finora trovato (< crescente; > decrescente)
        min_indice=j; // si imposta l'indice dell'elemento corrente come nuovo minimo
      }
    }
    int temp=arr[min_indice]; // si salva il valore del minimo
    arr[min_indice]=arr[i]; // si sposta l'elemento corrente nella posizione del minimo
    arr[i]=temp; // si inserisce il valore del minimo nella posizione corrente
  }
}

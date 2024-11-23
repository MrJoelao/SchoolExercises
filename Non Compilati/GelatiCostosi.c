/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>

#include "lib-J.h"

#define max_vett 10000
#define max_costo 100
#define max_soldi 15

void selectionSortz(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {

      if (array[i] > array[min_idx])
        min_idx = i;
    }

    swapz(&array[min_idx], &array[step]);
  }
  return;
}

int main() {
    int n,c,vett[max_vett], somma=0, i;

    printf("Inserire il numero di amici: ");
    n=leggi_compreso(1,max_vett);

    for(i=0; i<max_vett; i++){
        vett[i]=cas_compreso(0,max_soldi); //suppongo che ci siano amici che non prestino nulla
    }

    printf("Inserire il costo del gelato: ");
    c=leggi_compreso(1,max_costo);
    
    array_out(vett,n);
    printf("/n");
	
    selectionSortz(vett, n); //riordino array
    
    array_out(vett,n);

    for(i=0; i<0 || c>=somma; i++){
      somma+=vett[i];
      printf("%d",somma);
    }
    
    printf("Il numero minimo di amici per comprare il gelato è di: %d amici/o", i);

    printf("\n");
    return 0;
}

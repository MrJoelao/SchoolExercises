//----/* Informazioni:
/* Autore:	Joel Stephan
   Data:
   Versione: 0				 */
//----------------------------\\

//---------/*	Testo:
/*
  Scrivere un programma c che prende in ingresso da tastiera una serie di 20 numeri interi. I numeri immessi devono essere salvati all’interno di un array. 
  Una volta terminata l’immissione. Stampare a video l’array e successivamente ordinare una copia dell’array in ordine crescente. Scrivere una funzione C che permetta 
  di effettuare l’ordinamento secondo l’algoritmo selection sort. Infine stampare a video l’array ordinato su una sola riga. Per effettuare le operazioni utilizzare 
  l’aritmetica dei puntatori e le funzioni di allocazione dinamica della memoria (malloc()), non la notazione con puntatore ed indice (array[i]).
*/
//----------------------------------\\

//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>

//-----------------------\\

//---------/*	Define:
#define N 5
//---------------------\\

//----/* Funzioni:
void swap (int* a, int* b) {
    int temp = *a; //dichiaro temp e gli asseggno il valore di a
    *a = *b;	//assegno il valore di b ad a
    *b = temp;	//assegno il valore di temp (a) ad b
    
    return;
}

void sel_sort(int *vett, int n) {
    int i, j, indice_minimo;

    for (i=0; i<n-1; i++) {	// Ciclo esterno che scorre l'array fino all'elemento n-2

        indice_minimo=i;	// Trova l'elemento minimo nell'array non ordinato
        for (j=i+1; j<n; j++) {
            if (*(vett+j)<*(vett+indice_minimo)) {
                indice_minimo=j;
            }
        }

        swap((vett+indice_minimo), (vett+i));	// Scambia l'elemento minimo con il primo elemento nell'array non ordinato
    }
}


//---------------\\

//----/* Int Main:
int main(){
	//---------/*	Variabili:
	int *arr = (int *)malloc(N * sizeof(int));
	int i;
 	//-----------------------\\

 	//---------/*	Algoritmo Risolutivo:
 	for(i=0;i<N; i++){
 		scanf("%d", arr+i);
	}
	system("CLS");
	
	printf("Non ordinato: \n");
	
	int *arr_1 = (int *)malloc(N * sizeof(int));
	
	for(i=0;i<N; i++){
 		printf("%d\t", *(arr+i));
 		*(arr_1+i)=*(arr+i);
	}
	
	sel_sort(arr_1,N);
	
	printf("\nOrdinato: \n");
	
	for(i=0;i<N; i++){
 		printf("%d\t", *(arr_1+i));
	}
	
	free(arr);
	free(arr_1);
 	//----------------------------------\\

	printf("\n");
	system("PAUSE");
	return 0;
}

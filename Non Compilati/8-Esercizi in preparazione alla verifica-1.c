/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
Scrivere un programma c che prende in ingresso da tastiera una serie di 20 numeri interi. I numeri immessi devono essere salvati all’interno di un array. 
Una volta terminata l’immissione. Stampare a video l’array e successivamente ordinare una copia dell’array in ordine crescente. 
Scrivere una funzione C che permetta di effettuare l’ordinamento secondo l’algoritmo selection sort. Infine stampare a video l’array ordinato su 
una sola riga. Per effettuare le operazioni utilizzare l’aritmetica dei puntatori e le funzioni di allocazione dinamica della memoria (malloc()), 
non la notazione con puntatore ed indice (array[i]).
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>

//-------------------------/

//---------/*	Define:
#define MAX 5
//----------------------------------/

//---------/*	Struct:
//----------------------------------/

//---------/*	Funzioni:
int *allocaArray(int lung) {
    int *arr = (int *)malloc(lung * sizeof(int));
    if (arr == NULL) {
        printf("Errore nell'allocazione di memoria.");
        exit(1);
    }
    return arr;
}

void swap (int* a, int* b) {
    int temp = *a; 
    *a = *b;	
    *b = temp;
    
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

        swap(vett+indice_minimo, vett+i);	// Scambia l'elemento minimo con il primo elemento nell'array non ordinato
    }
}

void unioneArray(int *array0, int *array1, int *array2, int n){ //n è la lunghezza del singolo array (array 0 e 1)
	int i;
	for(i=0; i<n*2; i++){
		if(i<n){
			*(array2+i)=*(array0+i);
		}
		else{
			*(array2+i)=*(array1+i);
		}
	}
	return;
}

void stampaArray(int *array, int n){
	int i;
	for (i=0; i<n; i++) {
        printf("%d \t", *(array+i));
    }
    return;
}


//----------------------------------/

int main(){
	//---------/ Variabili:
	int i; 
	//----------------------/
    
	//---------/ Algoritmo Risolutivo:
	int *arr = allocaArray(MAX);
	int *arr1 = allocaArray(MAX);
	int *arr2 = allocaArray(MAX);

    printf("Inserisci 5 numeri interi:\n");
    for (i=0; i<MAX; i++) {
        scanf("%d", arr+i);
    }
    
    printf("Inserisci 5 numeri interi:\n");
    for (i=0; i<MAX; i++) {
        scanf("%d", arr+i);
    }
	
    printf("Array non ordinato:\n");
    for (i=0; i<MAX; i++) {
        printf("%d ", *(arr+i));
        *(arr_copy+i)=*(arr+i);
    }
    printf("\n");

    sel_sort(arr_copy, MAX);

    printf("Array copiato ordinato:\n");
   	stampaArray(arr_copy, MAX);
    printf("\n");
    
    printf("Array unito ordinato:\n");
    unioneArray(arr, arr_copy, arr2, MAX);
    sel_sort(arr2, MAX*2);
    stampaArray(arr2, MAX);

    free(arr);
    free(arr_copy);
    free(arr2);
	//---------------------------------/

    printf("\n");
	system("PAUSE");
	return 0;
}


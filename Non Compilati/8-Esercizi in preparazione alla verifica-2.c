/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
Scrivere un programma C che genera o prende in ingresso due array ordinati e li stampa a video. Successivamente il programma deve fondere i 
due array in un solo array ordinato e stampare l’array ottenuto a video. Implementare infine una funzione di check che verifica se un array 
è ordinato. Nelle funzioni utilizzare il passaggio di parametri per indirizzo.
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
			*(array2+i)=*(array1+i-n);
		}
	}
	return;
}

void inputArray(int *array, int n){
	int i;
	printf("Inserisci 5 numeri interi:\n");
    for (i=0; i<n; i++) {
        scanf("%d", array+i);
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
	int *arr0 = (int *)malloc(MAX * sizeof(int)); 
	int *arr1 = (int *)malloc(MAX * sizeof(int));
	int *arr2 = (int *)malloc(MAX * sizeof(int));
	
	if (arr0 == NULL || arr1 == NULL || arr2 == NULL) {
        printf("Errore nell'allocazione di memoria.");
        exit(1);
    }

    inputArray(arr0, MAX);
    inputArray(arr1, MAX);
    
    sel_sort(arr0, MAX);
    sel_sort(arr1, MAX);

    printf("Array 1 E 2:\n");
   	stampaArray(arr0, MAX);
    printf("\n");
    stampaArray(arr1, MAX);
    
    printf("\nArray unito ordinato:\n");
    unioneArray(arr0, arr1, arr2, MAX);
    sel_sort(arr2, MAX*2);
    stampaArray(arr2, MAX*2);

    free(arr0);
    free(arr1);
    free(arr2);
	//---------------------------------/

    printf("\n");
	system("PAUSE");
	return 0;
}


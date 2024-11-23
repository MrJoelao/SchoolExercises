//----/* Informazioni:
/* Autore:	Joel Stephan
   Data:
   Versione: 0				 */
//----------------------------\\

//---------/*	Testo:
/*
  Scrivere un programma C che genera o prende in ingresso due array ordinati e li stampa a video. Successivamente il programma deve fondere i due array in un solo array 
  ordinato e stampare l’array ottenuto a video. Implementare infine una funzione di check che verifica se un array è ordinato. Nelle funzioni utilizzare il passaggio 
  di parametri per indirizzo.
*/
//----------------------------------\\

//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>

//-----------------------\\

//---------/*	Define:
#define MAX 5
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

void stampa(int *array, int N){
	int i;
	for(i=0;i<N; i++){
 		printf("%d\t", *(array+i));
	}
	return;
}

void lettura(int *array){
	int i;
	for(i=0; i<MAX; i++){
		scanf("%d",array+i);
	}
	return;
}

void unioneArray(int *array0, int *array1, int *array2, int N) {
    int i;
    for (i = 0; i < N; i++) {
        *(array2 + i) = *(array0 + i);
    }
    for (i = 0; i < N; i++) {
        *(array2 + N + i) = *(array1 + i);
    }
    return;
}
//---------------\\

//----/* Int Main:
int main(){
	//---------/*	Variabili:
	int *array0 = (int *)malloc(MAX * sizeof(int)); 
	int *array1 = (int *)malloc(MAX * sizeof(int));
	int *array2 = (int *)malloc(MAX * 2 * sizeof(int));
	int i;
	//-----------------------\\

	//---------/*	Algoritmo Risolutivo:
	if (array0 == NULL || array1 == NULL ) {
        printf("Errore nell'allocazione di memoria.");
        exit(1);
    }
	
	printf("Primo array: \n");
	lettura(array0);
	
	system("CLS");
	
	printf("Secondo array: \n");
	lettura(array1);
	
	system("CLS");
		
	sel_sort(array0, MAX);
	sel_sort(array1, MAX);
	
	printf("Primo array ordinato: \n");
	stampa(array0, MAX);
	
	printf("\nSecondo array ordinato: \n");
	stampa(array1, MAX);
	
	unioneArray(array0, array1, array2, MAX);
	
	sel_sort(array2, MAX*2);
	printf("\n");
	stampa(array2, MAX*2);
	//----------------------------------\\

	printf("\n");
	system("PAUSE");
	return 0;
}

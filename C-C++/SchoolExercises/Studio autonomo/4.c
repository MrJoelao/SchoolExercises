//----/* Informazioni:
/* Autore:	Joel Stephan
   Data:
   Versione: 0				 */
//----------------------------\\

//---------/*	Testo:
/*
  
*/
//----------------------------------\\

//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>

//-----------------------\\

//---------/*	Define:

//---------------------\\

//----/* Funzioni:
void swap (double* a, double* b) {
    double temp = *a; //dichiaro temp e gli asseggno il valore di a
    *a = *b;	//assegno il valore di b ad a
    *b = temp;	//assegno il valore di temp (a) ad b
}

void bubble_sort(double vett[], int n) {
    int i, indice;

    for (i=0; i<n-1; i++) { /* Ciclo esterno che scorre l'array fino all'elemento n-2 
	(l'ultimo elemento viene già ordinato nella penultima iterazione)*/
	
        for (indice=0; indice<n-1-i; indice++) {/* Ciclo interno che scorre l'array dalla
        prima posizione fino alla posizione n-2-i (le ultime i posizioni sono già ordinate)*/

            if (vett[indice]>vett[indice+1]) {	// Se l'elemento corrente è maggiore dell'elemento
                swap(&vett[indice], &vett[indice+1]);	 // successivo, scambiamo i valori
            }
        }
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int totalSize, i, a;
    double somma;
    totalSize = nums1Size + nums2Size;
    
    double array[1000000];

    // Copia gli elementi da nums1 a array
    for (i = 0; i < nums1Size; i++) {
        array[i] = nums1[i];
    }

    int arrayIndex = nums1Size; // Inizia la copia di nums2 da questa posizione in array

    // Copia gli elementi da nums2 a array a partire da arrayIndex
    for (i = 0; i < nums2Size; i++) {
        array[arrayIndex] = nums2[i];
        arrayIndex++;
    }

    bubble_sort(array, totalSize);

    a = totalSize / 2;
    
    if (totalSize % 2 == 0) {
        somma = (array[a] + array[a - 1]) / 2.0;
    } else {
        somma = array[a];
    }

    return somma;
}

//---------------\\

//----/* Int Main:
int main(){
 //---------/*	Variabili:
	int nums1[] = {1, 2};
    int nums1Size = 2;
    int nums2[] = {4, 7};
    int nums2Size = 2;
    float result;
 //-----------------------\\

 //---------/*	Algoritmo Risolutivo:
 result = findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size);
 printf("La mediana degli array [1, 2] e [4, 7] è: %.2f\n", result);
 //----------------------------------\\

	printf("\n");
	system("PAUSE");
	return 0;
}

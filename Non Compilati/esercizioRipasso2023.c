/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>
	#include   "TheLib-J.h"

//-------------------------/

//---------/*	Define:
	#define maxArray 100
	#define max 10
	#define min 0
//----------------------------------/

//---------/ Funzioni:
int ArrayCasuale(int array[], int n){
	int i,j;
	
	for(i=0; i<=n; i++){
		array[i]=cas_compreso(min,max);
		for(j=0; j<=i; j++){
			if(cercaVal(array, i, array[i])!=-1 && j>0){
				array[i]=cas_compreso(min,max);
				i--;
			}
		}
	}
}

void stampa(int array[], int n){
	int i,j;
	for(i=0; i<=n; i++){
		printf("%d: ",array[i]);
		for(j=0; j<=array[i]; j++){
			printf("*");
		}
		printf("\n");
	}
}
//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	int numCasuali[maxArray],n;
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	printf("Inserire: ");
	n=leggi_compreso(1, maxArray);
	
	ArrayCasuale(numCasuali, n);
	
	stampa(numCasuali, n);
	
	
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

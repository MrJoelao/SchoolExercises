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

//-------------------------/

//---------/*	Define:
//----------------------------------/

//---------/*	Struct:
//----------------------------------/

//---------/*	Funzioni:
void stampa(int x, int *ptr1, int **ptr2){
	printf("1. Valore di x: %d\n",x);
	printf("1. Valore puntato da ptr1: %d\n",*ptr1);
	printf("1. Valore puntato da ptr2, che punta ptr1: %d\n", **ptr2);
	return;
}
//----------------------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	int x=42;
	int *ptr1=&x;
	int **ptr2=&ptr1;
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	printf("1. Valore di x: %d\n",x);
	printf("1. Valore puntato da ptr1: %d\n",*ptr1);
	printf("1. Valore puntato da ptr2, che punta ptr1: %d\n", **ptr2);
	
	*ptr1=20;
	
	printf("\n*ptr1=20:\n");
	stampa(x,ptr1,ptr2);
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

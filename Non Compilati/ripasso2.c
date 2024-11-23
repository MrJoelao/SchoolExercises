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
	#define MIN 0
	#define MAX 50
//----------------------------------/

//---------/ Funzioni:
int calcSomma(int a, int b){
	return a+b;
}
//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	int a,b;
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	printf("Inserisci a: ");
	a=leggi_compreso(MIN,MAX);
	
	printf("Inserisci b: ");
	b=leggi_compreso(MIN,MAX);
	
	printf("Somma: %d",calcSomma(a,b));
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

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
	#include   "TheLib-J.h"

//-----------------------\\

//---------/*	Define:

//---------------------\\

//----/* Funzioni:
int funzione(char* stringa){
	printf("%s", stringa);
}

//---------------\\

//----/* Int Main:
int main(){
 //---------/*	Variabili:
 char vecchioDuce[5] = "daje";
 char *vecchioDucePuntatore = vecchioDuce;
 char *vecchioDucePuntatorePuntatore = vecchioDucePuntatore;
 //-----------------------\\

 //---------/*	Algoritmo Risolutivo:
 funzione(vecchioDucePuntatorePuntatore);
 //----------------------------------\\

	printf("\n");
	system("PAUSE");
	return 0;
}

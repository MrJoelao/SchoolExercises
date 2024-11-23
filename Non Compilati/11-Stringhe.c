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
//----------------------------------/

//---------/*	Struct:
//----------------------------------/

//---------/*	Funzioni:
//----------------------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	char *line = read_line();
	char *word = read_line();

	//----------------------/

	//---------/ Algoritmo Risolutivo:
	if(line){
		printf("Linea: %s\n", line);
		free(line);
	}else{
		printf("Lettura della linea fallita\n");
	}
	
	if(word){
		printf("Parola: %s\n", word);
		free(word);
	}else{
		printf("Lettura della parola fallita\n")
	}
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

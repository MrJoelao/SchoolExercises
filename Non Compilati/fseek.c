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

//---------/ Funzioni:
FILE *open_file (FILE *fd, char *namefile, char *mode){
	fd=fopen(namefile, mode);
    if (fd==NULL) { 					    
        printf("ERRORE: Apertura file invalida\n");
        exit(-1); 							
    }
	return fd;
}

void close_file(FILE *fd){
	if(fclose(fd)!=0) {             
        printf("ERRORE: Chiusura file invalida\n");	
        exit(-2); 								   
    }
    return;
}
//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:

	//----------------------/

	//---------/ Algoritmo Risolutivo:

	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

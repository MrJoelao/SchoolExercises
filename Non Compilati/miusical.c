/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
/---------*/


//---------/*	Librerie:	*\---------\\

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>
	#include   "TheLib-J.h"

//-------------------------------------\\

//---------/*	Define:	*\---------\\

	#define lung_max_stringa 100
	#define num_max_stringhe 100
	
//----------------------------------\\

//---------/ Funzioni:
FILE *myFopen (FILE *fd, char *namefile, char *mode){
	fd=fopen(namefile, mode);       // apro il file temperature.txt
    if (fd==NULL) { 					    // verificando che apertura sia andata 	
        printf("ERRORE: apertura del file invalida\n"); // a buon fine. in caso contrario esce 
        exit(-1); 								  // dal programma con codice di errore -1
    }
	return fd;
}

void myFclose(FILE *fd){
	if(fclose(fd)!=0) {                     // chiude il file verificandone la buona
        printf("ERRORE: chiusura del file invalida\n");	// riuscita, in caso contrario esce dal
        exit(-2); 								   // programma con codice di errore -2
    }
    return;
    
void leggiMatrice(FILE *fd){
		
}


//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	FILE *file;
	//----------------------/
	
	//---------/ Algoritmo Risolutivo:
	file=myFopen(file,"canzoni.txt", "r");
	
	
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}



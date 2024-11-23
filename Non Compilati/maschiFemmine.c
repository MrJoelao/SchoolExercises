/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
Dato un file di testo amici.txt, le cui righe rappresentano ciascuna i dati di una persona secondo il seguente formato (tracciato record):

 – cognome: al più 30 caratteri 
 – uno o più spazi
 – nome: al più 30 caratteri
 – uno o più spazi
 – sesso: un carattere (’M’ o ’F’)
 – uno o più spazi
 – anno di nascita

 Scrivi un programma che legga riga per riga i dati dal file e li ponga in un array di persone. Quindi  scrivi due nuovi file maschi.txt e femmine.txt 
 contenenti i record relativi ad amici/amiche disposti in ordine di età
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>

//-------------------------/

//---------/*	Define:
#define MAXC 30+1
//----------------------------------/

//---------/*	Struct:
typedef struct amico {
    char cognome[50];
    char nome[50];
    char sesso;
    int eta;
	}Amico;
	
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
	FILE *fd0, *fd1, *fd2;
	char parola[MAXC];
	Amico dati;
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	open_file(fd0,"amici.txt", "r");
	open_file(fd1,"maschi.txt", "w");
	open_file(fd2,"femmine.txt", "w");
	
	while(!feof(fd0)) {
    	fscanf(fd0, "%s %s %c %d\n", dati.cognome, dati.nome, &dati.sesso, &dati.eta);
    }
    
    printf("%s %s %c %d", dati.cognome, dati.nome, dati.sesso, dati.eta);
	
	close_file(fd0);
	close_file(fd1);
	close_file(fd2);
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

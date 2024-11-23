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
FILE *myFopen(char *nomeFile, char *tipo){
	FILE *fd=fopen(nomeFile, tipo);
	if(fd==NULL){
		printf("errore nell'apertura del file");
		exit(1);
	}
	return fd;
}

void myFclose(FILE *fd){
	if(fclose(fd)!=0){
		printf("errore nella chiusura del file");
		exit(2);
	}
}

int palindromo(char testo[], int lunghezza){
	int i=0,flag=1;
	do{
        if (testo[i]!=testo[lunghezza-1-i]) {
            flag=0;
        }
    }while(i<lunghezza && flag==1);
}
//---------------\\

//----/* Int Main:
int main() {
 //---------/*	Variabili:
	FILE *file;
    char carattere, *testo = NULL;
    long lunghezza = 0, i = 0;
 //-----------------------\\

    // Apri il file in lettura utilizzando myFopen
    file = myFopen("input.dat", "rb");

    // Determina la lunghezza del file
    fseek(file, 0, SEEK_END);
    lunghezza = ftell(file);
    rewind(file);

    // Leggi il contenuto del file nel buffer
    fread(testo, 1, lunghezza, file);

    // Chiudi il file utilizzando myFclose
    myFclose(file);

    // Stampa il risultato
    if (palindromo(testo, lunghezza)) {
        printf("Il testo nel file è un palindromo.\n");
    } else {
        printf("Il testo nel file non è un palindromo.\n");
    }


	printf("\n");
	system("PAUSE");
	return 0;
}



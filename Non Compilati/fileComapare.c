/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
Siano dati due file contenenti testo. Si realizzi un programma che individui e scriva un terzo file "risultati.txt" le parole che compaiono in entrambi i file.
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
	*FILE fd0, fd1, out;
	//----------------------/
	open_file(fd0,"file0.txt", "r");
	open_file(fd1,"file1.txt", "r");
	open_file(out,"ris.txt", "w");
	//---------/ Algoritmo Risolutivo:
	
	
	
	
	//---------------------------------/
	close_file(fd0);
	close_file(fd1);
	close_file(out);

	printf("\n");
	system("PAUSE");
	return 0;
}

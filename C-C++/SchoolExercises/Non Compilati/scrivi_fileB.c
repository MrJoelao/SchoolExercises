/*---------/ Informazioni:
	Autore: Joel Stephan
	Data:
	Versione: 0
/------------------------*/
/*---------/ Testo:
/---------*/

//---------/*	Librerie:
#include <stdio.h>
#include <stdlib.h>
//-------------------------/

//---------/*	Define:
#define MAXPAROLA 100+1
//----------------------------------/

//---------/ Funzioni:
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
//----------------------/

//----/* Int Main:
int main() {
    //---------/ Variabili:
    FILE *fd;
    char pali[MAXPAROLA],parola1[MAXPAROLA];
    //----------------------/

    //---------/ Algoritmo Risolutivo
    fd=myFopen("input.dat", "wb");

    fprintf(stdout, "Inserire la parola: ");
    fscanf(stdin, "%s", pali);
    fprintf(fd, "%s", pali);
    myFclose(fd);

    fd=myFopen("input.txt", "rb");
    fscanf(fd, "%s", parola1);
    printf("Verifica: %s\n", parola1);
    myFclose(fd);
	
	//---------------------------------/
	
	printf("\n");
	system("PAUSE");
	return 0;
}

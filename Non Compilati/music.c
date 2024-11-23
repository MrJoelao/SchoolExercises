/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define WORD 20

FILE * myFopen (char *nameFile, char *mode){
	FILE *fd=fopen(nameFile, mode);		
	if(fd==NULL){
		printf("\nErrore nell'apertura del file");
		exit(1);
	}
	return fd;
	
}

void myFclose(FILE *fd){
	if(fclose(fd)!=0){
		printf("\nErrore nella chiusura del file");
		exit(2);
	}
	return;
}

void split(char *stringa, char elencoParole[][MAX]){
	char *token;
	int i=0;
	token = strtok(stringa, " ");
	while (token != NULL){
    	strcpy(elencoParole[i++], token);
    	token = strtok(NULL, " ");
		}	
	return;
}

void rimuoviInvio(char *stringa) {
    int lunghezza = strlen(stringa);
    if (stringa[lunghezza - 1] == '\n') {
        stringa[lunghezza - 1] = '\0';
    }
}


int main(){
	//dichiarazione delle variabili
	FILE *fd;
	char stringhe[MAX][MAX], finale[MAX*MAX];
	int N, M, lenStringa[MAX];
	int i=0, j=0, totaleParole=0;

	//algoritmo risolutivo
	fd=myFopen("canzoni.txt", "r");
	
	fscanf(fd,"%d",&N);
	fscanf(fd,"%d",&M);
	
	for(i=0;i<N;i++){
		fscanf(fd,"%d",&lenStringa[i]);
		fgets(stringhe[i], MAX, fd);
		rimuoviInvio(stringhe[i]);
	}
	
	printf("\nN = %d", N);
	printf("\nM = %d", M);
	printf("\n");
	
	for(i=0;i<N;i++){
		printf("\n%d", lenStringa[i]);
		printf("\t%s", stringhe[i]);
	}	
	
	myFclose(fd);	
	
	printf("\n");			

	char elencoParole[MAX][MAX];
	split(stringhe[0], elencoParole);

	for(i=1; i<N; i++)
		strcat(finale, stringhe[i]);
	
	printf("%s",finale);
	
	char elencoParole2[MAX][MAX];
	split(finale, elencoParole2);
	
	for(i=1;i<=N;i++)
		totaleParole+=lenStringa[i];
	
	//for(i=0;i<totaleParole;i++)
	//	printf("%s\n", elencoParole2[i]);
	
	int cont;
	for(i=0;i<lenStringa[0];i++){
		cont=0;
		for(j=0;j<totaleParole;j++)
			if(strcmp(elencoParole[i], elencoParole2[j])==0)
				cont++;
		printf("\n%s\t\t%d",elencoParole[i],cont);
		
	}
	
	printf("\n");
	system("PAUSE");
	return 0;
}

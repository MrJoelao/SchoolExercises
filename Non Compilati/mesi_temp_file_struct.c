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
	#define maxMese 10
	#define nmesi 12
//----------------------------------/

//---------/ struct:
	typedef struct meteo{
		char mese[maxMese];
		float TMax;
		float TMin;
	}Meteo;
//----------------------/

//---------/ Funzioni:
void leggiTemp(Meteo *anno, FILE *fd){
	int i;
	for(i=0; i<nmesi; i++){
		fscanf(fd,"%s",anno[i].mese);
		fscanf(fd,"%f",&anno[i].TMax);
		fscanf(fd,"%f",&anno[i].TMin);
	}
}

void stampa(Meteo *anno){
	int i;
	for(i=0; i<nmesi; i++){
		printf("%s: %.2f %.2f",anno[i].mese,anno[i].TMax,anno[i].TMin);
	}
}
//----------------------/


//----/* Int Main:
int main(){
	//---------/ Variabili:
	Meteo anno[nmesi];
	FILE *fd;
	int i;
	//----------------------/
	
	//---------/ Algoritmo Risolutivo:
	fd=open_file(fd,"tempMesi.txt","r");
	leggiTemp(anno, fd);
	close_file(fd);
	
	stampa(anno);
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

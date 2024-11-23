	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>
	#include   "TheLib-J.h"

	#define   max_arr   12
	#define   max_parola   120

//---------/ Funzioni:
FILE *myFopen (FILE * fd, char * namefile, char * mode){
	fd=fopen(namefile, mode);       // apro il file temperature.txt
    if (fd==NULL) { 					    // verificando che apertura sia andata 	
        printf("Errore nell'apertura del file\n"); // a buon fine. in caso contrario esce 
        exit(-1); 								  // dal programma con codice di errore -1
    }
	return fd;
}

void myFclose(FILE *fd){
	if(fclose(fd)!=0) {                     // chiude il file verificandone la buona
        printf("errore nella chiusura del file");	// riuscita, in caso contrario esce dal
        exit(-2); 								   // programma con codice di errore 1
    }
    return;
}

void leggiArray(FILE *fd, float *arr){
	int i=0;
	
	for(i=0; i<max_arr; i++){
		fscanf(fd,"%f",&arr[i] );
	}
}

//----/ Int Main:
int main(){
	//---------/ Variabili:
	char mesi[max_arr]={'a','b','c','d','e','f','g','h','i','l','m','n'};
	float max_temp[max_arr], min_temp[max_arr];
	FILE *temperature;

	//---------/ Algoritmo Risolutivo:
	temperature=myFopen(temperature,"input.txt", "r");
	
    leggiArray(temperature,min_temp);
	leggiArray(temperature,max_temp);
	
	
	printf("Temperature minime: ");
	array_out_f(min_temp,max_arr);
	printf("Temperature massime: ");
	array_out_f(min_temp,max_arr);

    myFclose(temperature);

	printf("\n");
	system("PAUSE");
	return 0;
}


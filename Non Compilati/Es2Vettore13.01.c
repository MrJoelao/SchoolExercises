/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"
#define max 5
int main(){
	//dichiarazione variabili
	int base[max],esponente[max],risultato[max],i;
	//algoritmo risolutivo
	
	for(i=0; i<max; i++){
		base[i]=rand() % 6;
		printf("Base n%d=%d\n",i+1,base[i]);
	}
	for(i=0; i<max; i++){
		esponente[i]=rand() % 6;
		printf("Esponente n%d=%d\n",i+1,esponente[i]);
	}
	
	printf("\nRisultati:");
	for(i=0; i<max; i++){
		printf("\n%d^%d=%d",base[i],esponente[i],calc_pot(base[i],esponente[i]));
	}
	
	
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

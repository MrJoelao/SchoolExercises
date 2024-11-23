/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"
#define cas_max 99
#define cas_min 10
#define arrayMax 15

void caricamento(int num1[], int max, int min){
	for(int i=0; i<arrayMax; i++)
		num1[i]=cas_compreso(min,max);
	return;
}

int main(){
	//dichiarazione variabili
	int num1[arrayMax],num2;
	//algoritmo risolutivo
	printf("Inserire un numero: ");
	num2=leggi_compreso(0,99);
	
	
	caricamento(num1, cas_max, cas_min);
	for(int i=0; i<arrayMax; i++){
		if(num1[i]<num2){
			
		}
	}
		
	
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

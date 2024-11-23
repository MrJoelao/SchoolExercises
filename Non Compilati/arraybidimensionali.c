/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TheLib-J.h"


#define max_riga 5
#define max_colonna 5
#define max_cas	100
#define min_cas	1

int main(){
	//dichiarazione variabili
	int ArrBi[max_riga][max_colonna],i,j,val,flag=0,max,min;
	//algoritmo risolutivo
	
	for(i=0; i<max_riga; i++){
		for(j=0; j<max_colonna; j++){
			ArrBi[i][j]=cas_compreso(min_cas, max_cas);
		}
	}
	
	printf("Array generato automaticamenete: \n");
		
	for(i=0; i<max_colonna; i++){
		for(j=0; j<max_riga; j++){
			printf("%d\t",ArrBi[i][j]);
		}
		printf("\n");
	}
	
	printf("Inserire il valore da cercare: ");
	val=leggi_compreso(min_cas,max_cas);
	
	max=ArrBi[0][0];
	min=ArrBi[0][0];
	
	for(i=0; i<max_colonna; i++){
		for(j=0; j<max_riga; j++){
			if(ArrBi[i][j]==val){
				flag=1;
			}
			if(ArrBi[i][j]>max){
				max=ArrBi[i][j];
			}
			if(ArrBi[i][j]<min){
				min=ArrBi[i][j];
			}
		}
	}

	if(flag=1){
		printf("Elemento trovato\n");
	}
	else{
		printf("elemento non trovato\n");
	}
	printf("Massimo valore trovato: %d \nMinimo valore trovato: %d ",max,min);
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

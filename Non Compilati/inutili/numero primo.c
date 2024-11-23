/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	//dichiarazione variabili
	int numero,i,j,primo=0;

	//algoritmo risolutivo
	printf("inserisci 10 numeri e ti notifichero' quando un valore da te inserito e' primo\n");
	for( i=1 ; i<=10 ; i++ ){
		printf("Inserire un valore:");
		scanf("%d",&numero);
		primo=0;
		for(j=2; j<=numero/2 ;j++){
			if(numero%j==0){
				primo=1; 
			}	
		}
		if(primo==0){
			printf("numero primo");
		}
	}
	
	if(primo=0){
		printf("tra i 10 numeri inseriti, nessuno era primo");
	}
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

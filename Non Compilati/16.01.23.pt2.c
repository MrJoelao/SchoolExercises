/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"
#define max 100000
int main(){
	//dichiarazione variabili
	int n_numeri,num0[max],num1[max],uguali=0,val_uguale,ripete=0,non_presenti[max],diversi[max],i,j;
	//algoritmo risolutivo
	printf("Quanti numeri vuoi inserire?: ");
	/*utilizzo la funzione "leggi compreso" in modo che sia maggiore di zero e 
	 sotto al valore massimo stabilito*/
	n_numeri=leggi_compreso(0,max);
	
	for(i=0; i<n_numeri; i++){
		printf("Ciclo %d\nPrimo vettore: ",i+1);
		 scanf("%d",&num0[i]);
		printf("Secondo vettore: ");
		 scanf("%d",&num1[i]);
		 
		if(num0[i]==num1[i]){
				uguali++;
		}
	}
	
	for(i=0; i<n_numeri; i++){
		for(j=1; j<n_numeri; j++){
			if(num0[i]==num1[j]){
				val_uguale=1;
			}
			else{
				diversi[i]=num0[i];
			}		
		}
	}
	
	for(i=0; i<n_numeri; i++){
		for(j=0; j<n_numeri; j++){
			if(num0[i]==num0[j] || num1[i]==num1[j]){
				ripete++;
			}		
		}
	}
	
	
	if(uguali==n_numeri){
		printf("I due vettori sono identici\n");
	}
	else{
		if(uguali>0) {
			printf("Hanno almeno un valore in comune nella stessa posizione\n");	
		}
		
		printf("Numeri del primo vettore non contenuti nel secondo: ");
		for(i=0; i<n_numeri; i++){
			printf("\t%d",diversi[i]);
		}
	}
	
	if(val_uguale==1){printf("Hanno almeno un valore in comune che non e' nella stessa posizione\n");}
	
	if(ripete>n_numeri){
		printf("\nNel primo vettore o nel secondo ci sono valori ripetuti\n");
		} 
	

	
	printf("\n");
	system("PAUSE");
	return 0;
}

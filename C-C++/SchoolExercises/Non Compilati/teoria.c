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

void caricamento(int array[]){
	for(int i=0; i<max; i++)
		array[i]=cas_compreso(0,10);
	return;
}

void output(int array[]){
	for(int i=0; i<max; i++)
		printf("%d\t",array[i]);
	return;
}

void add_vett(int array0[], int array1[],int ris_array[]){
	for(int i=0; i<max; i++)
		ris_array[i]=array0[i]+array1[i];
}

void scambio_variabili(int *a,int *b){
int temp = *a;
    *a = *b;
    *b = temp;
}


int main(){
	//dichiarazione variabili
	int vett0[max],vett1[max],ris_vett[max],a=10,b=6;
	int *p, *q;
	
	//algoritmo risolutivo
	printf("Somma vettori: \n");
	srand(time(NULL));
		//1:
		caricamento(vett0);
		output(vett0);
	
	printf("\n");
	
		//2:
		caricamento(vett1);
		output(vett1);
		
	printf("\n\n");
		
	//sommo i due vettori :)
	add_vett(vett0,vett1,ris_vett);
	
	//output risultato
	output(ris_vett);
	
	p=&a;
	q=&b;
	printf("\n\nScambio variabili: \nA:");
	printf("\n Contenuto: %d",a);
	printf("\n Indirizzo: %d", &a);
	printf("\n Contenuto: %d",*p);
	printf("\n Indirizzo: %d", p);
	
	printf("\nB:");
	printf("\n Contenuto: %d",b);
	printf("\n Indirizzo: %d", &b);
	printf("\n Contenuto: %d",*q);
	printf("\n Indirizzo: %d", q);
	
	
	printf("\n\nPre scambio:");
	printf("\n Variabile a (10): %d",a);
	printf("\n Variabile b (-4): %d",b);
	scambio_variabili(&a, &b);
	printf("\nDopo lo scambio:");
	printf("\n Variabile a (10): %d",a);
	printf("\n Variabile b (-4): %d",b);
	
	
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

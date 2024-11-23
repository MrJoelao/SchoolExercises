/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	float n1,n2;


	//algoritmo risolutivo
	printf("Dimmi un numero, numero 1:\n");
	scanf("%f",&n1);
	printf("Dimmi un numero, numero 2:\n");
	scanf("%f",&n2);
	
	//verifica dei due numeri positivi o negativi
	if(n1>0){
	printf("Il primo numero inserito e' positivo e ");
	}
	else{
		if(n1==0){
		printf("il primo numero, zero, non e' ne positivo ne negativo e ");}
		else{
		printf("Il primo numero inserito e' negativo e ");}	
	}
	if(n2>0){
	printf("il secondo numero inserito e' positivo.");
	}
	else{
		if(n2==0){
		printf("il secondo numero, zero, non e' ne positivo ne negativo");}
		else{
		printf("il secondo numero inserito e' negativo.");}
	}

	printf("\n");
	system("PAUSE");
	return 0;
}

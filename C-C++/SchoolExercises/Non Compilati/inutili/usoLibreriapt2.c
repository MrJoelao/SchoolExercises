/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"
int main(){
	//dichiarazione variabili
	int num0,num1,mcd=0,i,minimo;

	//algoritmo risolutivo
	printf("Numero 1: ");
	scanf("%d",&num0);
	printf("Numero 2: ");
	scanf("%d",&num1);
	
	printf("Il massimo comun divisore e':%d",calc_mcd(num0,num1));	

	printf("\n");
	system("PAUSE");
	return 0;
}

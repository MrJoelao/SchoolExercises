/*
Autore: Joel Stephan
Data: 23/09/22
Versione: 0
Testo: Es in classe:
3) Scrivere un algoritmo che, letto in input il prezzo in euro, ne calcoli il valore in lire (1€=1936,27)
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	float euro,cambio, lire;
	cambio=1936,27;

	//algoritmo risolutivo
	printf("Dimmi il valore in euro \n");
	scanf("%f",&euro);
	
	lire=(euro)*(cambio);
		
	printf("%.2f?, Il suo valore in lire e':%.2f",euro,lire);	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

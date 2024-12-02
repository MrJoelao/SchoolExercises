/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"
#define min 1
#define max 30
int main(){

	//algoritmo risolutivo
	srand(time(0));
	
	int n, i, passi = 0;
  	int mattonelle[100000]; // Dichiarazione dell'array di mattonelle

  	// Lettura della quantità di mattonelle
  	printf("Numero mattonelle: ");
  	n=leggi_compreso(1, 200);

  	// Lettura dei valori sulle mattonelle
  	for (i = 0; i < n; i++) {
    	mattonelle[i]=num_cas(1, 20);
 	 }
 	 
 	for (i = 0; i < n; i++) {
    	printf("%d: %d\n",i+1,mattonelle[i]);
 	 }
	
	// Inizio del ciclo per contare i passi
  	i = n - 1; // Iniziamo a contare dalla fine
 	while (i >= 0) {
		passi++; // Aumentiamo di 1 i passi
   		i--; // Andiamo alla mattonella successiva
   			while (i >= 0 && mattonelle[i] >= mattonelle[i + 1]) {
     			i--; // Saltiamo le mattonelle con valori non crescenti
    				passi++; // Aumentiamo di 1 i passi
    		}
  }
	
	printf("%d\n", passi);
	
	printf("\n");
	system("PAUSE");
	return 0;
}

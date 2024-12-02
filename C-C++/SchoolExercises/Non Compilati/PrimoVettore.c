/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#define max 7

int main(){
	//dichiarazione variabili
	int i;
	float somma=0,temperature[max];
	
	
	//algoritmo risolutivo
	
	 //ciclo input dati 
	for(i=0; i<max; i++){
		printf("Inserisci la %d temperatura: ",i+1);
		scanf("%d",&temperature[i]);	
	}
	//ciclo output dati normale
	printf("\nOutput normale:\n");
	for(i=0; i<max; i++){
		printf("Temperatura inserita nel %d giorno: %d\n",i+1,temperature[i]);
		somma=somma+temperature[i];
	} 
	//ciclo output dati al contrario
	printf("\nOutput al contrario:\n");
	for(i=max-1; i>=0; i--){
		printf("Temperatura inserita nel %d giorno: %d\n",i,temperature[i]);
	}
	printf("\nMedia: %d",somma/max);
	                                              

	printf("\n");
	system("PAUSE");
	return 0;
}

/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h>

int calc(int volte){
	//dichiarazione variabili
	int volte,i;
	float media=0,num;

	//algoritmo risolutivo
	volte=leggi_maggiore(0);
	
	for(i=volte;i>=1;i--){
		printf("Inserire un numero, valori rimanenti: %d\n",i);
		scanf("%f",&num);
		
		while(num<0){
			printf("Inserire un numero maggiore di zero\n");
			printf("Inserire un valore\n");
			scanf("%f",&num);	
		}
		
		media=media+num;
	}
	media=media/volte;
	return media;
}
 
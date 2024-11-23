/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define max 20

int main(){
	//dichiarazione variabili
	int numeriCas[max],nPari[max],nDispari[max],i;
	//algoritmo risolutivo
	for(i=0; i<=max; i++){
		numeriCas[i]=rand()%100-0;
		printf("Numero casuale: %d\n",numeriCas[i]);
	}
	
	for(i=0; i<=max; i++){
		
		if(numeriCas[i]%2==0){
			numeriCas[i]=nPari[i];
		}
		else{
			numeriCas[i]=nDispari[i];
		}
	}
	
	printf("\n");
		
	for(i=0; i<max; i++){
		printf("Numeri pari %d\n",nPari[i]);
	}
	for(i=0; i<max; i++){
		printf("Numeri dispari %d\n",nPari[i]);
	}
	
	printf("\n");
	system("PAUSE");
	return 0;
}

/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TheLib-J.h"

void genera_numeri_casuali(int array[], int size, int min, int max){
    int i;
    srand(time(NULL));
    for (i = 0; i < size; i++) {
        array[i] = rand() % (max - min + 1) + min;
    }
}

int main(){
	//dichiarazione variabili
	int num[120],i;

	//algoritmo risolutivo
	for(i=0; i<15; i++){
		printf("Num: %d",genera_numeri_casuali(num, 120, 1, 60));
	}
	
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){
	//dichiarazione variabili
	//algoritmo risolutivo

	printf("Dimensione di uno short:  %d\n",sizeof(short));
	printf("Dimensione di uno int:  %d\n",sizeof(int));
	printf("Dimensione di uno long:  %d\n",sizeof(long));
	printf("Dimensione di uno float:  %d\n",sizeof(float));
	printf("Dimensione di uno double:  %d\n",sizeof(double));
	
	printf("il minimo valore di uno short e':%d\n",SHRT_MIN);
	printf("il massimo valore di uno short e':%d\n",SHRT_MAX);
	printf("il minimo valore di uno int e':%d\n",INT_MIN);
	printf("il massimo valore di uno int e':%d\n",INT_MAX);
	printf("il minimo valore di uno long e':%d\n",LONG_MIN);
	printf("il massimo valore di uno long e':%d\n",LONG_MAX);


		
	printf("\n");
	system("PAUSE");
	return 0;
}

/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"
#define maxArray 15

int main(){
	//dichiarazione variabili
	int array[maxArray],max=0,min=101,pmax,pmin;
	//algoritmo risolutivo
	for(int i=0; i<maxArray; i++){
		array[i]=cas_compreso(1,100);
		if(array[i]>max){
			max=array[i];
			pmax=i;
		} 
		if(array[i]<min){
			min=array[i];
			pmin=i+1;
		}
		
	}
	
	for(int i=0; i<maxArray; i++){
		printf("%d: %d\n",i+1,array[i]);
	}
	printf("\nMax: %d, %d\nMin: %d, %d",max,pmax,min,pmin);
	
	printf("\n");
	system("PAUSE");
	return 0;
}

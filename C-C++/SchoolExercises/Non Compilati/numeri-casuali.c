/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define vMax 10
int main(){
	//dichiarazione variabili
	int random[vMax];
	//algoritmo risolutivo
	srand(time(0));
	
	for(int i=0; i<vMax; i++){
		random[i]=rand()%10;
		for(int j=0; j<i; j++){
			if(random[i]==random[j])
			i--;
		}
	}
	
	for(int i=0; i<vMax; i++){
		printf("%d ",random[i]);
	}
	
	printf("\n");
	system("PAUSE");
	return 0;
}

/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	int N,i,X;

	//algoritmo risolutivo
	printf("Da quale numero vuoi iniziare?:");
	scanf("%d",&X);
	printf("Quanti numeri vuoi stampare dopo il %d?, ",X);
	
	
	//ciclo verifica dati inseriti
	do{
		printf("Il valore inserito deve essere maggiore di zero:");
		scanf("%d",&N);
	} while(N<=0);
	
	
	//ciclo N numeri dopo X
	for(i=X+1; i<=X+N; i++){
		printf("%d\n",i);}	
	
	printf("\n");
	system("PAUSE");
	return 0;
}
 
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
	int n_macchinette,i;

	//algoritmo risolutivo
	printf("Inserisci il numero di macchinette: ");
	scanf("%d",&n_macchinette);
	
	for( i=1; i<=n_macchinette; i++){
		printf("ciclo %d\n",i);
	}

	printf("\n");
	system("PAUSE");
	return 0;
}

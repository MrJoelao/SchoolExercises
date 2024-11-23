/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
int fat(int num){
	int i, fattoriale =1;
	for(i=2; i<=num; i++)
	return fattoriale;
}

int main(){
	//dichiarazione variabili
	int i,f, j, riga;

	//algoritmo risolutivo
	printf("Indica il numero di righe:");
	scanf("%d",&riga);
		//verifica del dato: riga
		while(riga<=0){
			printf("\nErrore: indica un numero maggiore di zero!");
			scanf("%d",&riga);
		}
		
	for( i=0; i<=riga; i++){
		for(j=1; j<=i; j++){
			printf("%d\t",fat(i)/(fat(j)*fat(i-j)));
		}
		printf("\n");
	}



	printf("\n");
	system("PAUSE");
	return 0;
}

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
	int n, i, j,q=1;

	//algoritmo risolutivo
	printf("Quante colonne?\n");
		scanf("%d",&n);
	for (i = 1; i <= n; i++) {
	         for(j=1; j<=i; j++){
		        printf("%d.",q);
		        q=q+1;
				}
		printf("\n");
	}

		
     
     


	printf("\n");
	system("PAUSE");
	return 0;
}
	         

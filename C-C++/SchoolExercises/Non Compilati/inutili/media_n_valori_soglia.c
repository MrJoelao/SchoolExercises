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
	int n,i;
	float media,num,s;
	media=0;

	//algoritmo risolutivo
	
	printf("Di quanti numeri vuoi fare la media?\n");
	//verifica 
	do{
		printf("Il valore deve essere maggiore di zero:");
		scanf("%d",&n);
	} while(n<=0);
	
	printf("Valore di soglia?:");
	scanf("%f",&s);
	
	i=n;
	
	//Ciclo
	for(i=n;i>=1;i--){
		printf("\nInserire un numero, valori rimanenti: %d\n",i);
		scanf("%f",&num);
		
		if(num>s){	
		
			printf("Valore preso!\n");
			media=media+n;
			}
		
		
	}
	media=media/s;
	printf("La media dei numeri inseriti e' %.2f",media);
	
	printf("\n");
	system("PAUSE");
	return 0;
}
 
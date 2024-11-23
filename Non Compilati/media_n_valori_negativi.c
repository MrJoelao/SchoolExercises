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
	int volte,i;
	float media=0,num;

	//algoritmo risolutivo
	
	printf("Di quanti numeri vuoi fare la media?\n");

	do{
		printf("Il valore deve essere maggiore di zero:\n");
		scanf("%d",&volte);
	} while(volte<=0);
	
	i=volte;
	
	//Ciclo
	for(i=volte;i>=1;i--){
		printf("Inserire un numero, valori rimanenti: %d\n",i);
		scanf("%f",&num);
		
		if(num<0){	
			media=media+num;	
		}
		
		
	}

	printf("La media dei numeri inseriti e' %.2f",media=media/volte);
	
	printf("\n");
	system("PAUSE");
	return 0;
}
 
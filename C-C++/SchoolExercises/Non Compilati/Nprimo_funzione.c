/*
Autore: Joel Stephan
Data: 06/12/2022
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>

int isPrime(int num){
	int i,primo=0;
	for(i=2; i<num && primo==0; i++)
    {
        if(num%i==0)
            primo=1;
    }
     
    return primo;
}


int main(){
	//dichiarazione variabili
	int i,numero;

	//algoritmo risolutivo
	do{
		//input numero
		printf("Inserisci un numero: ");
			scanf("%d",&numero);
			
			//chiamata funzione "isPrime" con un if: =0 primo, =!0 non primo
		if(isPrime(numero)==0){
			printf("Il numero inserito e' primo\n");
		}
		else{
			printf("Il numero inserito non e' primo\n");
		}
	}while(numero!=0);
	
	printf("\n");
	system("PAUSE");
	return 0;
}

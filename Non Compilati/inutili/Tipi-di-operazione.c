/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
	//dichiarazione variabili
	float n1, n2, ris;
	char operazione;

	//algoritmo risolutivo
	printf("Inserisci 2 numeri per svolgere operazione: ");
	scanf("%f %f",&n1,&n2);
	fflush(stdin);
	printf("Inserisci operatore per svolgere operazione: ");
	scanf("%c",&operazione);
	
	switch(operazione){
		case '+':
			ris=n1+n2;
			break;
		case '-':
			ris=n1-n2;
			break;
		case '*':
			ris=n1*n2;
			break;
		case '/':
			if(n2=!0){
			ris=n1/n2;
		}
			break;
		case 'pot':
			ris=pow(n1,n2);
			break;
		case '@':
			ris=abs(n1);
			break;
		case 'perc':
			ris=n1/100*n2;
			break;
	
		default:
			printf("Operatore inserito non valido");	
	}
	
	if(n2==0 && operazione=='/')
		printf("Non e possibile eseguire una divisione per 0");
	else
	printf("Il risultato e': %.2f",ris);

	printf("\n");
	system("PAUSE");
	return 0;
}

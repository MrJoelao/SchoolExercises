/*
Autore: Joel Stephan
Data:
Versione:
Testo: acquisire 3 numeri interi da tastiera e determini, stampando un mess opporuno, quale dei tre numeri è maggiore
Input: n1: 1° numero intero
	   n2: 2° numero intero
	   n3: 3° numero intero
Output:
maggiore
nx: "x" sarà uno dei tre numeri

1. dichiaro le variabili: n1, n2, n3 e maggiore
2. prendo n1,n2,n3 
3. metto che la variabile "maggiore" è uguale a "n1"
4. verifico che "maggiore" sia maggiore di "n2"

	4.1 VERO: Verifico che "maggiore" sia più grande di n3
		4.12 VERO: n1 è il numero piu grande, stampo al utente "n1"
		4.13 FALSO: n3 è il numero piu grande, stampo al utente "n3"
		
	4.2 FALSO: "maggiore"="n2"
		Verifico che "maggiore" sia più grande di n3
			4.22 VERO: n2 è il numero piu grande, stampo al utente "n2"
			4.23 FALSO: n3 è il numero piu grande, stampo al utente "n3"
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	int n1,n2,n3,maggiore;

	//algoritmo risolutivo
	printf("Dimmi 3 numeri e ti calcolero' il maggiore\n");
		//Primo numero
	printf("Primo numero:\n");
	scanf("%d",&n1);
		//Secondo numero	
	printf("Secondo numero:\n");
	scanf("%d",&n2);
		//Terzo numero	
	printf("Terzo numero:\n");
	scanf("%d",&n3);
	
		//Assegno a maggiore n1
	maggiore=n1;
	
	if(maggiore>n2){
		if(maggiore>n3){
			printf("Il numero piu' grande fra i tra e': %d",n1);}
		else
			printf("Il numero piu' grande fra i tra e': %d",n3);
}		
	else{

	maggiore=n2;
		
		if(maggiore>n3){
			printf("Il numero piu' grande fra i tra e': %d",n2);}
		else
			printf("Il numero piu' grande fra i tra e': %d",n3);
	}			
	printf("\n");
	system("PAUSE");
	return 0;
}

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
	int num0,num1,mcm=0,i,minimo;

	//algoritmo risolutivo
	printf("Programma per calcolare, su due numeri inseriti dall'utente, mcm in modo automatico.\n\nEsempio:\n-\nNumero 1: 8\nNumero 2: 4\nL'MCM tra i due numeri inseriti, 8 e 4, e': 8\n-\n\n");
	printf("Numero 1: ");
	scanf("%d",&num0);
	printf("Numero 2: ");
	scanf("%d",&num1);


	//algoritmo risolutivo
	if(num0<num1){
		minimo=num0;}
	else{
		minimo=num1;}
			
	for( i=1; i<=minimo; i++){
		if(num0%i==0 && num1%i==0){
				mcm=num0*num1/i;
		}
	}
	system ("cls");
	//output
	printf("L'MCM tra i due numeri inseriti, %d e %d, e': %d\n",num0,num1,mcm);	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

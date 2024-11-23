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
	int num1,num2,somma;

	//algoritmo risolutivo
	printf("digita un numero: \n");
	scanf("%d", &num1); 
	printf("digita un secondo numero: \n");
	scanf("%d", &num2);
	
	if (num1%2==0 && num2%2==0){
		somma=num1+num2;
		printf("La loro somma e': %d",somma); }
	else {
		somma=num1*num2;
		printf("Il loro prodotto e': %d",somma); }

	printf("\n");
	system("PAUSE");
	return 0;
}

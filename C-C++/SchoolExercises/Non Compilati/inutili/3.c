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
	
	if (num1%num2==0){
		printf("il primo numero e' multiplo del secondo"); }
	else {
		printf("il primo numero non e' multiplo del secondo"); }

	printf("\n");
	system("PAUSE");
	return 0;
}

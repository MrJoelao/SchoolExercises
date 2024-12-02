/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/
#include <w>
#include <stdio.h>
#include <stdlib.h>
int calc_mcm (int num0, int num1){
	
	int i,mcm,minimo;
	
	if(num0<num1){
			minimo=num0;}
		else{
			minimo=num1;}
			
	for( i=2; i<=minimo; i++){
		if(num0%i==0 && num1%i==0){
				mcd=i;
		}
	}
	return mcd;
}

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
	
	mcm=calc_mcm(num0,num1);
	
	system ("cls");
	//output
	printf("L'MCM tra i due numeri inseriti, %d e %d, e': %d\n",num0,num1,mcm);	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

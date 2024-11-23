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
	int num0,num1,mcd=0,i,minimo;

	//algoritmo risolutivo
	printf("Numero 1: ");
	scanf("%d",&num0);
	printf("Numero 2: ");
	scanf("%d",&num1);
	
	if(num0<num1){
		minimo=num0;}
	else{
		minimo=num1;}
	
	for( i=2; i<=minimo; i++){
		if(num0%i==0 && num1%i==0){
				mcd=i;
		}
	}
	printf("Il massimo comun divisore e':%d",mcd);	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

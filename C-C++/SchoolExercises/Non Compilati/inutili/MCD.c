/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int calcolo_mdc(int num1,int num2){
		if(num0<num1){
		//caso 1: numero inserito per primo minore del secondo
		for(i=2;i<=num0;i++){
			if(num0%i==0){
				if(num1%i==0){mcd=i;}
			}
		}
	}
	else{
		//caso 2: numero inserito per primo maggiore del secondo
		for(i=2;i<=num1;i++){
			if(num1%i==0){
				if(num0%i==0){mcd=i;}
			}
		}
	}
	return mcd;
}

int main(){
	//dichiarazione variabili
	int num0,num1,mcd=0,i;

	//algoritmo risolutivo
	printf("Numero 1:");
	scanf("%d",&num0);
	printf("Numero 2:");
	scanf("%d",&num1);
	

	printf("Il massimo comun divisore e':%d",mcd);
	
	printf("\n");
	system("PAUSE");
	return 0;
}

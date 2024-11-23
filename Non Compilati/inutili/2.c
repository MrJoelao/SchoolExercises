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
	float a,b,x;

	//algoritmo risolutivo
	printf("Inserisci intervallo usando due estremi, A e B, inserisci il valore A:\n");
	scanf("%f",&a);
	printf("inserisci il valore B\n");
	scanf("%f",&b);
	
	printf("inserisci il valore X\n");
	scanf("%f",&x);
	
	if(x>=a && x<=b){
			printf("Il valore inserito %.2f e' interno all'intervallo\n",x);
	}
	else{
		printf("Il valore inserito %.2f e' estreno all'intervallo\n",x);
	}


	system("PAUSE");
	return 0;
}

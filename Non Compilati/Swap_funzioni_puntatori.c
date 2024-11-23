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
	float x, y, temp;

	//algoritmo risolutivo
	printf("Dimmi un valore per X \n");
	scanf("%f",&x);
	printf("Dimmi un valore per Y \n",x);
	scanf("%f",&y);
	
	temp=x;
	x=y;
	y=temp;
	
	
	printf("Il valore X e':%.0f, il valore Y e':%.0f\n", x,y);
	
	printf("\n");
	system("PAUSE");
	return 0;
}

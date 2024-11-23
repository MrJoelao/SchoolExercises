/*
Autore: Joel Stephan
Data:23/09/22
Versione:0
Testo: Es in classe:
2) Scrivere un algoritmo che, dati tre numeri reali X, Y e Z calcoli il risultato di (X+Y+Z)*(X+Y+Z)
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	float x, y, z, somma;

	//algoritmo risolutivo
	printf("Dimmi il valore di X \n");
	scanf("%f",&x);
	printf("%.0f? bene, dimmi il valore di Y \n",x);
	scanf("%f",&y);
	printf("%.0f? bene, dimmi il valore di Z \n",y);
	scanf("%f",&z);	
	
	somma=(x+y+z)*(x+y+z);
	
	printf("Il calcolo e':%.0f",somma);	
	
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

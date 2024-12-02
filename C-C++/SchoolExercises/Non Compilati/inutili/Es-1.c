/*
Autore: Joel Stephan
Data: 23/09/22
Versione:
Testo: Es 1
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	float num, risultato;

	//algoritmo risolutivo
	printf("Dimmi un valore e ti calcolero' il suo doppio!\n");
	scanf("%f",&num);
	
	risultato=num*2;
	printf("%.0f? bene, il suo doppio e': %.0f\n",num,risultato);

	printf("\n");
	system("PAUSE");
	return 0;
}

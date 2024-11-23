/*
Autore: Joel Stephan
Data: 23/09/22
Versione: 0
Testo: Es 9
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	float prezzo, scontato;

	//algoritmo risolutivo
	printf("Dimmi il prezzo del tuo articolo e ti calcolero' il suo prezzo scontato del 20 per 100\n");
	scanf("%f", &prezzo);
	scontato=prezzo-(prezzo/100*20);
	printf("%.2f? il prezzo scontato e' di: %.2f",prezzo,scontato);
	
	printf("\n");
	system("PAUSE");
	return 0;
}

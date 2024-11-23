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
	float prezzo,quantita,costo,sconto;

	//algoritmo risolutivo
	printf("Inserire il prezzo del prodotto:\n");
	scanf("%f",&prezzo);
	printf("Inserire la quantita:\n");
	scanf("%f",&quantita);
	if(quantita>0 && costo>0){
	if(quantita>20){
		costo = prezzo*quantita;
		sconto = costo*20/100;
		printf("Il costo non scontato di: %.2f, con uno sconto del 20 per cento e' di: %.2f\n",costo,costo-sconto);
	}
	else{
		if(quantita>10){
		costo = prezzo*quantita;
		sconto = costo*15/100;
		printf("Il costo non scontato di: %.2f, con uno sconto del 15 per cento e' di: %.2f\n",costo,costo-sconto);
		}
		else{
			if(quantita>5){
			costo = prezzo*quantita;
			sconto = costo*10/100;
			printf("Il costo non scontato di: %.2f, con uno sconto del 10 per cento e' di: %.2f\n",costo,costo-sconto);
			}
			else{
			costo = prezzo*quantita;
			sconto = costo*10/100;
			printf("Il costo e' di: %.2f\n",costo);
			}	
		}
	}
	}
	else
	printf("Quantita o costo non valido");
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

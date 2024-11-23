#include<stdio.h>

float sconto (float, float);
/* dato il costo e la % di sconto calcola il prezzo scontato
   IN: prezzo, %sconto
   OUT: prezzo scontato
*/

int main(){
float prezzo, scont; 
printf("inserisci il costo del prodotto: ");
scanf("%f", &prezzo); 
printf("inserisci il valore dello sconto in percentuale: "); 
scanf("%f", &scont);
prezzo = sconto(prezzo, scont); 
printf("il prezzo scontato ammonta a: %.2f", prezzo); 
return 0;
}

// funzioni

float sconto (float prezzo, float perc_sconto){
	prezzo = prezzo*((100-v_sconto)/100); 
	return prezzo;
}

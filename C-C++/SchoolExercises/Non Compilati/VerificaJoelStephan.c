/*
Autore: Joel Stephan
Data:
Versione: 0
Testo: 
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"
#define min 0
#define max 2

 int num_monete=0;
 

float input(){
	float moneta,importo=0;
	while (moneta!=0) {
    	
        printf("Inserisci moneta da 0.1, 0.2, 0.5, 1, 2 euro, per smettere immetere 0 : ");
        scanf("%f", &moneta);
        if (moneta == 0,1 || moneta == 0,2 || moneta == 0,5 || moneta == 1 || moneta == 2) {
        	importo=importo+moneta;
			num_monete++;
            printf("Importo attuale: %.2f\n", importo);
    	}
    	else {
        printf("Moneta non valida!\n");
    	}
    }
    return importo;
}

int main() {
    int ora_arrivo, minuti_arrivo,ora_uscita, minuti_uscita,totale_ore,totale_minuti,somma_monete;
    float importo;
	
    printf("Buongiorno! benvenuto al nostro parcheggio, qui la tariffa e' di 10 centesimi al ora!\nInserisci ora d'arrivo (hh mm): ");
    scanf("%d %d", &ora_arrivo, &minuti_arrivo);
	
    importo=input();
    
    //trafformo gli euro inseriti in centesimi perchè 10 centesimi=10 min, quindi 1 centesimi = 1 minuto
    somma_monete=importo*100;
    //il resto della divisione tra somma_monete e 60 sono i miuti
    totale_minuti=somma_monete%60;
    //uguale
    totale_ore=somma_monete/60;
    //somma ora calcolata con ora d'arrivo
    ora_uscita=totale_ore+ora_arrivo;
    //somma i minuti calcolati con i minuti d'arrivo
	minuti_uscita=totale_minuti+minuti_arrivo;
   
    printf("Hai soggiornato per: %d ore e per %d minuti, hai immesso %d monete\nOra d'uscita: %d:%d'",totale_ore,totale_minuti,num_monete,ora_uscita,minuti_uscita);
  
	printf("\n");
	system("PAUSE");
	return 0;
}

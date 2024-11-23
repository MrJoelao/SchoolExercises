/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"
#define max_mesi 12 /*inserisco come massimo 12 (basterebbe 11 dato che inizia da zero, ma è
					utile per la media quindi lo lascio 12) perchè ci sono 12 mesi in un anno.*/
					
#define max_importo 12 /*inserisco come massimo 1000 perchè valuto 1 unità come 1000 euro quindi 
					sostanzialmente il valore massimo inseribile mensilmente è 1 000 000 euro
					ed anche per non avere numeri troppo grandi.*/	

/*void input_cas_verificato(int arr[]) {
	int i,j,flag;
    for (i=0; i<max_mesi; i++) {
        arr[i]=cas_compreso(0,max_importo); //Genera un numero casuale nel range specificato
        for (j=0; j<i; j++){ 
            if(arr[j]==arr[i] && i>1){ //Verifica che il numero casuale non sia già presente nell'array
               i--;
            }
            else{
            printf("%d)Mese: %d\n",i+1,arr[i]);
			}
        }
    }
}*/

void random_array_v(int arr[], int size, int min, int max) {
    int i, j, randomNumber;
    for (i = 0; i < size; i++) {
        do {
            randomNumber = cas_compreso(min,max); // Genera un numero casuale nel range specificato
            // Verifica che il numero casuale non sia già presente nell'array
            for (j = 0; j < i; j++) {
                if (arr[j] == randomNumber) {
                    break;
                }
            }
        } while (j < i); // Continua a generare numeri casuali finché non ne trova uno unico
        arr[i] = randomNumber; // Aggiunge il numero casuale unico all'array
    }
}
int main(){
	//dichiarazione variabili
	int vendite[max_mesi],somma=0,vendita_max=-1,vendita_min=1001,pmax,pmin; //dichiaro vendità_max/min rispettivamente 
	int	risposta_utente,num_denaro,num_min_mesi=0,somma_investimento; /*eguagliati a valori impossibili per evitare 
																		errori*/
	float media; //dichiaro media float per dare al utente una media più precisa.
	

	//algoritmo risolutivo
	
	random_array_v(vendite,max_mesi,0,max_importo);
	
	for (int i=0; i<max_mesi; i++) {
        printf("%d)Mese: %d\n",i+1,vendite[i]);
	}
	
	printf("\n");
	system("PAUSE");
	return 0;
}

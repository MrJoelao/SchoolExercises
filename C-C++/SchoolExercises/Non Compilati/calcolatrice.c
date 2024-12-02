/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
Scrivere un programma che, da menù, consenta all’utente di scegliere tra le seguenti opzioni:

    calcolare il fattoriale di un numero (intero non negativo e non superiore a 10)
    dati n e k interi non negativi non superiori a 20, calcolare le disposizioni di ordine n e classe k
    dati n e k interi non negativi non superiori a 20, calcolare le combinazioni di ordine n e classe k
    terminare il lavoro
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"

#define fatMin 0 // definisce una costante per il valore minimo accettato per il calcolo del fattoriale
#define fatMax 10 // definisce una costante per il valore massimo accettato per il calcolo del fattoriale

#define min 0 // definisce una costante per il valore minimo accettato per n e k
#define max 20 // definisce una costante per il valore massimo accettato per n e k


// funzione che calcola le disposizioni, utilizzando il fattoriale
int calc_disp(int n, int k) {
	return calc_fat(n)/calc_fat(n-k);
}

// funzione che calcola le combinazioni, utilizzando il fattoriale
int calc_comb(int n, int k) {
	return calc_fat(n)/(calc_fat(k)*calc_fat(n-k));
}


int main(){
	//dichiarazione delle variabili:
	int scelta,num,n,k,flag=0;
	//algoritmo risolutivo
	
	do{
		// stampa del menu di scelta
		printf("1.Fattoriale\n2.Calcolo delle disposizioni di ordine n e classe k (n intero non negativo non superiore a 10)\n3.Calcolo delle combinazioni di ordine n e classe k (n e k interi non negativi non superiori a 20).\n4. Chiudi programma.\nInserire: ");
		scanf("%d",&scelta);
		switch(scelta){
			case 1:
				system ("cls");
				
				printf("Fattoriale! inserisci un numero: ");
				num=leggi_compreso(fatMin,fatMax);
				
				printf("Risultato: %d\n\n",calc_fat(num));
			break;
			
			case 2:
				system ("cls");
				
				printf("Calcolo delle disposizioni! inserisci n: ");
				n=leggi_compreso(min,max);
				printf("inserisci k:");
				k=leggi_compreso(min,max);
				
				printf("Risultato: %d\n\n",calc_disp(n,k));
			break;
			
			case 3:
				system ("cls");
				
				printf("Calcolo delle combinazioni! inserisci n: ");
				n=leggi_compreso(min,max);
				printf("inserisci k:");
				k=leggi_compreso(min,max);
				
				printf("Risultato: %d\n\n",calc_comb(n,k));
				
			break;
			
			case 4:
				//uso un flag per uscire dal ciclo eguagliandolo a 1
				flag=1;
			break;
			
			default:
				printf("Scelta non valida");
			break;
		}
	}
	while(flag!=1);
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

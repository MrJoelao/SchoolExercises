/*
Autore: Alessandro Pini
Data: 30/01/2023
Versione:
Testo: Simulare il funzionamento di un registratore di cassa.
		Il programma deve:
		- richiedere la cifra iniziale presente in cassa (fondo cassa)
		- per ogni cliente che effettua un acquisto richiedere, per ogni articolo acquistato, il
		  prezzo unitario e la quantita’
		- visualizzare lo scontrino (con il dettaglio degli acquisiti e il totale da pagare)
		- Richiedere la somma versata dal cliente e calcolare il resto
		Quando si decide di spegnere il registratore di cassa, visualizzare il totale presente in
		cassa e il totale incassato nella giornata
*/

#include <stdio.h>
#include <stdlib.h>
#include "pini.h"

void scontrino (float,int,float);
void resto (float,float);

int main(){
	
	int onOff,unita,articolo;
	float totIniziale,totCassa,tot=0,prezzoArticolo,sommaVersata,incasso;

		onOff=1;
		printf("Inserire il totale in cassa a inizio giornata: ");
		totIniziale=FLOATLEGGI(0,1000);
		totCassa=totIniziale;
		do{
			tot=0;
			do{
				printf("\nPrezzo articolo: ");
				prezzoArticolo=FLOATLEGGI(0,1000);
				printf("\nQuantita': ");
				unita=INTLEGGI(0,10);
				tot+=prezzoArticolo*unita;
				scontrino(prezzoArticolo, unita, tot);
				printf("\nFinito gli acquisti? [0 nessun articolo]	");
				scanf("%d", &articolo);
			}while(articolo!=0);
			printf("\nSomma versata: ");
			sommaVersata=FLOATLEGGI(0,1000);
			resto(tot, sommaVersata);
			totCassa+=tot;
			incasso=totCassa-totIniziale;
			printf("\nSpegnere il registratore? [0 spegne]	");
			scanf("%d", &onOff);
			if(onOff==0){
				printf("\nTotale presente in cassa: %.2f", totCassa);
				printf("\nIncasso: %.2f", incasso);	
			}
		}while(onOff!=0);

	printf("\n");
	system("PAUSE");
	return 0;
}

void scontrino (float prezzoArticolo,int unita,float tot){
	
	printf("\nPrezzo articolo: %.2f x %d",prezzoArticolo,unita);
	printf("\nSomma totale: %.2f\n",tot);
	
}

void resto (float tot,float sommaVersata){
	
	float resto;
	
		resto=sommaVersata-tot;
		printf("\n-------------------------\n");
		printf("\nSomma versata: %.2f",sommaVersata);
		printf("\nResto dovuto: %.2f\n",resto);
		printf("\n-------------------------\n");
	
}

/*****************************
Autore:
Data:
Versione:
Testo: 	Simulare il funzionamento di un registratore di cassa.
		Il programma deve:
		- richiedere la cifra iniziale presente in cassa (fondo cassa)
		- per ogni cliente che effettua un acquisto richiedere, per ogni articolo acquistato, il
		  prezzo unitario e la quantita’
		- visualizzare lo scontrino (con il dettaglio degli acquisiti e il totale da pagare)
		- Richiedere la somma versata dal cliente e calcolare il resto
		Quando si decide di spegnere il registratore di cassa, visualizzare il totale presente in
		cassa e il totale incassato nella giornata
*****************************/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione delle variabili
	int onOff, prezzoArticolo, unita;

	//algoritmo risolutivo
	onOff=1; //accendo la cassa
	totaleIniziale=leggiDato(0,1000);
	totaleCassa=totaleIniziale;
	do{
		totale=0; //spesa iniziale singolo cliente
		do{
			prezzoArticolo=leggidato(0,1000);
			unita=leggidato(0,10);
			totale+=prezzoArticolo*unita;
			printScontrino(prezzoArticolo, unita, totale);
			printf("\nFino gli acquisti? [0 nessun articolo]");
			scanf("%d", &articolo);
		}while(articolo!=0);
		
		sommaVersata=leggiDato(0,1000);
		calcolaResto(totale, sommaVersata);
		
		totaleCassa+=totale;
		incasso=totaleCassa-totaleIniziale;
		
		printf("\nSpegnere il registratore? [0 spegne]");
		scanf("%d", &onOff);
		if(onOff==0){
			printf("\nTotale presente in cassa: %f", totaleCassa);
			printf("\nTotale presente in cassa: %f", incasso);	
		}
	}while(onOff!=0);


	printf("\n");
	system("PAUSE");
	return 0;
}

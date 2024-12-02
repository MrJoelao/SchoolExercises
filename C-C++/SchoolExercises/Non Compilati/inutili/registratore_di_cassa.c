/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"
#define maxc 1000000
int main(){
	//dichiarazione variabili
	int fondo_cassa,n_acquisti,n_articoli,prezzo_articolo,somma_versata,tot_pagamento=0,flag_off,resto,totale_incassato=0,i;
	char risposta[maxc];
	//algoritmo risolutivo
	
	// Richiedere in input la cifra iniziale presente in cassa:
	printf("Inserire il fondo cassa: ");
	 fondo_cassa=leggi_maggiore(0);
	
	do{
		
	// numero di articoli
	printf("Inserire il numero di articoli acquistati: ");
	 n_acquisti=leggi_maggiore(0);
	 
	//calcolo totale pagamento
	for(i=0; i<n_acquisti; i++){
		printf("\nArticolo %d:\nNumero di articoli:",i+1);
		n_articoli=leggi_maggiore(0);
		
		printf("Prezzo: ");
		prezzo_articolo=leggi_maggiore(0);
		
		tot_pagamento+=n_articoli*prezzo_articolo;
	}
	  
	// Scontrino
	printf("\nScontrino:\nArticoli aquistati: %d \nTotale da pagare: %d\nInserire: ",n_acquisti,tot_pagamento);
	 somma_versata=leggi_maggiore(tot_pagamento);
	 
	if(somma_versata>tot_pagamento){
		resto=somma_versata-tot_pagamento;
		printf("Il resto e' di: %d\nBuona giornata!",resto);
	}
	else{
		printf("Buona giornata\n");	
	}
	
	// Scelta di spegnimento
	printf("Spegnere?\n1.[si] 2.[no]");
	 scanf("%s",risposta);
	 
	//Calcolo il totale incassato nella giornata
	totale_incassato+=tot_pagamento;
	
	}while(risposta!="si" || risposta!="Si");
	
	printf("\nTotale presente: %d \nTotale incassato nella giornata: %d",fondo_cassa+totale_incassato,totale_incassato);
	
	printf("\n");
	system("PAUSE");
	return 0;
}

/*
Autore: Joel Stephan
Data: 19/12/2022
Versione: 0
Testo: chiedere a gli utenti quanti voti inserire, 
	   successivamente inserire i voti e i cfu associati.
	   calcolare la media ponderata.
*/	   

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"

int main(){
	//dichiarazione variabili
	int num_voti, i; 
	float voto, cfu, somma_voti = 0, somma_cfu = 0;
	
	//algoritmo risolutivo
  	
	printf("Quanti voti vuoi inserire? ");
	 num_voti=leggi_maggiore(0);
	
	for (i = 0; i < num_voti; i++) {
   		printf("\nCorso %d\nInserisci il voto: ", i+1);
    	 voto=leggi_intervallo(18,30);
    	printf("Inserisci i CFU del corso: ");
    	 cfu=leggi_intervallo(3,15);

    somma_voti=somma_voti+voto*cfu;
    somma_cfu=somma_cfu+cfu;
	}
	 
	printf("La tua media ponderata e': %.3f\n", somma_voti / somma_cfu);		                       
                        
	printf("\n");
	system("PAUSE");
	return 0;
}

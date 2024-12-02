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
					
#define max_importo 1000 /*inserisco come massimo 1000 perchè valuto 1 unità come 1000 euro quindi 
					sostanzialmente il valore massimo inseribile mensilmente è 1 000 000 euro
					ed anche per non avere numeri troppo grandi.*/	
int main(){
	//dichiarazione variabili
	int vendite[max_mesi],somma=0,vendita_max=-1,vendita_min=1001,pmax,pmin; //dichiaro vendità_max/min rispettivamente 
	int	risposta_utente,num_denaro,num_min_mesi=0,somma_investimento; /*eguagliati a valori impossibili per evitare 
																		errori*/
	
	float media; //dichiaro media float per dare al utente una media più precisa.
	
	//algoritmo risolutivo.
	
	for(int i=0; i<max_mesi; i++){
		vendite[i]=cas_compreso(0,12); /*metto zero perchè metto come minimo 0 
												  euro di ricavato mensile.*/
		
		printf("%d)Mese: %d\n",i+1,vendite[i]);
								  
		somma+=vendite[i]; /*dopo aver letto l'importo mensile lo aggiungo a "somma" 
						     in modo di calcolare la media.*/
						     
		if(vendite[i]>vendita_max){	//verifico se il valore appena creato è maggiore 
			vendita_max=vendite[i];	//della vendità più grande mai inserita, se lo è il valore 
			pmax=i;					//attuale diventa il nuovo valore massimo. e inoltre salvo 
		}							//la posizione dove è stato trovato il valore massimo
		
		 
		if(vendite[i]<vendita_min){	//verifico se il valore appena creato è maggiore 
			vendita_min=vendite[i]; //della vendità più piccola mai inserita, se lo è il valore 
			pmin=i;					//attuale diventa il nuovo valore massimo. e inoltre salvo 
		}							//la posizione dove è stato trovato il valore minimo
	}
	
	//calcolo la media artmetica.
	media=somma/max_mesi;
	
	//stampa dei risultati ottenuti.
	printf("\n\tDati calcolati:\n-Importo annuale: %d\n-Media mensile: %.2f",somma,media); //uso tre printf 
	printf("\nNel mese %d e' stata rivelato importo piu' alto: %d",pmax+1,vendita_max); //per comodità
	printf("\nNel mese %d e' stata rivelato importo piu' basso: %d",pmin+1,vendita_min); // :)
	
	//Compito 2 e 3: Aggiungere una Funzionalità di Ricerca e una per ottimizzare gli Investimenti
	printf("\n\n\tTools:\n1.Funzionalita' di Ricerca\n2.Investimenti\nInserire: ");
	
	//leggo la scelta del utente
	risposta_utente=leggi_compreso(1,2);
	
	if(risposta_utente==1){
		//Compito 2: Aggiungere una Funzionalità di Ricerca.
		printf("Benvenuto!, inserire il mese (1-12): ");
		risposta_utente=leggi_compreso(1,12); //leggo in input la risposta del utente riutilizado la stessa v.
		printf("Mese trovato!\n%d Mese: %d ",risposta_utente,vendite[risposta_utente]); //stampo il mese
	}
	else{
		//Compito 3: Aggiungere una Funzionalità per ottimizzare gli Investimenti
		printf("Benvenuto!, inserire investimento: ");
		num_denaro=leggi_compreso(1,somma); //a somma di denaro sia minore uguale alla somma annuale se no 
											//risulta impossibile dire quanti mesi ci vogliono se neanche la 
											//somma raggiunge investimento
		do{
			for(int i=0; i<max_mesi; i++){
				for(int j=0; j<max_mesi; j++){
					if(vendite[i]>vendite[j]){
						somma_investimento+=vendite[i];
						num_min_mesi++;
						printf("Dentro!");
					}
				}		
			}

		}while(somma_investimento>=num_denaro);
		
		printf("\nNumero minimo di mesi: %d",num_min_mesi);
	}
	
	printf("\n");
	system("PAUSE");
	return 0;
}

/*
Autore: Joel Stephan
Data:
Versione:
Testo: il biglietto di ingresso in un museo ha le seguenti tariffe: per i bambini inferiori ai 6 anni ingresso è gratuito (opz 1) per gli studenti 8 euro (opz 2) per i pensionati 10 euro (opz 3) 
per tutti gli altri 15 euro (opz 4).
creare un programma in qui utente inserisce un num tra 1-4 e gli viene comunicato il prezzo relativo all'opzione scelta, se il numero inserito non è valido mostrare un messagio di errore
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	int scelta;

	//algoritmo risolutivo
	printf("Per sapere il prezzo d'ingresso al museo scegli, tra le seguenti opzioni, la piu' adatta per lei:\n1.Bambino sotto i 6 anni\n2.Studente\n3.Pensionato\n4.Altro\n");
	scanf("%d",&scelta);
	switch(scelta){
		case 1:
			printf("Per i bambini con eta' inferiore a 6 anni e' gratis!");
				break;
		case 2:
			printf("Il prezzo in base alla sua scelta e': 8 euro");	
				break;
		case 3:
			printf("Il prezzo in base alla sua scelta e': 10 euro");
				break;
		case 4:
			printf("Il prezzo in base alla sua scelta e': 15 euro");
				break;
		default:
			printf("Scelta non valida");
				break;
	}                                              
	printf("\n");
	system("PAUSE");
	return 0;
}

/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
Sei il responsabile dell'ufficio esami di una scuola superiore e hai appena ricevuto i risultati degli esami 
di fine anno degli studenti. Devi analizzare i risultati e fornire una panoramica della performance degli studenti.

Compito 1: Creare un Array Monodimensionale per i Risultati degli Esami
	1. Creare un array monodimensionale in cui ogni elemento rappresenta il voto di uno studente.
	2. Popolare l'array con i risultati degli esami degli studenti.

Compito 2: Analizzare i Risultati degli Esami
    1. Calcolare la media dei voti degli studenti.
    2. Trovare il voto più alto e il voto più basso.
    3. Calcolare la percentuale di studenti che hanno superato l'esame (voti superiori o uguali a 60) e 
	   la percentuale di studenti che non hanno superato l'esame.

Compito 3: Classificare gli Studenti
	Classificare gli studenti in base al loro voto:
    -Voto superiore a 90: studente eccellente
    -Voto compreso tra 80 e 90: studente distinto
    -Voto compreso tra 70 e 80: studente sufficiente
    -Voto inferiore a 70: studente insufficiente

Compito 4: Stampare i Risultati
	1. Stampare la media dei voti degli studenti.
	2. Stampare il voto più alto e il voto più basso.
	3. Stampare la percentuale di studenti che hanno superato l'esame e la percentuale di studenti che non 
	   hanno superato l'esame.
	4. Stampare la classificazione degli studenti.

*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"
#define maxStudenti 20000

int main(){
	//dichiarazione variabili
	int nStudenti,arrayStudenti[maxStudenti],somma,max=0,min=100,sufficenti=0,insufficenti;
	float media,percentualePassati,percentualiInsufficenti;
	
	//algoritmo risolutivo
	printf("Inserire il numero di stundeti e successivamente un voto che va da 0 a 100: ");
	 nStudenti=leggi_compreso(2,maxStudenti);
	 
	for(int i=0; i<nStudenti; i++){
//		printf("Inserire studente n%d :",i+1);
		
//		arrayStudenti[i]=leggi_compreso(0,100); 
		arrayStudenti[i]=cas_compreso(100,0);
		somma+=arrayStudenti[i];
		
		if(arrayStudenti[i]>=max)
			max=arrayStudenti[i];
			
		if(arrayStudenti[i]<min)
			min=arrayStudenti[i];
		
		if(arrayStudenti[i]>=60)
			sufficenti+=1;
		
		
	}
	
	media=somma/nStudenti;
	insufficenti=nStudenti-sufficenti;
	percentualePassati=100*sufficenti/nStudenti;
	percentualiInsufficenti=100*insufficenti/nStudenti;
	
	printf("\n%d %d\n",sufficenti,insufficenti);
	
	printf("La media e': %.2f\n\nMax: %d\nMin: %d\n\nPercetuale:\n Passati: %.2f\n Non passati: %.2f\n\nClassificazione: \n",media,max,min,percentualePassati,percentualiInsufficenti);
	
	for(int i=0; i<nStudenti; i++){
		printf("Studente %d e' ",i+1);
		if(arrayStudenti[i]>90)
			printf("Eccelente\n");
		else if(arrayStudenti[i]>80)
			printf("Distinto\n");
		else if(arrayStudenti[i]>70)
			printf("Discreto\n");
		else if(arrayStudenti[i]>60)
			printf("Sufficente\n");
		else	
			printf("Insufficente\n");
	}
	
	printf("\n");
	system("PAUSE");
	return 0;
}

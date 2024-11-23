/*
Autore: Joel Stephan
Data:
Versione: 0
Testo: 
Dato un intero che rappresenta un numero di ammalati e un numero intero che rappresenta la percentuale di ammalati 
e un numero intero che rappresenta la percentuale di ammalati che ogni giorno guarisce, calcolare quanti sono necessari 
affinchè il numero di ammalati sia minore di 100.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	int nGiorni=0,i,ammalati,percGuariti;
	
	//algoritmo risolutivo
	
		//input ammalati con verfica dei dati
	printf("Inserire la quantita' di persone ammalate: ");
		scanf("%d",&ammalati);
		while(ammalati<=0){
			printf("Errore: Quantita' inserita non valida, inserisci un valore maggiore di zero.\n Inserire la quantita' di persone ammalate: ");
				scanf("%d",&ammalati);
		}
		//input percentuale guariti con verfica dei dati
	printf("Inserire la percentuale di persone guarite: ");
		scanf("%d",&percGuariti);
		while(percGuariti<=0){
			printf("Errore: Quantita' inserita non valida, inserisci un valore maggiore di zero.\n Inserire la percentuale di persone guarite: ");
				scanf("%d",&percGuariti);
		}

	do{	
		nGiorni=nGiorni+1;
		ammalati=ammalati-(ammalati*percGuariti)/100;
		printf("\nammalati: %d\n",ammalati);
	}while(ammalati>1);
	
	printf("I giorni necessari per far guarire tutti e': %d, %d",nGiorni,ammalati);
	printf("\n");
	system("PAUSE");
	return 0;
}

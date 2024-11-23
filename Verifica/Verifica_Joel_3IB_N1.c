/*
Autore: Joel Stephan
Data: 14/11/22
Versione: 0
Testo:

SpongeBob e Patrick partecipano ad un’asta per contendersi l’acquisto di il piatto speciale del  
“Krusty Krab”. A turno i due compratori dovranno fare un’offerta per li piatto da comprare, l’asta 
termina quando uno dei due compratori si ritira offrendo ‘0’, a quel punto l’altro compratore si 
sarà aggiudicato l’asta. Stampare quale compratore si è aggiudicato l’asta e con che cifra.

*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	float offertaSpongebob=1,offertaPatrick=1,maggiore=0,vincente;

	//algoritmo risolutivo
	printf("Inserisci una offerta e ti indichero a fine ciclo offerta piu' alta e chi a proposto offerta!\n");
	
	//ciclo
	do{
		//input spongebob
		printf("Offerta Spongebob?:");
			scanf("%f",&offertaSpongebob);
		
		//controllo input spongebob
		while(offertaSpongebob<0 || offertaSpongebob==offertaPatrick){
			printf("Errore: Valore inserito minore di zero o hai inserito la stessa offerta di patrick, inserisci un valore diverso!\nOfferta Spongebob?:");
				scanf("%f",&offertaSpongebob);
		}
		
		//input patrick
		printf("Offerta Patrick?:");
			scanf("%f",&offertaPatrick);
		
		//controllo input patrick
		while(offertaPatrick<0 || offertaPatrick==offertaSpongebob){
			printf("Errore: Valore inserito minore di zero o hai inserito la stessa offerta di spongebob, inserisci un valore diverso!\nOfferta Patrick?:");
				scanf("%f",&offertaPatrick);
		}
		
		if(offertaSpongebob>offertaPatrick && offertaSpongebob>maggiore){
			printf("	Offerta di Spongebob e' quella piu' alta!\n");
			maggiore=offertaSpongebob;
			vincente=1;
		}
		else{
			if(offertaPatrick>maggiore){
			printf("	Offerta di Patrick e' quella piu' alta!\n");
			maggiore=offertaPatrick;
			vincente=2;
			}
		}
	}while(offertaSpongebob>0 && offertaPatrick>0);
	
	
	//output finale
	if(vincente==1){
			printf("FINE ASTA!\nIl vincitore e spongebob con una offerta di: %.2f",maggiore);
		}
	else{
			printf("FINE ASTA!\nIl vincitore e patrick con una offerta di: %.2f",maggiore);
		}
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

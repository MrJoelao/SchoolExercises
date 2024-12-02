 /*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	int bassi=0,volte=0;
	float altezza,media=0;

	//algoritmo risolutivo
	
	printf("Inserisci altezza dei giocatori, inserisci un numero uguale a zero per interrompere il ciclo.\n\nEsempio:\n-\nAltezza?: 1.89\nAltezza?: 1.51\nAltezza?: 0\nLa media dei giocatori e' di: 1.70\nIl numero di giocatori sotto il 1.75m e' di: 1 giocatori\nFine.\n-\n\n");
		do{
			
			//input output
			printf("Altezza?:");
			scanf("%f",&altezza);
				
			//verifica che sia maggiore di zero
			if(altezza>0 && altezza<3){
			
				//conta valori sotto 1.65
				if(altezza>1,75){
					bassi=bassi+1;
				}
				
			//media
			volte=volte+1;
			media=media+altezza;
			}
			
			//output di errore
			else{
				printf("Errore: valore inserito non valido, inserisci un numero maggiore di 0 e minore di 3.\n");
			}
		}while(altezza!=0);
		
	system ("cls");
	
	//verica che ci siano almeno 2 valori per eseguire la media
	if(volte>2){
		
	//calcolo media
	media=media/volte;
	
	//output media
	printf("La media dei giocatori e' di: %.2fm\nIl numero di giocatori sotto il 1.75m e' di: %d giocatori",media,bassi);
	}
	
	else{
		//output di errore
		printf("Errore: Inserisci almeno 2 altezze!");
	}

	
	printf("\n");
	system("PAUSE");
	return 0;
}
 
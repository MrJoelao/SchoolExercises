/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h> 
#define pc 0.45
#define conchiglia 0.60
#define nocciolina 0.35
#define bastoncino 1
int main(){
	//dichiarazione variabili
	int nAmici,sceltaPal,i;
	float somma=0;
	//algoritmo risolutivo
	printf("Quanti amici hai?: ");
		scanf("%d",&nAmici);
	while(nAmici<0){
			printf("Errore: Valore inserito minore di zero, inserisci un valore diverso!\nQuanti amici hai?: ");
				scanf("%d",&nAmici);
		}
	for(i=1;i<=nAmici;i++){
		printf("Tra:\n1. Pallina di carta\n2. Conchiglia\n3. Nocciolina\n4. Bastoncino di legno colorato\n");
			scanf("%d",&sceltaPal);
		
		switch(sceltaPal){
			case 1:
				somma=somma+pc;
			break;
			
			case 2:
				somma=somma+conchiglia;
			break;
			
			case 3:
				somma=somma+nocciolina;
			break;
			
			case 4:
				somma=somma+bastoncino;
			break;
			
			default:
			printf("Scelta non valida");
				//dato che la scelta era non valida tolgo un ciclo
				i=i-1;
				break;
		}
	}
	
	//output
	printf("bene! la lunghezza della collana e' di: %.2f cm",somma);
	
	printf("\n");
	system("PAUSE");
	return 0;
}

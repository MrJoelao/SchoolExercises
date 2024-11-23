/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define vMax 10
#define max 0
#define min 20
int main(){
	//dichiarazione variabili
	int num,random[vMax],flag=0,posizione=-1;
	//algoritmo risolutivo
	srand(time(0));
	
	printf("Inserisci un numero: ");
	scanf("%d",&num);
	
	for(int i=0; i<vMax; i++) {
        random[i]=rand()%max+min;
        printf("%d ",random[i]); // stampa i valori generati
        if(random[i]==num){
        	posizione=i;
		}
    }
    
	
	if(posizione>-1)
		printf("\nTrovato!\nPosizone: %d",posizione);
	else
		printf("Non trovato.");
		
	printf("\n");
	system("PAUSE");
	return 0;
}

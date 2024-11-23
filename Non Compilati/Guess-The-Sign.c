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
	int A,B,fat=1,i,j,N,maggiore,minore;
	
	//algoritmo risolutivo
	printf("Quanti turni vuoi giocare?:");
		scanf("%d",&N);
		
		//ciclo controllo dati:
	while(N<=0){
			//output errore
		printf("ERRORE: Valore inserito non valido! insersci un valore maggiore di 0\n");
			//intput
		printf("Quanti turni vuoi giocare?:");
		scanf("%d",&N);
	}
	
	for(j=1; j<=N; j++){
			//input
		printf("Inserire il valore A:");
			scanf("%d",&A);
		printf("Inserire il valore B:");
			scanf("%d",&B);
	
			//if maggiore/minore
		if(A>B){
				//se A è maggiore di B assegno la variabile "maggiore" il valore di A e "minore" il valore di B
			maggiore=A;
			minore=B;}
		else{
				//se B è maggiore di A assegno la variabile "maggiore" il valore di B e "minore" il valore di A
			maggiore=B;
			minore=A;}
			
			//ciclo fattoriale tar A e B
		for(i=minore; i<=maggiore; i++){
			fat=fat*i;
		}
		
		//output
		if(fat>0){
				//se il fattoriale è maggiore di zero è positivo
			printf("Risultato: +\n");
		}
		else{
				//se uguale a zero, nullo
			if(fat==0){
				printf("Risultato: 0\n");
			}
				//se non è maggiore di zero ne nullo è negativo
			else{
				printf("Risultato: -\n");
			}
		}
		//per definire meglio la fine di ogni ciclo/turno
		printf("FINE TURNO %d\n\n",j);
	}

	printf("\n");
	system("PAUSE");
	return 0;
}

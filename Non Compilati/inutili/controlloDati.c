/*
Autore: Joel Stephan
Data:
Versione: 0
Testo: Scrivere un programma in c dove si chiede di inserire 5 numeri primi e positivi.
	   Dichiaro come costante un intero di nome DIM  con valore 5.
	   Successivamente fare la somma.
	   Utilizzare la funzione per la lettura, positività, somma e controllo se i numeri inseriti sono primi.
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 5
int leggi(int min){
    int valore,primo;

    do{
        scanf("%d",&valore);
        
        //verifica numero primo
		primo = 0; 
		for (int i=2; i<valore && primo==0; i++) {
        	if (valore%i == 0) 
            	primo = 1;
    	}
    	
    	//messaggio di errore
        if(valore<min && primo!=0){
            printf("ERRORE: Valore inserito non valido!, inserisci un numero primo maggiro di zero: ");
        }
    }while(valore<min && primo!=1);

    return valore;
}
	
int main(){
	//dichiarazione variabili
	int num,i;
	//algoritmo risolutivo
	for(i=0; i<DIM; i++){
		printf("\nInserisci un numero primo maggiore di zero: ");
		num=leggi(0);
	}
	
	printf("\n");
	system("PAUSE");
	return 0;
}

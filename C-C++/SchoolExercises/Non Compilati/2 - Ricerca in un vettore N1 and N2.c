/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 10
#define max 21
#define min -10
int main() {
	//dichiarazioni variabili
    int i,maxVal,minVal,vettore[max]; // variabile per memorizzare il massimo valore, il minimo e vettore per memorizzare i numeri casuali
    
	//algoritmo risolutivo
    srand(time(0));
    
    for(i=0; i<n; i++) {
        vettore[i]=rand()%max+min;
        printf("%d ",vettore[i]); // stampa i valori generati
    }
    
    maxVal=vettore[0]; // inizializza maxVal con il primo elemento del vettore
    minVal=vettore[0]; // inizializza minVal con il primo elemento del vettore
    
    for(i=1; i<n; i++) {
        if (vettore[i]<minVal) {
        	minVal=vettore[i];
        }
        if (vettore[i]>maxVal) {
        	maxVal=vettore[i];
        }
    }
    printf("\nIl massimo e': %d\nIl minimo e': %d",maxVal,minVal);
    
    printf("\n");
	system("PAUSE");
	return 0;
}

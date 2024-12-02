/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
7 - Rovescia stringhe

Scrivere un programma in C che legge da standard input una sequenza di parole, e stampa le parole lette, una per linea, in ordine inverso rispetto 
all’ordine di lettura.

La lunghezza massima di una parola e' definita nel programma dalla costante MAX LEN.

Il numero massimo di parole in input e' definito dalla costante MAX WORDS.

Ogni parola (stringa) deve essere allocata dinamicamente con una lunghezza minima necessaria a contenerla (e memorizzata in un array di stringhe).
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>

//-------------------------/

//---------/*	Define:
#define MAXLEN 30
#define MAXWORDS 100
//----------------------------------/

//---------/ Funzioni:
//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	char **parole = (char **)malloc(MAXWORDS * sizeof(char *)); 
	int lunghezza = 1, i = 0, n;
	//----------------------/

	//---------/ Algoritmo Risolutivo:

	do {
        parole[i] = (char *)malloc(MAXLEN * sizeof(char)); // Allocazione di spazio per la singola parola

        printf("%d) Inserire parola: ", i + 1);
        fgets(parole[i], MAXLEN, stdin);
        strtok(parole[i], "\n"); // Rimuovo il carattere per andare a capo

        i++;
    } while (i < MAXWORDS && strcmp(parole[i - 1], "END") != 0); // Leggo parole fino a MAXWORDS o finché non viene inserita la parola "END"

    n = i - 2; // Per non prendere "END" e perchè alla fine i viene incrementata di 1

    printf("Parole lette in ordine inverso:\n");
    for (i = n; i >= 0; i--) {
        printf("%s\n", parole[i]); // Stampa le parole in ordine inverso
        free(parole[i]); // Libera la memoria allocata per ciascuna parola
    }

    free(parole); // Libera la memoria allocata per l'array di puntatori a stringhe

	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

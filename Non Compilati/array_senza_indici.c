/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Analisi codice:
Vengono dichiarato un puntatore, puntatore_array, insieme a un array di interi. 
Questo array viene allocato dinamicamente con dimensione MAX e inizializzato tutto a 0 grazie alla malloc.

"puntatore_array" viene inizializzato all'inizio dell'array. Questo significa che puntatore_array viene fatto puntare alla 
prima cella del array (array[0]).
Uso un ciclo for per assegnare valori da 0 a 10 agli elementi dell'array. 

	All'interno del ciclo for, l'istruzione "*puntatore_array=i;" assegna il valore di i all'elemento dell'array a cui punta 
	puntatore_array. Inizialmente, i è 0, quindi assegna 0 a array[0].
	
	Dopo aver assegnato il valore, puntatore_array viene incrementato di 1 tramite l'istruzione "puntatore_array++;" ora 
	puntatore_array punta a array[1].
	
	Questo processo si ripete per tutto il ciclo, assegnando i valori crescenti da 0 a 10 (incluso) agli elementi successivi 
	dell'array.

Dopo il popolamento dell'array, stampo gli elementi dell'array utilizzando un secondo ciclo for:

	"puntatore_array" viene riportato all'inizio dell'array con l'istruzione "puntatore_array = &array[0];" 
	(o puntatore_array = array;, che è equivalente).
	
	All'interno del ciclo for, "printf("%d ", *puntatore_array);" stampa il valore dell'elemento corrente a cui 
	punta puntatore_array.
	
	Successivamente, puntatore_array viene incrementato di 1 con puntatore_array++; per puntare all'elemento successivo, il
	processo si ripete fino a quando tutti gli elementi dell'array sono stati stampati.

In sintesi, il puntatore "puntatore_array" viene utilizzato per accedere agli elementi dell'array uno per uno durante il 
popolamento e la stampa. Dopo aver assegnato un valore o stampato un elemento, il puntatore viene spostato alla cella di 
memoria successivo dell'array. Questo consente di lavorare con l'array utilizzando puntatori anziché indici.

Infine libero la memoria assegnata dalla malloc usando la funzione free().
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>

//-------------------------/

//---------/*	Define:
#define MAX 10
//----------------------------------/

//---------/ Funzioni:
//----------------------/

//----/* Int Main:
nt main() {
    // Dichiarazione delle variabili
    int *puntatore_array, i;
    int *array = (int*)calloc(MAX, sizeof(int)); // Allocazione dinamica di un array di interi con dimensione MAX

    // Inizializzazione del puntatore puntatore_array all'inizio dell'array
    puntatore_array = &array[0];

    // Ciclo per popolare l'array utilizzando il puntatore
    for (i = 0; i <= MAX; i++) {
        *puntatore_array = i; // Assegna il valore di 'i' all'elemento corrente dell'array
        puntatore_array++; // Sposta il puntatore all'elemento successivo
    }

    // Reimposta il puntatore all'inizio dell'array
    puntatore_array = &array[0];

    // Ciclo per stampare gli elementi dell'array utilizzando il puntatore
    for (i = 0; i <= MAX; i++) {
        printf("%d ", *puntatore_array); // Stampa il valore dell'elemento corrente dell'array
        puntatore_array++; // Sposta il puntatore all'elemento successivo
    }

    // Libera la memoria precedentemente allocata per l'array
    free(array);

    printf("\n");
    system("PAUSE");
    return 0;
}

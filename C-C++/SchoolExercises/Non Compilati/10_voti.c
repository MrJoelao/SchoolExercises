/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
Scrivere un programma che gestisce un vettore di voti in modo dinamico.

Il vettore deve contenere una struttura formata da numero di registro e voto (int e float).

Il programma deve partire da un vettore di dimensione 5 e aggiungere 5 elementi ogni volta che si raggiunge la sua capienza massima.

Deve essere strutturato in funzioni.

Le informazioni vanno lette da un file binario opportunamente creato.

Deve prevedere il calcolo della media totale dei voti.
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>

//-------------------------/

//---------/*	Define:
#define MAX_STUDENTI 250
#define MAX_VOTI 5
//----------------------------------/

//---------/*	Struct:
typedef struct{
    int nRegistro;
    float voto;
} registro;
//----------------------------------/

//---------/*	Funzioni:
// Funzione per la lettura dei dati
float leggiDati(registro *array, int *lunghezza) {
    int i = 0;
    FILE *file = fopen("dati.bin", "rb");

    if (file == NULL) {
        printf("Impossibile aprire il file dati.bin\n");
        return -1;
    }

    while (i < *lunghezza && !feof(file)) {
        if (i == *lunghezza) {
            *lunghezza += 5;
            array = (registro *)realloc(array, (*lunghpezza) * sizeof(registro));
        }

        fread(&array[i].nRegistro, sizeof(registro), 1, file);
        fread(&array[i].voto, sizeof(registro), 1, file);
        i++;
    }

    fclose(file);

    float somma = 0.0;

    for (int j = 0; j < i; j++) {
        if (array[j].voto >= 0 && array[j].voto <= 10) {
            somma += array[j].voto;
        }
    }

    return somma / i;
}

//----------------------------------/

//----/* Int Main:
int main() {
    //---------/ Variabili:
    registro *array = (registro *)malloc(MAX_VOTI * sizeof(registro));
    int lunghezza = MAX_VOTI;
    //----------------------/

    //---------/ Algoritmo Risolutivo:
    if (array == NULL) {
        printf("Errore nell'allocazione di memoria.\n");
        return 1;
    }

    float media = leggiDati(array, &lunghezza);

    if (lunghezza == 0) {
        printf("Nessun dato inserito.\n");
    } else {
        printf("La media dei voti inseriti e': %.2f\n", media);
    }

    free(array);
    //---------------------------------/

    printf("\n");
    system("PAUSE");
    return 0;
}


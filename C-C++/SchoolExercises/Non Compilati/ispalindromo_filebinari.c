//----/* Informazioni:
/* Autore:	Joel Stephan
   Data:
   Versione: 0				 */
//----------------------------\\

//---------/*	Testo:
/*
  
*/
//----------------------------------\\

//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>
	#include   "TheLib-J.h"

//-----------------------\\

//---------/*	Define:

//---------------------\\

//----/* Funzioni:

//---------------\\

//----/* Int Main:

int main() {
    FILE *file;
    char filename[100];
    char carattere;
    char *testo = NULL;
    long lunghezza = 0;
    long i = 0;

    // Chiedi all'utente di inserire il nome del file
    printf("Inserisci il nome del file: ");
    scanf("%s", filename);

    // Apri il file in lettura
    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Impossibile aprire il file.\n");
        return 1;
    }

    // Determina la lunghezza del file
    fseek(file, 0, SEEK_END);
    lunghezza = ftell(file);
    rewind(file);

    // Alloca memoria per il testo
    testo = (char *)malloc(lunghezza);

    // Leggi il contenuto del file nel buffer
    fread(testo, 1, lunghezza, file);

    // Chiudi il file
    fclose(file);

    // Rimuovi eventuali caratteri non alfabetici
    for (i = 0; i < lunghezza; i++) {
        if (isalpha(testo[i])) {
            testo[i] = tolower(testo[i]);
        } else {
            memmove(&testo[i], &testo[i + 1], lunghezza - i);
            lunghezza--;
            i--;
        }
    }

    // Verifica se il testo è un palindromo
    int palindromo = 1;
    for (i = 0; i < lunghezza / 2; i++) {
        if (testo[i] != testo[lunghezza - 1 - i]) {
            palindromo = 0;
            break;
        }
    }

    // Stampa il risultato
    if (palindromo) {
        printf("Il testo nel file è un palindromo.\n");
    } else {
        printf("Il testo nel file non è un palindromo.\n");
    }

    // Libera la memoria allocata
    free(testo);

    return 0;
}
/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>
	#include   "TheLib-J.h"

//-------------------------/

//---------/*	Define:

//----------------------------------/

//---------/ Funzioni:
//----------------------/

//----/* Int Main:
int main() {
    char stringa1[100], stringa2[100];
    int lunghezza_totale;

    // Chiedi all'utente di inserire due stringhe
    printf("Inserisci la prima stringa: ");
    fgets(stringa1, sizeof(stringa1), stdin);

    printf("Inserisci la seconda stringa: ");
    fgets(stringa2, sizeof(stringa2), stdin);

    // Calcola la lunghezza totale delle due stringhe
    lunghezza_totale = strlen(stringa1) + strlen(stringa2);

    // Alloca memoria per la stringa concatenata
    char *stringa_concatenata = malloc((lunghezza_totale + 1) * sizeof(char));

    if (stringa_concatenata == NULL) {
        printf("Memoria non allocata.\n");
        exit(0);
    } else {
        // Concatena le due stringhe
        strcpy(stringa_concatenata, stringa1);
        strcat(stringa_concatenata, stringa2);

        printf("Stringa concatenata: %s\n", stringa_concatenata);

        free(stringa_concatenata);  // Libera la memoria
    }

    printf("\n");
    system("PAUSE");
    return 0;
}


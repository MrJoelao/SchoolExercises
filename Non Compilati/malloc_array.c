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
    int *array;
    int lunghezza, i;

    printf("Inserisci la lunghezza massima dell'array: ");
    scanf("%d", &lunghezza);

    array = malloc(lunghezza);

    for(i = 0; i < lunghezza; i++) {
        printf("zugu %d dell'array: ", i+1);
        scanf("%d", &array[i]);
    }

    printf("zugu zugu");
    for(i = 0; i < lunghezza; i++) {
        printf("%d ", array[i]);
    }

    free(array);

	printf("\n");
	system("PAUSE");
	return 0;
}

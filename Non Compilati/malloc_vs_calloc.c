/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
malloc e calloc vengono utilizzati per allocare memoria per un array di interi. La differenza principale è che 
malloc non inizializza la memoria allocata, mentre calloc inizializza tutti i byte della memoria allocata a zero. 
Quindi, quando stampiamo gli array, vediamo che l’array allocato con malloc contiene valori spazzatura, 
mentre l’array allocato con calloc contiene solo zeri.
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>

//-------------------------/

//---------/*	Define:

//----------------------------------/

//---------/ Funzioni:
//----------------------/

//----/* Int Main:
int main() {
    int *puntatoreMalloc, *puntatoreCalloc;
    int numeroElementi = 5, i;

    // Utilizzo di malloc
    puntatoreMalloc = (int*) malloc(numeroElementi * sizeof(int));
    if(puntatoreMalloc != NULL) {
        printf("Valori allocati con malloc: ");
    	for(i = 0; i < numeroElementi; i++) {
        	printf("%d ", puntatoreMalloc[i]);
  		}
    	printf("\n");
    }

    

    // Utilizzo di calloc
    puntatoreCalloc = (int*) calloc(numeroElementi, sizeof(int));
    if(puntatoreCalloc != NULL) {
        printf("Valori allocati con calloc: ");
    	for(i = 0; i < numeroElementi; i++) {
        	printf("%d ", puntatoreCalloc[i]);
    	}
    }

    

    // Libero la memoria
    free(puntatoreMalloc);
    free(puntatoreCalloc);

    return 0;
}
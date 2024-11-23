/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"
#define max 1000
int main() {
	//dichiarazione variabili
    int n_muffin,grandezza_vasoio,max_gusto=0,gusto_corrente=0,i,gusto_muffin[max];
    
	//algoritmo risolutivo
    printf("Inserisci il numero di muffin e la dimensione della finestra: ");
    scanf("%d %d", &n_muffin, &grandezza_vasoio);

    for (i=0; i<n_muffin; i++) {
        printf("Inserisci il gusto del muffin %d: ", i+1);
        scanf("%d", &gusto_muffin[i]);
    }

    
    for (i=0; i<grandezza_vasoio; i++) {
        gusto_corrente=gusto_corrente+gusto_muffin[i];
    }

    for (i=grandezza_vasoio; i<n_muffin; i++) {
        gusto_corrente=gusto_corrente+(gusto_muffin[i]-gusto_muffin[i-grandezza_vasoio]);
        max_gusto=valmax_2(max_gusto, gusto_corrente);
    }

    printf("La massima somma di gusti tra %d muffin adiacenti e': %d", grandezza_vasoio, max_gusto);
	
	printf("\n");
	system("PAUSE");
	return 0;
}

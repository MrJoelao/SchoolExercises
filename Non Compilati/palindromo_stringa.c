/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max_vett 500000

int main() {
    // Dichiarazione delle variabili
    char parola[max_vett];
    int lunghezza, i, palindroma;

    // Inserimento della parola
    printf("Inserisci una parola: ");
    scanf("%s", parola);

    // Visualizzazione della parola inserita
    printf("\nParola inserita: %s\n", parola);

    // Conversione dei caratteri in minuscolo
    lunghezza=strlen(parola);
    for(i=0; i<lunghezza; i++){
        parola[i]=tolower(parola[i]);
    }

    // Visualizzazione della parola con caratteri minuscoli
    printf("(SYSTEM) minuscolo: %s\n", parola);

    // Verifica se la parola è palindroma
    palindroma = 1;
    for (i=0; i<lunghezza/2; i++) {
        if (parola[i]!=parola[lunghezza-1-i]) {
            palindroma=0;
        }
    }

    // Stampa il risultato
    if (palindroma==1) {
        printf("La parola e' palindroma.\n");
    } else {
        printf("La parola non e' palindroma.\n");
    }

    return 0;
}
	
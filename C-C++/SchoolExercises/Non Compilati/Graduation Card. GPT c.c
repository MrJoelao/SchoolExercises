	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>
	#include   "TheLib-J.h"

#define MAX_LEN 1000

void appendWord(char *message, const char *word) {
    strcat(message, word);
    strcat(message, " ");
}

int main() {
    int N, K;
    char words[MAX_LEN][21]; // Matrice per memorizzare le parole
    char message[MAX_LEN] = ""; // Stringa per il messaggio finale
	FILE *file;
    // Apertura del file di input
    file=Open_file(file,"file.txt", "r");

    // Lettura dell'input
    fscanf(file, "%d %d", &N, &K);
    for (int i = 0; i < N; i++) {
        fscanf(file, "%s", words[i]);
    }

    // Chiusura del file di input
    fclose(file);

    // Costruzione del messaggio
    int lineLen = 0;
    for (int i = 0; i < N; i++) {
        int wordLen = strlen(words[i]);

        // Se la parola non entra nella riga corrente, vado a capo
        if (lineLen + wordLen > K) {
            strcat(message, "\n");
            lineLen = 0;
        }

        // Aggiungo la parola alla riga corrente
        appendWord(message, words[i]);
        lineLen += wordLen + 1;
    }

    // Stampa del messaggio
    printf("%s\n", message);

    return 0;
}
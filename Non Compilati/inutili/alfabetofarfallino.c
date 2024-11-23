/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib-J.h"

#define max_vett 100 //metto 100 caratteri massimi come richiesto da problema
#define max_vett_3 300 

int is_vocale(char carattere) {
    char minuscolo = tolower(carattere);
    int verifica=0;

    if (minuscolo == 'a' || minuscolo == 'e' || minuscolo == 'i' || minuscolo == 'o' || minuscolo == 'u') {
        verifica=1;
 	
 	return verifica;
}

int main(){
	char frase[max_vett],farfallino[max_vett_3];
	int i,j=0;
	//algoritmo risolutivo
	printf("Inserire una stringa: ");
	gets(frase);

	//algoritmo risolutivo
	 // costruisci la frase in alfabeto farfallino
    for (i = 0; frase[i] != '\0' && i < 100; i++) {
        farfallino[j++] = frase[i];

        if (isalpha(frase[i])) { // se è una lettera
            if (is_vocale(frase[i])==1) {
                    farfallino[j++] = islower(frase[i]) ? 'f' : 'F';
                    farfallino[j++] = frase[i];
            }
        }
    }
    farfallino[j] = '\0';  // termina la stringa farfallino

    puts(farfallino);
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

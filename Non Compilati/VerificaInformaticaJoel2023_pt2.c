/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TheLib-J.h"

#define max_vett 99
#define max_vett_2 128
int main() {
	//dichiarazione variabili
    char sta[max_vett], stb[max_vett], sta2[max_vett_2];
    int i;
    
	//algoritmo risolutivo
    printf("Inserisci la prima stringa (max %d caratteri): ", max_vett);
    gets(sta);

    printf("Inserisci la seconda stringa (max %d caratteri): ", max_vett);
    gets(stb);

    // Concateno "sta" con uno spazio vuoto usando la funzione strcat della libreria
    strcat(sta, " ");
    
    //concateno sta e sta2 e succesivamente concateno stb con sta2 in questo modo concateno sta e stb in sta2
    strcpy(sta2, sta); 
    strcat(sta2, stb);
    
    // Stampa la stringa "sta2" in ordine inverso
    for (i=strlen(sta2); i>=0; i--) {
        printf("%c", sta2[i]);
    }
    
    printf("\n");
    return 0;
}
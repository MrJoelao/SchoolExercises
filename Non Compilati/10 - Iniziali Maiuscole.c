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
#define max_vett 100

int main(){
	//dichiarazione variabili
	char parola[max_vett];
    int i,lunghezza;

    // Inserimento della parola
    printf("Inserisci una frase (massimo 100 caratteri): ");
    gets(parola);
	
	//algoritmo risolutivo
	
	printf("Frase originale: %s\n", parola); // stamapa la fase originale
	
	lunghezza=strlen(parola); //calcolo la lunghezza della stringa
	
    for(i=0; i<lunghezza; i++) { 
        if(parola[i-1]==' ' || i==0) { // se il carattere precedente era uno spazio o è il primo dell frase
            parola[i]=toupper(parola[i]); // rendi maiuscola l'iniziale della nuova parola
        }
        else {
            parola[i]=tolower(parola[i]); // rendi minuscole tutti gli altri caratteri
        }
    }
    
    printf("Nuova Frase: %s\n",parola);  // stampa la nuova fase
	
	printf("\n");
	system("PAUSE");
	return 0;
}

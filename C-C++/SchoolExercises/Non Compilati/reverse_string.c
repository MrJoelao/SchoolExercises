/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
Scrivere un programma in C che legge da standard input una sequenza di parole, e stampa le parole lette, una per linea, in ordine inverso rispetto 
all’ordine di lettura.
La lunghezza massima di una parola e' definita nel programma dalla costante MAX LEN.
Il numero massimo di parole in input e' definito dalla costante MAX WORDS.
Ogni parola (stringa) deve essere allocata dinamicamente con una lunghezza minima necessaria a contenerla (e memorizzata in un array di stringhe).
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>

//-------------------------/

//---------/*	Define:
#define MAX_LEN 100
#define MAX_WORDS 100
//----------------------------------/

//---------/ Funzioni:
//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	char *words[MAX_WORDS];
    int i=0, j, flag = 0;
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	while (i<MAX_WORDS && !flag) {
        words[i]=malloc(MAX_LEN * sizeof(char));
        scanf("%s", words[i]);
        
        if (strcmp(words[i], "-1") == 0)
            flag=1;
        i++;
    }
	
	printf("\nParole: \n");
	
    for (j=i-2; j>=0; j--) { // Nota: j parte da i - 2 per escludere "-1"
        printf("%s\n", words[j]);
        free(words[j]);
    }
    
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

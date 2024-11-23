/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>
	#include   "TheLib-J.h"

int main() {
	//dichiarazione variabili
    char stringa[100];
    int lunghezza, i, conteggio_vocali[5]={0,0,0,0,0};
    FILE *fp;
    
	//algoritmo risolutivo
    printf("Inserisci una stringa: ");	// Leggo la stringa dall'input
    gets(stringa);
	
    // Controllo che la stringa contenga solo caratteri alfabetici
    lunghezza=strlen(stringa);
    
    for (i=0; i<lunghezza; i++) {
  		tolower(stringa[i]);
    }

	
    // Conto le vocali nella stringa
    for (i=0; i<lunghezza; i++) {
        switch(stringa[i]){
        	case 'a':
        		conteggio_vocali[0]++;
        	 break;
        	case 'e':
        		conteggio_vocali[1]++;
        	 break;
        	case 'i':
        		conteggio_vocali[2]++;
        	 break;	
        	case 'o':
        		conteggio_vocali[3]++;
        	 break;	
        	case 'u':
        		conteggio_vocali[4]++;
        	 break;	
        	default:
        	 break;
		}
    }
	
	for(i=0; i<5; i++){
		conteggio_vocali[5]+=conteggio_vocali[i];
	}
	
    // Scrivo il numero di vocali nel file "output.txt"
    fp=fopen("output.txt", "w");
    fprintf(fp, "%d", conteggio_vocali[5]);
    fclose(fp);

    printf("\n");
	system("PAUSE");
	return 0;
}
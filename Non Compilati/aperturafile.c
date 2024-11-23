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

int main(){
	//dichiarazione variabili
	 FILE *fp;
    char ch;
    
	//algoritmo risolutivo
    fp=fopen("File.txt", "r");

    if (fp==NULL) { 
        printf("Errore nell'apertura del file\n");
        
    }

    while ((ch=fgetc(fp))!=EOF) {
        printf("%c", ch);
    }

    fclose(fp);
    
	printf("\n");
	system("PAUSE");
	return 0;
}
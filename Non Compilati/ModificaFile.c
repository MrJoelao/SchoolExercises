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
    fp=fopen("File.txt", "a");

    if (fp==NULL) { 
        printf("Errore nell'apertura del file\n");
        return 1;
    }
	
    fprintf(fp,"daje roma ");

    fclose(fp);
	
	printf("\n");
	system("PAUSE");
	return 0;
}

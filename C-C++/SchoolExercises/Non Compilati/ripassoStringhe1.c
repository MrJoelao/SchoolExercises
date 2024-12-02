/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
Da stringa normale a lettere minuscole
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>
	#include   "TheLib-J.h"

//-------------------------/

//---------/*	Define:
	#define MAX 80
//----------------------------------/

//---------/ Funzioni:
//----------------------/

//----/* Int Main:

int main() {
	//---------/ Variabili:
	char stringa[MAX];
    int i;
	//----------------------/
    
    //---------/ Algoritmo Risolutivo:
	printf("Inserisci una stringa: ");
    fgets(stringa, MAX, stdin);
    
    stringa[0]=toupper(stringa[0]);
    
    for (i=1; i<strlen(stringa); i++) {
        if(stringa[i-1]==' '){
        	stringa[i]=toupper(stringa[i]);
		}
    }
    
    fputs(stringa, stdout);
	//---------------------------------/

    printf("\n");
    system("PAUSE");
    return 0;
}

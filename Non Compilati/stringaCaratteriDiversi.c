/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
/---------*/


//---------/*	Librerie:

#include    <stdio.h>
#include    <stdlib.h>
#include    <string.h>
#include    <ctype.h>
#include    <time.h>
#include    <math.h>

//-------------------------/

//---------/*	Define: */
#define MAX 80
//----------------------------------/

//---------/ Funzioni:
int cercaCarattere(char array[], int lunghezza, char valore) {
    int i, flag=0; 

    for ( i=0; i<lunghezza; i++) {
        if (array[i]==valore) { 
            flag=1;
        }
    }
    
    return flag; 
}

int caratDiversi(char vettore[], int lunghezza) {
    int i, conta=0;
    
    for (i=0; i<lunghezza-1; i++) {
        if (cercaCarattere(vettore, i, vettore[i])==0) {
            conta++;
        }
    }

    return conta;
}

//----/* Int Main:
int main() {
    //---------/ Variabili:
    char stringa[MAX];
    int i;
    //----------------------/

    //---------/ Algoritmo Risolutivo:
    printf("Inserire la stringa: ");
    
    fgets(stringa, MAX, stdin);
    
    for (i=0; i<strlen(stringa); i++) {
        stringa[i]=tolower(stringa[i]);
    }
    
    printf("I caratteri unici dentro alla stringa sono: %d\n", caratDiversi(stringa, strlen(stringa)));
    //---------------------------------/

    printf("\n");
    system("PAUSE");
    return 0;
}

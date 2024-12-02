//----/* Informazioni:
/* Autore:	Joel Stephan
   Data:
   Versione: 0				 */
//----------------------------\\

//---------/*	Testo:
/*
  
*/
//----------------------------------\\

//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>
	#include   "TheLib-J.h"

//-----------------------\\

//---------/*	Define:
#define MAXNOME 30 + 1
#define MAXTELEFONO 15
#define MAXCONTATTI 1000
//---------------------\\

//---------/*	Struct:
typedef struct {
    char nome[MAXNOME];
    char telefono[MAXTELEFONO];
}Contatto;

typedef struct {
    Contatto contatti[MAXCONTATTI];
    int numContatti;
}Rubrica;
//---------------------\\

//----/* Funzioni:
void scriviRubrica(char *nomeFile, Rubrica *rubrica) {
    FILE *binario = fopen(nomeFile, "wb");
    if (binario == NULL) {
        printf("Errore nell'apertura del file\n");
        return;
    }

    fwrite(rubrica, sizeof(Rubrica), 1, binario);
    fclose(binario);
}

void leggiRubrica(char *nomeFile, Rubrica *rubrica) {
    FILE *binario = fopen(nomeFile, "rb");
    if (binario == NULL) {
        printf("Errore nell'apertura del file\n");
        return;
    }

    fread(rubrica, sizeof(Rubrica), 1, binario);
    fclose(binario);
}
//---------------\\


//----/* Int Main:
int main() {
	//---------/*	Variabili:
	Rubrica laRubrica;
    int i;
 	//-----------------------\\
    
    //---------/*	Algoritmo Risolutivo:
    laRubrica.numContatti = 3;
    strcpy(laRubrica.contatti[0].nome, "Mario");
    strcpy(laRubrica.contatti[0].telefono, "349-975-3995");
    strcpy(laRubrica.contatti[1].nome, "Luigi");
    strcpy(laRubrica.contatti[1].telefono, "317-785-2245");
    strcpy(laRubrica.contatti[2].nome, "Totti");
    strcpy(laRubrica.contatti[2].telefono, "384-395-8970");

    // Scrivi la rubrica nel file binario
    scriviRubrica("binario.dat", &laRubrica);

    // Leggi la rubrica dal file
    leggiRubrica("binario.dat", &laRubrica);

    // Stampa i dati letti dalla rubrica
    for (i = 0; i < laRubrica.numContatti; i++) {
        printf("Nome: %s\n", laRubrica.contatti[i].nome);
        printf("Telefono: %s\n", laRubrica.contatti[i].telefono);
    }
    //----------------------------------\\
    

    printf("\n");
	system("PAUSE");
	return 0;
}

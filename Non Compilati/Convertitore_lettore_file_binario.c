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
	#include   "TheLib-J.h"

//-------------------------/

//---------/*	Define:
//----------------------------------/

//---------/*	Struct:
//----------------------------------/

//---------/*	Funzioni:
void leggiBin() {
    FILE *file;
    char valoreLetto;
    char nomeFile[100];

    printf("Inserisci il nome del file binario da leggere: ");
    scanf("%s", nomeFile);

    file = fopen(nomeFile, "rb");
    if (file == NULL) {
        printf("Impossibile aprire il file %s.\n", nomeFile);
        return;
    }
	
    while (fread(&valoreLetto, sizeof(char), 1, file)) {
        printf("%c", valoreLetto);
    }

    fclose(file);
    printf("\n");
}

void converti() {
    char nomeFileTxt[100], nomeFileBin[100], carattere;
 
    printf("Inserisci il nome del file di testo da convertire (es. input.txt): ");
    scanf("%s", nomeFileTxt);

    printf("Inserisci il nome del file binario in cui salvare i dati (es. output.bin): ");
    scanf("%s", nomeFileBin);
    
    FILE *fileTxt = fopen(nomeFileTxt, "r");
    FILE *fileBin = fopen(nomeFileBin, "wb");
    
    if (fileBin == NULL || fileTxt == NULL) {
        printf("Impossibile creare o aprire il file binario o Impossibile aprire il file di testo %s\n", nomeFileBin);
        fclose(fileTxt);
        return;
    }
    
    while ((carattere = fgetc(fileTxt)) != EOF) {
        fwrite(&carattere, sizeof(char), 1, fileBin);
    }

    fclose(fileTxt);
    fclose(fileBin);

    printf("Il file di testo e' stato convertito con successo in un file binario %s\n", nomeFileBin);
}
//----------------------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	int scelta;
	//----------------------/
	do {
        printf("Menu:\n");
        printf("1. Leggi da file binario\n");
        printf("2. Converti testo in binario\n");
        printf("3. Esci\n");
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
            	system("CLS");
                leggiBin();
                break;
            case 2:
            	system("CLS");
                converti();
                break;
            case 3:
                printf("Uscita dal programma...\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    } while (scelta != 3);
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

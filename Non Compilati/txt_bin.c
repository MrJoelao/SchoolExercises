#include <stdio.h>
#include <stdlib.h>

int main() {
    char nomeFileTxt[100];
    char nomeFileBin[100];

    printf("Inserisci il nome del file di testo da convertire (es. input.txt): ");
    scanf("%s", nomeFileTxt);

    printf("Inserisci il nome del file binario in cui salvare i dati (es. output.bin): ");
    scanf("%s", nomeFileBin);

    FILE *fileTxt = fopen(nomeFileTxt, "r");
    if (fileTxt == NULL) {
        printf("Impossibile aprire il file di testo %s\n", nomeFileTxt);
        return 1;
    }

    FILE *fileBin = fopen(nomeFileBin, "wb");
    if (fileBin == NULL) {
        printf("Impossibile creare o aprire il file binario %s\n", nomeFileBin);
        fclose(fileTxt);
        return 1;
    }

    char carattere;
    while ((carattere = fgetc(fileTxt)) != EOF) {
        fwrite(&carattere, sizeof(char), 1, fileBin);
    }

    fclose(fileTxt);
    fclose(fileBin);

    printf("Il file di testo e' stato convertito con successo in un file binario %s\n", nomeFileBin);

    return 0;
}

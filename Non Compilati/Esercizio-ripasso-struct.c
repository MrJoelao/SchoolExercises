#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTARGA 7 + 1
#define MAXCHAR 30 + 1
#define MAXAUTO 1000
#define MAXKW 2.58
#define MINKW 3.87

typedef struct automobile {
    char targa[MAXTARGA];
    char marca[MAXCHAR];
    char modello[MAXCHAR];
    int kw;
    int anno_im;
    int anno_rev;
} automobile;

typedef struct marche {
    char nome[MAXCHAR];
    int numero;
} marche;

FILE *myFopen(char *nomeFile, char *tipo) {
    FILE *fd = fopen(nomeFile, tipo);
    if (fd == NULL) {
        printf("Errore nell'apertura del file");
        exit(1);
    }
    return fd;
}

void myFclose(FILE *fd) {
    if (fclose(fd) != 0) {
        printf("Errore nella chiusura del file");
        exit(2);
    }
}

int popola_auto(FILE *fd, automobile lista_auto[]) {
    int i = 0;
    while (fread(&lista_auto[i], sizeof(automobile), 1, fd) == 1) {
        i++;
    }
    return i;
}

void stampa_auto(automobile lista_auto[], int numero_auto) {
    for (int i = 0; i < numero_auto; i++) {
        printf("Auto %d:\n", i + 1);
        printf("Targa: %s\n", lista_auto[i].targa);
        printf("Marca: %s\n", lista_auto[i].marca);
        printf("Modello: %s\n", lista_auto[i].modello);
        printf("KW: %d\n", lista_auto[i].kw);
        printf("Anno di immatricolazione: %d\n", lista_auto[i].anno_im);
        printf("Anno di revisione: %d\n", lista_auto[i].anno_rev);
        printf("\n");
    }
}

float calcola_bollo(int kw) {
    float importo = 0.0;
    if (kw <= 100) {
        importo = kw * MAXKW;
    } else {
        importo = 100 * MAXKW + (kw - 100) * MINKW;
    }
    return importo;
}

void scambia(automobile *auto1, automobile *auto2) {
    automobile temp;
    temp = *auto1;
    *auto1 = *auto2;
    *auto2 = temp;
}

int uscita() {
    char risposta;
    printf("Uscire dal programma? (y or n): ");
    scanf(" %c", &risposta);
    if (risposta == 'y' || risposta == 'Y') {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE *fBinario;
    automobile lista_auto[MAXAUTO];
    int n, scelta,i,nuovo_anno_rev,anno_min;
    char marca_cercata[MAXCHAR],targa_cercata[MAXTARGA],vettore_targhe[MAXAUTO][MAXTARGA];

    fBinario = myFopen("input.dat", "rb");

    n = popola_auto(fBinario, lista_auto);

    do {
        printf("Scegli un'opzione:\n");
        printf("1. Visualizza l'elenco delle auto di una data marca\n");
        printf("2. Ordina l'elenco per valori crescenti di kw\n");
        printf("3. Visualizza i dati di un'auto con una data targa e modifica l'anno di revisione\n");
        printf("4. Calcola e visualizza l'importo del bollo per ogni auto\n");
        printf("5. Determina l'anno di immatricolazione più vecchio\n");
        printf("6. Salva le targhe di tutte le automobili in un vettore di stringhe\n");
        printf("7. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                // Implementa la visualizzazione delle auto di una data marca
                printf("Inserisci la marca da cercare: ");
                scanf("%s", marca_cercata);
                for (i = 0; i < n; i++) {
                    if (strcmp(lista_auto[i].marca, marca_cercata) == 0) {
                        // Stampa l'auto
                        printf("Auto %d:\n", i + 1);
                        printf("Targa: %s\n", lista_auto[i].targa);
                        printf("Marca: %s\n", lista_auto[i].marca);
                        printf("Modello: %s\n", lista_auto[i].modello);
                        printf("KW: %d\n", lista_auto[i].kw);
                        printf("Anno di immatricolazione: %d\n", lista_auto[i].anno_im);
                        printf("Anno di revisione: %d\n", lista_auto[i].anno_rev);
                        printf("\n");
                    }
                }
                break;

            case 2:
                // Implementa l'ordinamento per valori crescenti di kw
                for (i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (lista_auto[j].kw > lista_auto[j + 1].kw) {
                            scambia(&lista_auto[j], &lista_auto[j + 1]);
                        }
                    }
                }
                printf("Elenco ordinato per kw:\n");
                stampa_auto(lista_auto, n);
                break;

            case 3:
                // Implementa la visualizzazione e la modifica dei dati di un'auto con una data targa
                printf("Inserisci la targa dell'auto da cercare: ");
                scanf("%s", targa_cercata);
                for (i = 0; i < n; i++) {
                    if (strcmp(lista_auto[i].targa, targa_cercata) == 0) {
                        // Stampa l'auto
                        printf("Auto trovata:\n");
                        printf("Targa: %s\n", lista_auto[i].targa);
                        printf("Marca: %s\n", lista_auto[i].marca);
                        printf("Modello: %s\n", lista_auto[i].modello);
                        printf("KW: %d\n", lista_auto[i].kw);
                        printf("Anno di immatricolazione: %d\n", lista_auto[i].anno_im);
                        printf("Anno di revisione: %d\n", lista_auto[i].anno_rev);
                        printf("Inserisci il nuovo anno di revisione: ");
                        scanf("%d", &nuovo_anno_rev);
                        lista_auto[i].anno_rev = nuovo_anno_rev;
                        printf("Anno di revisione modificato.\n");
                        break;
                    }
                }
                break;

            case 4:
                // Implementa il calcolo e la visualizzazione dell'importo del bollo per ogni auto
                printf("Importo del bollo per ogni auto:\n");
                for (i = 0; i < n; i++) {
                    float importo = calcola_bollo(lista_auto[i].kw);
                    printf("Targa: %s, Importo del bollo: %.2f\n", lista_auto[i].targa, importo);
                }
                break;

            case 5:
                // Determina l'anno di immatricolazione più vecchio
                anno_min = lista_auto[0].anno_im;
                for (i = 1; i < n; i++) {
                    if (lista_auto[i].anno_im < anno_min) {
                        anno_min = lista_auto[i].anno_im;
                    }
                }
                printf("L'anno di immatricolazione più vecchio è: %d\n", anno_min);
                break;

            case 6:
                // Implementa il salvataggio delle targhe di tutte le automobili in un vettore di stringhe
                for (i = 0; i < n; i++) {
                    strcpy(vettore_targhe[i], lista_auto[i].targa);
                }
                printf("Targhe salvate nel vettore:\n");
                for (i = 0; i < n; i++) {
                    printf("%s\n", vettore_targhe[i]);
                }
                break;

            case 7:
                // Uscita dal programma
                printf("Uscendo dal programma...\n");
                break;

            default:
                printf("Errore: Scelta non valida\n");
                break;
        }
    } while (scelta != 7);

    myFclose(fBinario);
    return 0;
}

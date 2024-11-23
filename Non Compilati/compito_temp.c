#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define NUM_MESI 12
#define MAX 10

typedef struct info {
    char nome_mese[MAX];
    float temperatura;
} mesi_temperatura;

// Funzione per inizializzare i nomi dei mesi
void inizializzaNomiMesi(mesi_temperatura mesi[]) {
    strcpy(mesi[0].nome_mese, "Gennaio");
    strcpy(mesi[1].nome_mese, "Febbraio");
    strcpy(mesi[2].nome_mese, "Marzo");
    strcpy(mesi[3].nome_mese, "Aprile");
    strcpy(mesi[4].nome_mese, "Maggio");
    strcpy(mesi[5].nome_mese, "Giugno");
    strcpy(mesi[6].nome_mese, "Luglio");
    strcpy(mesi[7].nome_mese, "Agosto");
    strcpy(mesi[8].nome_mese, "Settembre");
    strcpy(mesi[9].nome_mese, "Ottobre");
    strcpy(mesi[10].nome_mese, "Novembre");
    strcpy(mesi[11].nome_mese, "Dicembre");
}

// Funzione per generare temperature casuali
void generaTemperatureCasuali(float temperatura_medie[]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_MESI; i++) {
        temperatura_medie[i] = ((float)rand() / RAND_MAX) * 50 - 10;
    }
}

// Funzione di ordinamento a bolle
void bubbleSortAlfa(mesi_temperatura mesi[], float temperatura_medie[]) {
    int scambiato;
    do {
        scambiato = 0;
        for (int i = 0; i < NUM_MESI - 1; i++) {
            if (strcmp(mesi[i].nome_mese, mesi[i + 1].nome_mese) > 0) {
                // Scambia le due strutture
                mesi_temperatura temp_mese = mesi[i];
                mesi[i] = mesi[i + 1];
                mesi[i + 1] = temp_mese;
                // Scambia anche le temperature medie corrispondenti
                float temp_temp = temperatura_medie[i];
                temperatura_medie[i] = temperatura_medie[i + 1];
                temperatura_medie[i + 1] = temp_temp;
                scambiato = 1;
            }
        }
    } while (scambiato);
}

void bubbleSortDec(mesi_temperatura mesi[], float temperatura_medie[]) {
    int scambiato;
    float temp2;
    mesi_temperatura temp1;
    
    do {
        scambiato = 0;
        for (int i = 0; i < NUM_MESI - 1; i++) {
            if (temperatura_medie[i]>temperatura_medie[i+1]) {
                // Scambia le due strutture
                temp1 = mesi[i];
                mesi[i] = mesi[i + 1];
                mesi[i + 1] = temp1;
                // Scambia anche le temperature medie corrispondenti
                temp2 = temperatura_medie[i];
                temperatura_medie[i] = temperatura_medie[i + 1];
                temperatura_medie[i + 1] = temp2;
                scambiato = 1;
            }
        }
    } while (scambiato);
}

int main() {
    mesi_temperatura mesi[NUM_MESI];
    float temperatura_medie[NUM_MESI];
    int i;

    inizializzaNomiMesi(mesi);
    generaTemperatureCasuali(temperatura_medie);

    
    printf("\nTemperature medie mensili:\n");
    for (i = 0; i < NUM_MESI; i++) {
        printf("%s: %.2f C\n", mesi[i].nome_mese, temperatura_medie[i]);
    }

    // Ordina la lista in ordine alfabetico crescente usando bubble sort
    bubbleSortAlfa(mesi, temperatura_medie);

    
    printf("\nTemperature mensili in ordine alfabetico crescente:\n");
    for ( i = 0; i < NUM_MESI; i++) {
        printf("%s: %.2f C\n", mesi[i].nome_mese, temperatura_medie[i]);
    }
    
    // Ordina la lista in ordine decrescente per le temperature
    bubbleSortDec(mesi, temperatura_medie);
    
    
    printf("\nTemperature mensili in ordine numerico Decrescente:\n");
    for ( i = 0; i < NUM_MESI; i++) {
        printf("%s: %.2f C\n", mesi[i].nome_mese, temperatura_medie[i]);
    }

    return 0;
}

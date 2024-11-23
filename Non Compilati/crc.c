#include <stdio.h>
#include <string.h>

#define LUNG_GEN_POLY strlen(pol_gener)

char dati[28];  // dati da trasmettere e ricevere
char crc[28];   // valore CRC
char pol_gener[10];  // polinomio generatore
int lung_dati, i, j;

// Esegue l'operazione XOR
void xor() {
    for (j = 1; j < LUNG_GEN_POLY; j++)
        crc[j] = ((crc[j] == pol_gener[j]) ? '0' : '1');
}

// Calcola il CRC e controlla eventuali errori nella ricezione dei dati
void ricevente() {
    // Ottiene i dati ricevuti
    printf("Inserisci i dati ricevuti: ");
    scanf("%s", dati);
    printf("\nDati ricevuti: %s", dati);
    // Calcola il CRC
    for (i = 0; i < LUNG_GEN_POLY; i++)
        crc[i] = dati[i];
    do {
        if (crc[0] == '1')
            xor();
        for (j = 0; j < LUNG_GEN_POLY - 1; j++)
            crc[j] = crc[j + 1];
        crc[j] = dati[i++];
    } while (i <= lung_dati + LUNG_GEN_POLY - 2);
    // Controlla eventuali errori
    for (i = 1; i < LUNG_GEN_POLY; i++) {
        if (crc[i] == '1') {
            printf("\nErrore rilevato\n\n");
            return;
        }
    }
    printf("\nNessun errore rilevato\n\n");
}

int main() {
    printf("Inserisci i dati da trasmettere: ");
    scanf("%s", dati);
    lung_dati = strlen(dati);
    printf("Dati inseriti: %s\n", dati);
    printf("Inserisci il polinomio generatore: ");
    scanf("%s", pol_gener);
    printf("Polinomio generatore inserito: %s\n", pol_gener);
    ricevente();
    return 0;
}
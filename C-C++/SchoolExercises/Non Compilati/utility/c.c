#include <conio.h> // Libreria per la gestione dei tasti

int main() {
    char tasto;
    int continua = 1; // Flag per continuare a tenere premuto 'c'

    printf("Premi 'ins' per tenere premuto 'c'. Premi 'pausa' per smettere.\n");

    while (continua) {
        if (_kbhit()) { // Controlla se un tasto è stato premuto
            tasto = _getch(); // Ottieni il tasto premuto

            if (tasto == 0 || tasto == 224) { // Controllo per tasti speciali
                tasto = _getch(); // Ottieni il tasto speciale
                if (tasto == 82) { // 'ins' è rappresentato dal codice 82
                    printf("Tieni premuto 'c'...\n");
                    // Simula il tasto 'c' premuto continuamente
                    // Inserisci qui la tua logica per tenere premuto 'c'
                } else if (tasto == 80) { // 'pausa' è rappresentato dal codice 80
                    printf("Hai premuto 'pausa'. Interrompo il loop.\n");
                    continua = 0; // Esci dal loop
                }
            }
        }
    }

    return 0;
}

/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/

/*---------/ Testo:
Questo problema riguarda la gestione dei dati relativi alle località e alle loro temperature. Ecco un'analisi più dettagliata dei punti richiesti:

1. **Progettare le strutture dati**: Innanzitutto, dobbiamo definire una struttura dati C che possa rappresentare ciascun elemento contenente il nome 
di una località e la sua temperatura. Nella tua implementazione precedente, hai utilizzato una struttura `Elemento` per questo scopo. È una scelta 
appropriata poiché consente di raggruppare le informazioni correlate in un'unica entità.

2. **Costruire una lista di record**: Per gestire le località e le loro temperature, dovremo creare una lista collegata. Inizialmente, la lista sarà 
vuota, e la funzione dovrà leggere i dati dal file di temperature e creare un nuovo elemento per ciascuna località. Questi elementi dovrebbero 
essere inseriti in testa alla lista per semplificare l'inserimento. Inoltre, dovremo assegnare un codice ('f', 't', o 'c') in base alla temperatura 
e assegnarlo a ciascun elemento della lista.

3. **Scrivere la lista su un file ordinata per codice di temperatura**: Per questa parte, dovrai suddividere la lista in tre sottoliste separate, 
una per le località fredde, una per le temperate e una per le calde. Successivamente, dovrai scrivere ciascuna sottolista nel file di output 
nell'ordine specificato (calde, temperate, fredde). Questo richiederà un processo di divisione e scrittura dei dati.

4. **Gestire la memoria**: È essenziale gestire correttamente la memoria. Dopo aver scritto i dati nel file di output, dovrai liberare la memoria 
occupata dagli elementi della lista. Questo preverrà perdite di memoria e migliorare l'efficienza del tuo programma.

Nel complesso, questo problema coinvolge l'acquisizione di dati da un file, la manipolazione di strutture dati, la classificazione delle località 
in base alle temperature e la scrittura dei dati su un altro file. È un buon esercizio di programmazione in C che coinvolge la gestione dei file e 
delle strutture dati.
/---------*/

//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>

//-------------------------/

//---------/*	Define:

#define MAX_CHAR 20

//----------------------------------/

//---------/*	Struct:
// Definizione della struttura per gli elementi della lista
typedef struct elemento {
    char citta[MAX_CHAR];
    int temp;
    struct elemento* next;
} Elemento;
//----------------------------------/

//---------/*	Funzioni:
// Funzione per inserire un elemento in testa alla lista
void inserisci_testa(Elemento **lista, char *citta, int temp) {
    Elemento* nuovo = malloc(sizeof(Elemento)); // Allocazione dinamica di memoria per un nuovo elemento
    if (nuovo == NULL) { // Verifica se l'allocazione ha avuto successo
        perror("Errore di allocazione di memoria"); // Stampa un messaggio di errore e termina il programma
        exit(1);
    }
    strncpy(nuovo->citta, citta, MAX_CHAR - 1); // Copia il nome della città nell'elemento
    nuovo->temp = temp; // Assegna la temperatura all'elemento
    nuovo->next = *lista; // Il nuovo elemento punta al primo elemento della lista
    *lista = nuovo; // Aggiorna il puntatore alla testa della lista con il nuovo elemento
	return;
}

// Funzione per creare una lista di record da un file di temperature
Elemento *crea_lista_da_file(char *nome_file) {
    FILE *file = fopen(nome_file, "r"); // Apre il file in modalità lettura
    if (file == NULL) { // Verifica se l'apertura del file ha avuto successo
        perror("Impossibile aprire il file"); // Stampa un messaggio di errore e termina il programma
        exit(1);
    }

    Elemento *lista = NULL; // Inizializza una lista vuota
    char citta[MAX_CHAR];
    int temp;

    while (fscanf(file, "%s %d", citta, &temp) != EOF) { // Legge il nome della città e la temperatura dal file
        inserisci_testa(&lista, citta, temp); // Chiama la funzione per inserire l'elemento in testa alla lista
    }

    fclose(file); // Chiude il file
    return lista; // Restituisce la lista creata
}

// Funzione per assegnare un codice in base alla temperatura
char assegna_codice(int temp) {
    if (temp < 20)
        return 'f'; // 'f' per temperature inferiori a 20
    else if (temp >= 20 && temp <= 30)
        return 't'; // 't' per temperature comprese tra 20 e 30
    else
        return 'c'; // 'c' per temperature superiori a 30
}

// Funzione per scrivere la lista su un file ordinata per codice di temperatura
void scrivi_lista_su_file(Elemento* lista, char* nome_file) {
    FILE* file = fopen(nome_file, "w"); // Apre il file in modalità scrittura
    if (file == NULL) { // Verifica se l'apertura del file ha avuto successo
        perror("Impossibile aprire il file"); // Stampa un messaggio di errore e termina il programma
        exit(1);
    }

    Elemento* calde = NULL; // Lista per le località calde
    Elemento* temperate = NULL; // Lista per le località temperate
    Elemento* fredde = NULL; // Lista per le località fredde

    // Suddivide le località in base al codice di temperatura
    while (lista != NULL) {
        Elemento* da_lib = lista; // Memorizza il puntatore all'elemento corrente
        lista = lista->next; // Passa all'elemento successivo

        char codice = assegna_codice(da_lib->temp);
        if (codice == 'c') {
            da_lib->next = calde;
            calde = da_lib;
        } else if (codice == 't') {
            da_lib->next = temperate;
            temperate = da_lib;
        } else {
            da_lib->next = fredde;
            fredde = da_lib;
        }
    }

    // Scrive le località calde
    Elemento* corrente = calde;
    while (corrente != NULL) {
        fprintf(file, "%s c\n", corrente->citta);
        Elemento* da_lib = corrente;
        corrente = corrente->next;
        free(da_lib);
    }

    // Scrive le località temperate
    corrente = temperate;
    while (corrente != NULL) {
        fprintf(file, "%s t\n", corrente->citta);
        Elemento* da_lib = corrente;
        corrente = corrente->next;
        free(da_lib);
    }

    // Scrive le località fredde
    corrente = fredde;
    while (corrente != NULL) {
        fprintf(file, "%s f\n", corrente->citta);
        Elemento* da_lib = corrente;
        corrente = corrente->next;
        free(da_lib);
    }

    fclose(file); // Chiude il file
}

//----------------------------------/

int main() {
	
    Elemento *lista_temperature = crea_lista_da_file("temperature.txt");
    scrivi_lista_su_file(lista_temperature, "output.txt");

	printf("\n");
	system("PAUSE");
	return 0;
}
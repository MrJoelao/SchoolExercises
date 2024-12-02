/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
/---------*/

//---------/*	Librerie:
#include <stdio.h>    // Libreria per l'input/output standard
#include <stdlib.h>   // Libreria per l'allocazione dinamica di memoria

//-------------------------/

//---------/*	Define:

//----------------------------------/

//---------/ Lista:
typedef struct elemento {
    int info;
    struct elemento* next;
} Elemento;

//----------------------/

//---------/ Funzioni:

// Questa funzione inserisce un elemento all'inizio della lista
void inserisci_testa(Elemento **lista, int elem) {
    Elemento* aux;
    aux = malloc(sizeof(Elemento));   // Alloca dinamicamente memoria per il nuovo elemento
    aux->info = elem;                // Imposta il valore dell'elemento
    aux->next = *lista;              // Il nuovo elemento punta al primo elemento della lista
    *lista = aux;                    // Aggiorna il puntatore alla testa della lista con il nuovo elemento
    return;
}

// Questa funzione inserisce un elemento alla fine della lista
void inserisci_coda(Elemento **lista, int elem) {
    Elemento* ultimo;                  // Puntatore utilizzato per la scansione della lista
    Elemento* new_elem = malloc(sizeof(Elemento)); // Alloca dinamicamente memoria per il nuovo elemento
    new_elem->info = elem;            // Imposta il valore dell'elemento
    new_elem->next = NULL;            // Il nuovo elemento punta a NULL in quanto sarà l'ultimo elemento
    if (*lista == NULL) {             // Se la lista è vuota
        *lista = new_elem;            // Il nuovo elemento diventa il primo elemento della lista
    } else {
        ultimo = *lista;
        while (ultimo->next != NULL)  // Scorre la lista fino all'ultimo elemento
            ultimo = ultimo->next;
        ultimo->next = new_elem;      // Collega l'ultimo elemento alla nuova coda
    }
}

void stampa_lista(Elemento *head){
	Elemento *temp=head;
		while(temp!=NULL){
			printf("%d\n",temp->info);
			temp=temp->next;
		}
	return;
}

//----------------------/

//----/* Int Main:
int main() {
    //---------/ Variabili:
    Elemento* lista = NULL;  // Inizializza la lista a vuota
    //----------------------/

    //---------/ Algoritmo Risolutivo:
    inserisci_coda(&lista, 1);  // Inserisce 1 all'inizio della lista
    inserisci_coda(&lista, 2);  // Inserisce 2 all'inizio della lista
    inserisci_coda(&lista, 3);  // Inserisce 3 all'inizio della lista

    // Stampa gli elementi della lista
    stampa_lista(lista);

    // Dealloca la memoria occupata dalla lista
    while (lista != NULL) {
        Elemento* temp = lista;
        lista = lista->next;
        free(temp);
    }
    //---------------------------------/

    printf("\n");
    system("PAUSE");
    return 0;
}
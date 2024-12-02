	/*---------/ Informazioni:

	Autore: Joel Stephan e Pietro vannucchi
	Versione: 0

/------------------------*/
/*---------/ Testo:
Sistema di gestione di un negozio:
Crea un sistema di gestione per un negozio che utilizza una lista collegata per tenere traccia degli
articoli in magazzino. Ogni nodo della lista dovrebbe rappresentare un prodotto e contenere
informazioni come il codice, la descrizione, il prezzo e la quantità disponibile. Implementa funzioni
per aggiungere nuovi prodotti, aggiornare le quantità in magazzino e generare fatture per gli
acquisti.
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>

//-------------------------/

//---------/*	Define:
#define MAX_NOME 20+1 //ipotizzo 20 caratterti come massimo numero dell'array (+1 per il carattere di tappo)
#define MAX_CODICE 13+1 //ipotizzo 13 caratterti come numero massimo per il codice (+1..)
#define MAX_DESCRIZIONE 100+1 //scelgo 100 caratteri come massima lunghezza della descrizione (+1..)

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
//----------------------------------/

//---------/*	Struct:
typedef struct nodo{
	char nome[MAX_NOME];
	char codice[MAX_CODICE];
	char descrizione[MAX_DESCRIZIONE];
	float prezzo;
	int quantita;
	struct nodo *next;
}Prodotto;

//----------------------------------/

//---------/*	Funzioni:
FILE *open_file (FILE *file, char *nomeFile, char *mode){
	file=fopen(nomeFile, mode);
    if (file==NULL){					    
        printf("ERRORE: Apertura file invalida.\n");
        exit(-1);
    }
	return file;
}

void close_file(FILE *file){
	if(fclose(file)!=0) {
        printf("ERRORE: Chiusura file invalida.\n");
        exit(-2);
    }
    return;
}

void input_accensione(char *nomeFile, Prodotto** lista){
    FILE* file = open_file(NULL, nomeFile, "r");

    int flag = 0; // Utilizzo una variabile per gestire la condizione di uscita

    while (!flag) {
        Prodotto* nuovoProdotto = (Prodotto*)malloc(sizeof(Prodotto));

        if (nuovoProdotto == NULL) {
            printf("ERRORE: all'allocazione della memoria invalida.\n");
            fclose(file);
            exit(-1);
        }

        if (fscanf(file, "%s %s %s %f %d", nuovoProdotto->nome, nuovoProdotto->codice, nuovoProdotto->descrizione, &nuovoProdotto->prezzo, &nuovoProdotto->quantita) == EOF) {
            free(nuovoProdotto);
            flag = 1; // Imposto a 0 per uscire dal loop
        }
        else {
            nuovoProdotto->next = NULL; // Inizializza il campo 'next' del nuovo prodotto

            if (*lista == NULL) {
                // Se la lista è vuota, il nuovo prodotto diventa il primo elemento
                *lista = nuovoProdotto;
            } else {
                // Altrimenti, trova l'ultimo elemento e aggiungi il nuovo prodotto alla fine
                Prodotto* ultimo = *lista;
                while (ultimo->next != NULL) {
                    ultimo = ultimo->next;
                }
                ultimo->next = nuovoProdotto;
            }
        }
    }

    return;
}


void stampa_prodotto(Prodotto *prodotto){
	
    // Stampa delle informazioni del prodotto
    printf("Nome: %s\n", prodotto->nome);
    printf("Codice: %s\n", prodotto->codice);
    printf("Descrizione: %s\n", prodotto->descrizione);
    printf("Prezzo: %.2f\n", prodotto->prezzo);
    printf("Quantita': %d\n", prodotto->quantita);
    printf("-------------------------\n");
    
    return;
}

void stampa_lista(Prodotto *lista){
    // Verifica se la lista è vuota
    if (lista == NULL){
        printf("La lista e' vuota.\n");
        exit(-2);
    }

    // Itera attraverso la lista e stampa ciascun prodotto
    Prodotto *attuale = lista;
    while (lista != NULL){
        stampa_prodotto(lista);
        // Passa al successivo nella lista
        lista = lista->next;
    }
    
    system("PAUSE");
	system("CLS");
    return;
}

// Funzione per verificare se un codice è già presente nella lista
int codice_presente(Prodotto *lista, char *codice){
	int flag = 0; // Codice non presente
	
    while (lista != NULL) {
        if (strcmp(lista->codice, codice) == 0) {
            flag = 1; // Codice già presente
        }
        lista = lista->next;
    }
    return flag; 
}

// Funzione per ottenere un prezzo valido (maggiore o uguale a zero)
float input_prezzo_valido(){
    float prezzo;
    do {
        printf("Inserisci il prezzo del nuovo prodotto (deve essere maggiore o uguale a zero): ");
        scanf("%f", &prezzo);
        if (prezzo < 0) {
            printf("ERRORE: Il prezzo deve essere maggiore o uguale a zero.\n");
        }
    } while (prezzo < 0);
    return prezzo;
}

// Funzione per ottenere una quantità valida (maggiore o uguale a zero)
int input_quantita_valida(){
    int quantita;
    do {
        printf("Inserisci la quantita' del nuovo prodotto (deve essere maggiore o uguale a zero): ");
        scanf("%d", &quantita);
        if (quantita < 0) {
            printf("ERRORE: La quantita' deve essere maggiore o uguale a zero.\n");
        }
    } while (quantita < 0);
    return quantita;
}

void aggiunta_prodotto(Prodotto **lista){
    // Allocazione di memoria per un nuovo prodotto
    Prodotto* nuovoProdotto = (Prodotto*)malloc(sizeof(Prodotto));

    if (nuovoProdotto == NULL) {
        printf("ERRORE: all'allocazione della memoria invalida.\n");
        exit(-1);
    }

    // Input dei dati per il nuovo prodotto
    printf("Inserisci il nome del nuovo prodotto: ");
    scanf("%s", nuovoProdotto->nome);

    // Input del codice del nuovo prodotto con controllo sulla presenza
    do {
        printf("Inserisci il codice del nuovo prodotto: ");
        scanf("%s", nuovoProdotto->codice);
        
        if (codice_presente(*lista, nuovoProdotto->codice)) {
            printf("ERRORE: Il codice inserito e' gia' presente. Inseriscine uno nuovo.\n");
        }
        
    } while (codice_presente(*lista, nuovoProdotto->codice));

    printf("Inserisci la descrizione del nuovo prodotto: ");
    scanf("%s", nuovoProdotto->descrizione);

    // Input del prezzo del nuovo prodotto con controllo sulla validità
    nuovoProdotto->prezzo = input_prezzo_valido();

    // Input della quantità del nuovo prodotto con controllo sulla validità
    nuovoProdotto->quantita = input_quantita_valida();

    // Inizializzazione del campo 'next' del nuovo prodotto
    nuovoProdotto->next = NULL;

    // Aggiunta del nuovo prodotto alla lista
    if (*lista == NULL) {
        // Se la lista è vuota, il nuovo prodotto diventa il primo elemento
        *lista = nuovoProdotto;
    } else {
        // Altrimenti, trova l'ultimo elemento e aggiungi il nuovo prodotto alla fine
        Prodotto* ultimo = *lista;
        while (ultimo->next != NULL) {
            ultimo = ultimo->next;
        }
        ultimo->next = nuovoProdotto;
    }

    printf("Prodotto aggiunto con successo!\n");
    
    system("PAUSE");
	system("CLS");
	return;
}

void salva_su_file(char *nomeFile, Prodotto *lista){
    FILE* file = open_file(NULL, nomeFile, "w");

    // Scrivi ogni prodotto nel file
    while (lista != NULL) {
        fprintf(file, "%s %s %s %.2f %d\n", lista->nome, lista->codice, lista->descrizione, lista->prezzo, lista->quantita);
        lista = lista->next;
    }

    // Chiudi il file dopo aver scritto tutti i prodotti
    close_file(file);
    
    return;
}

void aggiorna_quantita(Prodotto *lista) {
    char codice[MAX_CODICE];
    int nuova_quantita;
    int prodotto_trovato = 0;  // Flag che indica se il prodotto è stato trovato

    // Verifica se la lista è vuota
    if (lista == NULL) {
        printf("La lista e' vuota.\n");
        exit(-2);
    }

    // Input del codice del prodotto da aggiornare
    printf("Inserisci il codice del prodotto da aggiornare: ");
    scanf("%s", codice);

    // Cerca il prodotto con il codice corrispondente nella lista
    Prodotto* prodotto = lista;
    while (prodotto != NULL) {
        if (strcmp(prodotto->codice, codice) == 0) {
            // Trovato il prodotto, chiedi la nuova quantità
            printf("Inserisci la nuova quantita' per il prodotto %s: ", codice);
            scanf("%d", &nuova_quantita);

            // Aggiorna la quantità
            prodotto->quantita = nuova_quantita;

            printf("Quantita' aggiornata con successo!\n");
            prodotto_trovato = 1;  // Imposta il flag a true
        }

        // Passa al successivo nella lista
        prodotto = prodotto->next;
    }

    // Se nessun prodotto è stato trovato, stampa un messaggio
    if (!prodotto_trovato) {
        printf("Prodotto non trovato.\n");
    }
 
    system("PAUSE");
	system("CLS");
    return;
}

void ricerca_prodotto(Prodotto *lista) {
	char codice_da_cercare[MAX_CODICE];	
	int trovato = 0;  // Flag che indica se il prodotto è stato trovato
	
    // Verifica se la lista è vuota
    if (lista == NULL) {
        printf("La lista e' vuota.\n");
        exit(-2);
    }

    // Input del codice del prodotto da cercare
    printf("Inserisci il codice del prodotto da cercare: ");
    scanf("%s", codice_da_cercare);

    // Cerca il prodotto con il codice corrispondente nella lista
    Prodotto* prodotto_trovato = lista;

    while (prodotto_trovato != NULL) {
        if (strcmp(prodotto_trovato->codice, codice_da_cercare) == 0) {
        	
            // Trovato il prodotto, stampa le informazioni
            printf("Prodotto trovato:\n");
            stampa_prodotto(prodotto_trovato);
            trovato = 1;  // Imposta il flag a true
        }

        // Passa al successivo nella lista
        prodotto_trovato = prodotto_trovato->next;
    }

    // Se nessun prodotto è stato trovato, stampa messaggio d'errore
    if (!trovato) {
        printf("Nessun prodotto trovato con il codice %s.\n", codice_da_cercare);
	}
	
    system("PAUSE");
    system("CLS");
    return;
}

void generazione_fattura(Prodotto *lista) {
    char codice_acquisto[MAX_CODICE];
    int quantita_acquisto;
    float totale;

    // Verifica se la lista è vuota
    if (lista == NULL) {
        printf("La lista dei prodotti e' vuota. Impossibile generare la fattura.\n");
        exit(-2);
    }

    // Stampa la lista dei prodotti disponibili
    printf("Prodotti disponibili:\n");
    stampa_lista(lista);

    // Input del codice del prodotto da acquistare
    printf("Inserisci il codice del prodotto che vuoi acquistare: ");
    scanf("%s", codice_acquisto);

    // Ricerca del prodotto nella lista
    Prodotto* prodotto_acquisto = lista;
    while (prodotto_acquisto != NULL && strcmp(prodotto_acquisto->codice, codice_acquisto) != 0) {
        prodotto_acquisto = prodotto_acquisto->next;
    }

    // Verifica se il prodotto è stato trovato
    if (prodotto_acquisto == NULL){
        printf("Il prodotto con il codice %s non e' disponibile.\n", codice_acquisto);
        
    } else {
        // Input della quantità da acquistare
        printf("Inserisci la quantita' che vuoi acquistare: ");
        scanf("%d", &quantita_acquisto);

        // Verifica se la quantità disponibile è sufficiente
        if (quantita_acquisto > prodotto_acquisto->quantita){
        	
            printf("Quantita' disponibile non sufficiente per l'acquisto.\n");
            
        } else {
            // Calcolo del totale e aggiornamento della quantità disponibile
            totale = quantita_acquisto * prodotto_acquisto->prezzo;
            prodotto_acquisto->quantita -= quantita_acquisto;

            // Apertura del file delle ricevute in modalità d'aggiunta
            FILE* file_ricevute = open_file(NULL, "ricevute.txt", "a");

            // Scrittura della ricevuta nel file
            fprintf(file_ricevute, "Prodotto acquistato:\n");
            fprintf(file_ricevute, "Nome: %s\n", prodotto_acquisto->nome);
            fprintf(file_ricevute, "Codice: %s\n", prodotto_acquisto->codice);
            fprintf(file_ricevute, "Descrizione: %s\n", prodotto_acquisto->descrizione);
            fprintf(file_ricevute, "Prezzo unitario: %.2f\n", prodotto_acquisto->prezzo);
            fprintf(file_ricevute, "Quantita' acquistata: %d\n", quantita_acquisto);
            fprintf(file_ricevute, "Totale: %.2f\n", totale);
            fprintf(file_ricevute, "-------------------------\n");

            // Chiusura del file delle ricevute
            close_file(file_ricevute);

            printf("Acquisto completato. Ricevuta generata e salvata nel file 'ricevute.txt'.\n");
        }
    }

	system("PAUSE");
    system("CLS");
    return;
}

//----------------------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	int scelta;
	Prodotto *lista = NULL;
	//----------------------/
	
	//---------/ Algoritmo Risolutivo:
	
	//Caricamento dei prodotti da file sulla lista.	
	input_accensione("prodotti.txt", &lista);
	
	do {
        printf("--- Benvenuto nel Menu ---\n");
        
		printf(GREEN " 1. Stampa " RESET " - Mostra l'elenco completo dei prodotti disponibili.\n");
		printf(GREEN " 2. Ricerca " RESET " - Trova e visualizza le informazioni di un prodotto specifico con il suo codice.\n");
		printf(YELLOW " 3. Aggiunta" RESET " - Inserisci nuovi prodotti nel magazzino.\n");
		printf(YELLOW " 4. Modifica Quantita'" RESET " - Modifica le quantita' disponibili dei prodotti.\n");
		printf(CYAN " 5. Generazione Fatture" RESET " - Crea fatture per le transazioni di acquisto.\n");
		printf(RED " 6. Esci " RESET " - Chiudi l'applicazione.\n");
		
		printf("Inserisci il numero corrispondente alla tua scelta: ");
		scanf("%d", &scelta);


        switch (scelta) {
            case 1:
            	system("CLS");
            	
			    // Stampa prodotti
    			stampa_lista(lista);
    			
                break;
                
            case 2:
            	system("CLS");
            	
				//ricerca prodotto
                ricerca_prodotto(lista);
                
                break;
                
            case 3:
            	system("CLS");
					
            	// Aggiunta di nuovi prodotti
			    aggiunta_prodotto(&lista);
			    
			    // Salva la lista aggiornata nel file
			    salva_su_file("prodotti.txt", lista);

                break;
            
            case 4:
            	system("CLS");
            	
				// Aggiornamento delle quantita' in magazzino
    			aggiorna_quantita(lista);
    			
    			// Salva la lista aggiornata nel file
    			salva_su_file("prodotti.txt", lista);
    			
                break;
            
            case 5:
            	system("CLS");
            	
				// Generazione di fatture per gli acquisti
                generazione_fattura(lista);
                
                // Salva la lista aggiornata nel file
                salva_su_file("prodotti.txt", lista);
                
                break;  
                
            case 6:
            	system("CLS");
            	
                printf(RED "Uscita dal completata, arrivederci!\n" RESET);
                break;
                
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    } while (scelta != 6);
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

/*
Autore: Pietro Vannucchi
Data: 17/11/2023
Versione: 0
Testo: Crea un sistema di gestione per un negozio che utilizza una lista collegata per tenere traccia degli
		articoli in magazzino. Ogni nodo della lista dovrebbe rappresentare un prodotto e contenere
		informazioni come il codice, la descrizione, il prezzo e la quantità disponibile. Implementa funzioni
		per aggiungere nuovi prodotti, aggiornare le quantità in magazzino e generare fatture per gli
		acquisti.
Analisi:
*/

#include <stdio.h>
#include <stdlib.h> //13 è il numero massimo di un codice a barre di un prodotto al supermercato. Con +1 come carattere di tappo
#define MAX_DESCRIZIONE 100+1 //massima lunghezza per la descrizione con +1 per carattere di tappo
#define MAX_NOME 20+1 // massima lunghezza per il nome del prodotto con +1 per carattere di tappo


struct Prodotto *head; // creazione puntatore alla testa della lista


typedef struct Prodotto{
	char nome[MAX_NOME];
	int codice;
	char descrizione[MAX_DESCRIZIONE];
	float prezzo;
	int quantita;
	struct Prodotto *next;
} Prodotto;



void visualizza_lista()
{
struct Prodotto *p = head;
struct Prodotto *ultimostampato;

	do
	{
	printf("%s - ", p->nome);
	printf("%d - ", p->codice);
	printf("%s - ", p->descrizione);
	printf("%f - ", p->prezzo);
	printf("%d - ", p->quantita);

	ultimostampato = p;
	p = p->next;
	} while(ultimostampato->next!=NULL);
	printf("end");
}




/* funzione creazione primo elemento */
struct Prodotto* crea_lista()
{
struct Prodotto *p, *punt;
int i, n;

p = (struct Prodotto *)malloc(sizeof(struct Prodotto));


p->codice=0;
p->prezzo=12.3;
p->quantita=0;


return p;	
}

/* funzione inserimento elemento in coda alla lista */
void inserimento_in_coda(char nome_p[21],int codice_p,char descrizione_p[101], float prezzo_p, int quantita_p)
{
struct Prodotto *p, *punt;
p = (struct Prodotto *)malloc(sizeof(struct Prodotto));

for(int i=0; i<21;i++)
{
	p->nome[i]=nome_p[i];
}
p->codice=codice_p;

for(int i=0; i<101;i++)
{
	p->descrizione[i]=descrizione_p[i];
}

p->prezzo=prezzo_p;
p->quantita=quantita_p;

p->next=NULL;
}


FILE *myFopen(char *nomefile, char *tipo){
	FILE *fd=fopen(nomefile, tipo);
	if(fd==NULL){
		printf("Errore nell'aprire il file");
		exit(1);
	}
	return fd;
}

void myFclose(FILE *fd){
	if(fd!=0){
		printf("Errore nell chiusura del file");
		exit(2);
	}
}



void leggi_file(FILE *fd, Prodotto *articoli){
	int num;
	while(fscanf(fd, "%s %d %s %f %d", articoli->nome, articoli->codice, articoli->descrizione, articoli->prezzo, articoli->quantita)!=EOF){
		fscanf(fd, "%s %d %s %f %d", articoli->nome, articoli->codice, articoli->descrizione, articoli->prezzo, articoli->quantita);
		inserimento_in_coda(articoli->nome, articoli->codice, articoli->descrizione, articoli->prezzo, articoli->quantita);

	}
}

void stampa_file(){
}

void aggiungi_prodotti(){
}

void aggiungi_quantita(){
}

void gen_fatture(){
}

int main(){
	
	
head = crea_lista(); //creiamo la lista che ospiterò i dati dal file

	FILE *fd;
	int scelta;
	fd=fopen("negozio.txt", "r");
	
	fclose(fd);
	do {
        printf("Menu:\n");
        printf("1. Stampa prodotti\n");
        printf("2. Aggiunta di nuovi prodotti\n");
        printf("3. Aggiunta delle quantità in magazzino\n");
        printf("4. Generazione di fatture per gli acquisti\n");
        printf("Inserisci la tua scelta: ");
        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
                visualizza_lista();
                break;
            case 2:
            	system("CLS");
                aggiungi_prodotti();
                break;
            case 3: 
				system("CLS");
				aggiungi_quantita();
				break;
			case 4:
				system("CLS");
				gen_fatture();	    
            case 5:
                printf("Uscita dal programma...\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    } while (scelta != 3);


	printf("\n");
	system("PAUSE");
	return 0;
}
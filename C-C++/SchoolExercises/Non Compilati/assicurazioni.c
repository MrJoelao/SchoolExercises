/*---------/ Informazioni:

	Autore: Joel Stephan
	Data: 13/11/2023
	Versione: 0

/------------------------*/
/*---------/ Testo:
	La compagnia assicurativa:
	Una compagnia assicurativa registra i principali dati relativi alle polizze RC-auto e i dati relativi agli incidenti
	automobilistici segnalati all'assicurazione su due file.
	Il file relativo agli incidenti contiene per ogni incidente le seguenti informazioni:
		• targa dell'autoveicolo a cui si riferisce la segnalazione (stringa di 7 caratteri) ;
		• data dell'incidente (formato a scelta del candidato) ;
		• un carattere che può essere 'S' oppure 'N', e che denota se il veicolo è stato responsabile (S) oppure
		  no (N) dell'incidente.
		
	Il file relativo alle polizze contiene per ogni polizza le seguenti informazioni:
		• targa dell'autoveicolo (stringa 7 caratteri) ;
		• classe di merito (intero compreso tra 0 e 20);
		• nome dell'intestatario della polizza (stringa di al più 20 caratteri non contenente spazi).
		
	In base ai dati contenuti nei due file la compagnia deve aggiornare le classi di merito associate alle polizze
	secondo il seguente criterio: se l'autoveicolo non è responsabile di alcun incidente, la classe di merito viene
	decrementata di uno (fino ad un minimo di 0), mentre per ogni incidente di cui l'autoveicolo è responsabile,
	la classe di merito viene incrementata di 2 (fino ad un massimo di 20).
	
	Si richiede di risolvere i seguenti punti:
		1. Scrivere le definizioni dei tipi di dato C da utilizzarsi per risolvere i punti successivi.
		2. Scrivere una funzione C che riceva come parametro il nome di un file di incidenti e, in base alle
		   informazioni contenute in tale file, costruisca e restituisca opportunamente una lista, rappresentata
		   mediante strutture e puntatori, in cui ogni elemento è una coppia <t,n>, dove t è una targa di
		   autoveicolo ed n è un intero positivo che denota il numero di incidenti di cui l'autoveicolo è stato
		   responsabile.
		3. Scrivere una funzione C che riceva come parametri il nome di un file di polizze ed una lista di coppie
		   <t,n> (come definita al punto 2), ed aggiorni le classi di merito nel file di polizze in base alle
	   	   informazioni contenute nella lista.
/---------*/

/*---------/ Analsi:

/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>

//-------------------------/

//---------/*	Define:
#define MAX_TARGA 7+1
#define MAX_DATA 10+1
#define MAX_NOME 20+1
#define MAX_FILE 100
//----------------------------------/

//---------/*	Struct:
// Struttura per rappresentare un incidente
typedef struct{
    char targa[MAX_TARGA]; 
    char data[MAX_DATA];  
    char responsabile; 
}incidente;

// Struttura per rappresentare una polizza RC-auto
typedef struct{
    char targa[MAX_TARGA];  
    int classeM;   
    char intestatario[MAX_NOME];  
}polizza;

// Lista per rappresentare una coppia <targa, numero_incidenti>
typedef struct elemento{
    char targa[MAX_TARGA]; 
    int numeroIncidenti; 
	struct elemento* next;
}nIncidenti;

//----------------------------------/

//---------/*	Funzioni:
void leggi_file(incidente arrayIncidenti[], int *numIncidenti) {
    char nome_file[MAX_FILE];
    int i;
    FILE *file;

    printf("Inserisci il nome del file da leggere (Es: nome.txt): ");
    scanf("%s", nome_file);

    file = fopen(nome_file, "r");

    if (file == NULL) {
        printf("Errore nell'apertura del file. Assicurati che il file esista e sia accessibile.\n");
        exit(1);
    }

    *numIncidenti = 0;

    while (fscanf(file, "%7s %10s %c\n", arrayIncidenti[*numIncidenti].targa, arrayIncidenti[*numIncidenti].data, &arrayIncidenti[*numIncidenti].responsabile) == 3 && *numIncidenti < MAX_FILE) {
        (*numIncidenti)++;
    }

    printf("Incidenti letti da file:\n");
    for (i=0; i<*numIncidenti; i++) {
        printf("Targa: %s, Data: %s, Responsabile: %c\n",
               arrayIncidenti[i].targa, arrayIncidenti[i].data, arrayIncidenti[i].responsabile);
    }

    printf("\nFine file.\n");
    fclose(file);
}




//----------------------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	int scelta, numIncidenti;
    incidente arrayIncidenti[MAX_FILE]; 
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	do {
        printf("-----------| Menu': |-----------\n");
        printf(" 1. Costruisci lista incidenti\n");
        printf(" 2. Aggiorna classi di merito\n");
        printf(" 3. Esci\n");
        printf("--------------------------------\nScegliere una delle opzioni: ");

        scanf("%d", &scelta);

        switch (scelta) {
            case 1:
            	system("CLS");
				leggi_file(arrayIncidenti, &numIncidenti);
                break;

            case 2:

                break;

            case 3:
                printf("Uscita dal programma.\n");
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

//----/* Informazioni:
/* Autore:	Joel Stephan
   Data:
   Versione: 0				 */
//----------------------------\\

//---------/*	Testo:
/*
  6 - Creazione di un file binario
Si realizzi un programma che costruisca un file binario di nome "anagrafe" contenente le informazioni relative ai cittadini di un comune italiano.
Ogni record del file "anagrafe" rappresenta una persona abitante nel comune e contiene le seguenti informazioni:
Nome: una stringa che rappresenta il nome della persona;
Cognome: una stringa che rappresenta il cognome della persona;
Data di nascita: un insieme di tre interi che rappresenta la data di nascita;
Luogo di nascita: una stringa che rappresenta la località di nascita;
Indirizzo: una stringa che rappresenta l'indirizzo della persona;
Codice Fiscale: una sequenza di 16 caratteri che individua univocamente il cittadino.
Il programma dovrà riempire il file "anagrafe" con informazioni immesse dall'utente attraverso lo standard input e, successivamente, visualizzarne il contenuto.

Per risolvere il problema è necessario predisporre un tipo di dato adatto a rappresentare il record logico del file da creare:



struct elemento

{       char nome[50];

        char cognome[50];

        char l_nascita[50];

        char indirizzo[80];

        char CF[16];

};

 



Il programma è suddiviso in due funzioni:



void creafile(char *v);

void vedifile(char *v);

che servono rispettivamente a creare e a visualizzare il contenuto del file binario il cui nome v è dato come parametro.
*/
//----------------------------------\\

//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>

//-----------------------\\

//---------/*	Define:

//---------------------\\

//---------/*	Struct:
typedef struct Elemento{
    char nome[50];
    char cognome[50];
    int data_nascita[3];
    char luogo_nascita[50];
    char indirizzo[80];
    char CF[16];
}elemento;
//---------------------\\

//----/* Funzioni:
void creafile(char *nome_file) {
	elemento persona;
	int num_cittadini;
	
    FILE *file = fopen(nome_file, "wb");
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return;
    }

    printf("Inserisci il numero di cittadini da registrare: ");
    scanf("%d", &num_cittadini);

    for (int i = 0; i < num_cittadini; i++) {
        printf("Inserisci i dati del cittadino %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", persona.nome);

        printf("Cognome: ");
        scanf("%s", persona.cognome);

        printf("Data di nascita (GG MM AAAA): ");
        scanf("%d %d %d", &persona.data_nascita[0], &persona.data_nascita[1], &persona.data_nascita[2]);

        printf("Luogo di nascita: ");
        scanf("%s", persona.luogo_nascita);

        printf("Indirizzo: ");
        scanf("%s", persona.indirizzo);

        printf("Codice Fiscale: ");
        scanf("%s", persona.CF);

        fwrite(&persona, sizeof(elemento), 1, file);
    }

    fclose(file);
    printf("File \"%s\" creato con successo.\n", nome_file);
}

void vedifile(char *nome_file) {
	elemento persona;
    FILE *file = fopen(nome_file, "rb");
    if (file == NULL) {
        printf("Errore nell'apertura del file.\n");
        return;
    }

    printf("Contenuto del file \"%s\":\n", nome_file);

    while (fread(&persona, sizeof(elemento), 1, file) == 1) {
        printf("Nome: %s\n", persona.nome);
        printf("Cognome: %s\n", persona.cognome);
        printf("Data di nascita: %02d/%02d/%04d\n", persona.data_nascita[0], persona.data_nascita[1], persona.data_nascita[2]);
        printf("Luogo di nascita: %s\n", persona.luogo_nascita);
        printf("Indirizzo: %s\n", persona.indirizzo);
        printf("Codice Fiscale: %s\n", persona.CF);
        printf("\n");
    }

    fclose(file);
}
//---------------\\

//----/* Int Main:
int main() {
	//---------/*	Variabili:
	char *nome_file = "anagrafe.dat";
	//-----------------------\\

	//---------/*	Algoritmo Risolutivo:
	creafile(nome_file);
    vedifile(nome_file);
	//----------------------------------\\
    

    printf("\n");
	system("PAUSE");
	return 0;
}

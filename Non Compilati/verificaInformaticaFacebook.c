/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
Esercizio 1
Immagina di lavorare per “Facebook”.  L’azienda desidera sviluppare un software per effettuare analisi matematiche sul numero di like che gli utenti rilasciano giornalmente. Nel file di testo “utenti.txt”, per ogni utente, vengono  memorizzate le seguenti informazioni.
    • nome
    • numero di like giornalieri
    • numero di cuori giornalieri
Scrivere le funzioni per:
    1. leggere dal file le informazioni necessarie
    2. stampare a video le informazioni lette
    3. ricercare l’utente che ha postato più like
    4. ordinare in modo crescente gli utenti secondo il numero di cuori postati
    5. indicare il nome degli utenti che hanno più like che cuori 
    6. stampare le informazioni trovate sul file di testo “statistica.txt”
    
Preposizioni
    presuppongo che la lunghezza massima di un nome utente sia 99 caratteri (99+1 carattere di tappo)
    presuppongo che gli utenti massimi sia di 1000
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>
	#include   "TheLib-J.h"

//-------------------------/

//---------/*	Define:
	#define maxNome 100
	#define maxUtenti 1000
//----------------------------------/

//---------/ Struct
typedef struct dati{
		char nomeUtente[maxNome];
		int like;
		int cuori;
	}Dati;
//----------------------/

//---------/ Funzioni:
int input(Dati datiUtenti[], FILE *fd){
	int numeroUtenti,i;
	
	fscanf(fd,"%d",&numeroUtenti);

	for(i=0; i<numeroUtenti; i++){
		fscanf(fd,"%s",&datiUtenti[i].nomeUtente);
		fscanf(fd,"%d",&datiUtenti[i].like);
		fscanf(fd,"%d",&datiUtenti[i].cuori);
	}
	return numeroUtenti;
}

void output(Dati datiUtenti[], int numeroUtenti){
	int i;
	for(i=0; i<numeroUtenti; i++){
		printf("%s, %d %d\n",datiUtenti[i].nomeUtente,datiUtenti[i].like,datiUtenti[i].cuori);
	}
	return;
}

//funzione presa dalla libreria e rielaborata con il tipo di dato "dati"
int vMaxUtente(Dati datiUtenti[], int lunghezza) {
    int maggiore,i; 
    maggiore=datiUtenti[0].like; //assegno come maggiore il primo utenet

    for (i=1; i<lunghezza; i++) {	
        if (datiUtenti[i].like>maggiore) {	
            maggiore=i;	
        }
    }
    return maggiore;
}

//funzione presa dalla libreria e rielaborata con il tipo di dato "dati" (per ordinamento)
void swap_Dati (Dati *a, Dati *b) {
    Dati temp = *a; 
    *a = *b;	
    *b = temp;	
}


//funzione presa dalla libreria e rielaborata con il tipo di dato "dati"
/*void bubble_sort_Dati(Dati datiUtenti[], int lunghezza) {
    int i, indice;

    for (i=0; i<lunghezza-1; i++) {
	
        for (indice=0; indice<lunghezza-1-i; indice++) 

            if (datiUtenti[indice].cuori>datiUtenti.cuori[indice+1]) {
                swap_Dati(datiUtenti[indice], datiUtenti[indice+1]);
            }
        }
    }
}*/

void likeCuori(Dati datiUtenti[], int numeroUtenti, FILE *fd1){
	int i;
	for (i=0; i<numeroUtenti; i++){
        if (datiUtenti[i].like>datiUtenti[i].cuori) { //se i like del utente i sono maggiori dei cuori allora stampa nel file
            fprintf(fd1,"-%s\n",datiUtenti[i].nomeUtente);	
        }
    }
    return;
}

//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	Dati datiUtenti[maxUtenti];
	FILE *fd, *fd1;
	int numeroUtenti,i;
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	
	fd=open_file(fd,"utenti.txt","r"); //apro il file utenti.txt in modalità read (r) in modo da leggere i dati con la mia funzione in lib.
	
	//Num: 1
	numeroUtenti=input(datiUtenti,fd); //leggo i dati contenuti nel file e mi ritorno indietro il numero di utenti perchè necessario per altre funzioni
	if(numeroUtenti<0){
		printf("ERRORE: Il numero di utenti non può essere negativo");
		exit(-5);
	}
	
	close_file(fd); //vado a chiudere perchè non mi serve più da tenere aperto dato che le funzioni dopo non lo neccessitano
	
	//Num: 2.
	output(datiUtenti,numeroUtenti); //stampo a video i dati letti (nome utente, like, cuori) usando il numero degli utenti ricavato dalla funzione input
									
	fd1=open_file(fd1,"statitica.txt","w"); //apro il file statitica.txt in modalità write (w) in modo da scrivere dentro al file
	
	//Num: 3 e 6.
	fprintf(fd1,"Utente con il maggiore numero di like: %d\nNome degli utenti che hanno più like che cuori:\n",vMaxUtente(datiUtenti,numeroUtenti));
	/*
	  trovo utente con il maggiore numero di like e lo stampo nel file allo stesso tempo in modo da non dover creare una variabile a posta solo per 
	  utente con il maggiore numero di like e nella stampa predispongo anche una scritta per la stampa della funzione n5 (il numero di utente con più 
	  like che cuori)
	*/
	
	
	//Num: 4.
//	void bubble_sort_Dati(); eeeh si
	
	//Num: 5 e 6.
	likeCuori(datiUtenti, numeroUtenti,fd1);
	/*
	  uso la funzione likeCuori per trovare ogni utente con un numero di like maggiore del numero dei cuori una volta trovato lo stampo subito in 
	  modo da evitare di creare un array di stringhe per salvarmi ogni nome e successivamente stamparlo dato che è più laborioso
	*/
	
	
	close_file(fd1); //chiudo il file data la fine del programma
	
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

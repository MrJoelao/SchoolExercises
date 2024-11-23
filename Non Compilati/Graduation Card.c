/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
Luca è stato invitato alla festa di laurea di Edoardo, dove sa che ci saranno molti coriandoli! Ha
ha comprato un biglietto di laurea e ora deve scriverci sopra un piccolo messaggio di auguri. Il messaggio
che vuole scrivere è lungo N parole, dove la parola i-esima è Wi.

	Figura 1: Il biglietto di laurea che Luca ha comprato.
	
Luca sa di commettere sempre degli errori quando scrive sui bigliettini. In particolare, sovrastima sempre lo spazio
lo spazio che può utilizzare per scrivere il messaggio, così finisce per scrivere le ultime parole molto più piccole delle prime.
prime. Per evitare ciò, ha deciso che ogni riga deve contenere al massimo K lettere o spazi.
Vuole disporre il messaggio in modo che la prima parola sia all'inizio della prima riga, seguita da tutte le altre.
tutte le altre parole. Quando una parola non entra in una riga, viene inserita in una nuova riga, seguita dalle altre parole e così via.
altre parole e così via. Potete aiutare Luca a scrivere il messaggio?
+ Tra gli allegati di questo compito potete trovare un file modello text.* con un esempio di implementazione incompleta.
incompleto.

Input
	La prima riga contiene l'intero N, il numero di parole del messaggio e K, la lunghezza massima della riga, compresi gli spazi.
	della riga, compresi gli spazi. Le N righe successive contengono una stringa Wi, la parola i-esima del messaggio.
Output
	Il messaggio deve essere scritto in modo che ogni riga contenga al massimo K caratteri o spazi, come descritto sopra.
	come descritto sopra. Tra ogni parola consecutiva della stessa riga deve esserci un carattere di spazio.
	Gli spazi alla fine di una riga saranno ignorati.
	testo Pagina 1 di 2
	
Vincoli
	- 1 ≤ N ≤ 100 000.
	- 1 ≤ K ≤ 109.
	- 1 ≤ |Wi| ≤ min(20, K), per ogni i = 0 . . . N - 1, dove |Wi| è la lunghezza della parola i-esima.
	- Wi è composta solo da lettere minuscole dell'alfabeto inglese, per ogni i = 0 . . . N - 1
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>
	#include   "TheLib-J.h"

//------------------------/

//---------/*	Define:
	#define max 1000
//---------------------/

//---------/ Funzioni:

//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	FILE *file;
	int i,N, NLetters;
	char temp[max],stringaIniziale[max][max];
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	file=open_file(file,"file.txt", "r");

	fscanf(file,"%d",&N);
	fscanf(file,"%d",&NLetters);
	
	for(i=0; i<=N; i++){
		fscanf(file,"%s",&stringaIniziale[i]);
	}
	
	for(i=0; i<N; i++){
		strcat(stringaIniziale[0]," ");
		strcat(stringaIniziale[0],stringaIniziale[i+1]);
	}
		
	printf("N:%d\tLettere:%d\n",N,NLetters);
	puts(stringaIniziale[0]);
	
	close_file(file);
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
LE LISTE, NON HO CAPITO NA MINCHIA SEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEH, in poche parole è una struct
che pero alla fine punta ad un'altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct, che punta ad un altra struct...
a mo di treno che ogni vagone e attaccato all'altro, comunque ci sono le slide in piattaforma.
cosa bisogna fare? boh, data sta struct/lista populare mettendoci libri ecc. Probabilmente chiederò a chat gpt
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>

//-------------------------/

//---------/*	Define:
#define MAX 30+1
//----------------------------------/

//---------/ struct:
//tipo di lista, copiata dalla piattaforma (c'è la foto, nulla di mio in poche parole)
typedef struct rec *lpointer;
typedef struct rec{
    char titolo[MAX];
    char autore[MAX];
    char editore[MAX];
    float prezzo;
    lpointer next;
} Libro;
lpointer cima=NULL;
//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

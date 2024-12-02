/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
Esempio uso struct senza uso degli indici (vedere "array_senza_indici.c)
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>

//-------------------------/

//---------/*	Define:

//----------------------------------/

//---------/ struct:
typedef struct {
    char nome[50];
    int eta;
} Persona;
//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	Persona *puntatore_persona;
	int numero_persone, i;
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	    
    
    // Allocazione dinamica di un array di strutture Persona
    numero_persone=3; // Esempio con 3 persone
    puntatore_persona=(Persona*)malloc(numero_persone *sizeof(Persona));
    
    // Popolamento dell'array di strutture Persona utilizzando i puntatori
    for (i=0; i<numero_persone; i++) {
        printf("Inserisci il nome della persona %d: ", i+1);
        scanf("%s", puntatore_persona[i].nome);
        printf("Inserisci l'eta' della persona %d: ", i+1);
        scanf("%d", &puntatore_persona[i].eta);
    }

    // Stampa delle persone utilizzando i puntatori
    printf("\nElenco delle persone:\n");
    for (i=0; i<numero_persone; i++) {
        printf("Persona %d: Nome = %s, Eta' = %d\n", i + 1, puntatore_persona[i].nome, puntatore_persona[i].eta);
    }

    // Liberazione della memoria allocata
    free(puntatore_persona);
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

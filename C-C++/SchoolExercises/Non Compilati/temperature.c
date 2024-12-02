/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
	Il programma deve generare, in modo casuale, un array contenete le temperature di un anno solare. Il programma deve stampare i nomi dei mesi 
	con i relativi valori di temperature medie. Quindi, deve stamparli ordine alfabetico crescente. Infine deve stamparli in ordine decrescente di 
	temperatura.
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>

//-------------------------/

//---------/*	Define:
	#define MAXMESE 12
	#define MAXCHAR 10
//----------------------------------/

//---------/*	struct:
	typedef struct meteo{
		char mese[MAXMESE];
		float temperature;
	}Meteo;
//----------------------------------/

//---------/ Funzioni:
void leggiTemp(Meteo *anno, char mesi[][MAXCHAR], int min, int max) {
    int i;
    min=min*100;
    max=max*100;

    for (i=0; i<MAXMESE; i++) {
    	
    	strcpy(anno[i].mese, mesi[i]);
    	
        anno[i].temperature=((rand()%(max-min+1))+min);
        anno[i].temperature=anno[i].temperature/100;
    }
}

float tMedia(float numeri[], int lunghezza) {
    float somma=0,i;
    
    for (i=0; i<lunghezza; i++) {
        somma=somma+numeri[i];
    }
    
    return somma/lunghezza;
}

void ordinamento(Meteo *anno, float tMedie[]){
    int scambiato;
    float temp2;
    Meteo temp1;
    
    do {
        scambiato = 0;
        for (int i=0; i<MAXMESE-1; i++) {
            if (tMedie[i]>tMedie[i+1]) {
                temp1=anno[i];
                anno[i]=anno[i+1];
                anno[i+1]=temp1;

                temp2=tMedie[i];
                tMedie[i]=tMedie[i+1];
                tMedie[i+1]=temp2;
                scambiato=1;
            }
        }
    } while (scambiato);
}

void stampaArray(Meteo *anno){
    int i;   
    for (i = 0; i < MAXMESE; i++) {
        printf("%s: %.2f\n", anno[i].mese, anno[i].temperature);
    }
}


//----------------------/

//----/* Int Main:
int main() {
	//---------/ Variabili:
	Meteo anno[MAXMESE];
    char mesi[MAXMESE][MAXCHAR] = {"Gennaio", "Febbraio", "Marzo", "Aprile", "Maggio", "Giugno", "Luglio", "Agosto", "Settembre", "Ottobre", "Novembre", "Dicembre"};
	float media;
	//----------------------/
	
    srand(time(NULL));
	
	//---------/ Algoritmo Risolutivo:
    leggiTemp(anno, mesi, 0, 30); 
	
	media=tMedia(anno, MAXMESE);
	
	printf("Temperatura media annuale: %.2f\nTemperature mensili in ordine alfabetico crescente e in ordine decrescente di temperatura:\n",media);
	
	ordinamento(anno, media)
	
    stampaArray(anno);

	//---------------------------------/
	
    printf("\n");
    system("PAUSE");
    return 0;
}

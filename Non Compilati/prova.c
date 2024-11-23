/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
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

//---------/*	Struct:
// Definizione della struttura dati per ogni elemento della lista
typedef struct TemperatureRecord {
    char name[20];
    int temperature;
    char code; // 'f', 't', 'c' per freddo, temperato, caldo
    struct TemperatureRecord* next; // Puntatore all'elemento successivo
} TemperatureRecord;
//----------------------------------/

//---------/ Funzioni:
// Funzione per creare un nuovo elemento della lista
TemperatureRecord* createRecord(const char name[], int temperature) {
    TemperatureRecord* record = (TemperatureRecord*)malloc(sizeof(TemperatureRecord));
    if (record != NULL) {
        strncpy(record->name, name, 20);
        record->temperature = temperature;
        if (temperature < 20)
            record->code = 'f';
        else if (temperature >= 20 && temperature <= 30)
            record->code = 't';
        else
            record->code = 'c';
        record->next = NULL;
    }
    return record;
}

// Funzione per aggiungere un elemento in testa alla lista
TemperatureRecord* insertRecord(TemperatureRecord* list, TemperatureRecord* newRecord) {
    newRecord->next = list;
    return newRecord;
}

// Funzione per scrivere la lista su un file
void writeRecordsToFile(TemperatureRecord* list, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("Errore nell'apertura del file");
        return;
    }

    while (list != NULL) {
        fprintf(file, "%s %c\n", list->name, list->code);
        TemperatureRecord* temp = list;
        list = list->next;
        free(temp); // Libera la memoria dell'elemento corrente
    }

    fclose(file);
}
//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	char *filename = "temperature.txt"; // Nome del file di input
	char name[20];
    int temperature;
    FILE *file = fopen(filename, "r");
	TemperatureRecord *list = NULL; // Inizialmente la lista è vuota
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	if (file == NULL) {
    	printf("Errore nell'apertura del file");
    }
    else{
   		while (fscanf(file, "%s %d", name, &temperature) == 2) {
        TemperatureRecord* newRecord = createRecord(name, temperature);
        
        if (newRecord != NULL) {
            list = insertRecord(list, newRecord);
        }
        
        fclose(file);

    	// Scrivi la lista su un file e libera la memoria
   		writeRecordsToFile(list, "output.txt");
		}
    }

    

	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

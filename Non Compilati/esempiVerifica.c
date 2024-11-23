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

//-------------------------/

//---------/*	Define:
//----------------------------------/

//---------/*	Struct:
//----------------------------------/

//---------/*	Funzioni:
//----------------------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	FILE *file;
    char data[50];
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	// Apriamo il file in modalità lettura e scrittura
    file = fopen("test.txt", "w+");

    if (file == NULL) {
        printf("Impossibile aprire il file.\n");
        return 1;
    }

    // Utilizziamo fwrite per scrivere dei dati nel file
    fwrite("Ciao, mondo!", sizeof(char), 12, file);

    // Utilizziamo fseek per spostarci all'inizio del file
    fseek(file, 0, SEEK_SET);

    // Utilizziamo fread per leggere i dati dal file
    fread(data, sizeof(char), 12, file);

    // Stampiamo i dati letti
    printf("%s\n", data);

    // Utilizziamo rewind per tornare all'inizio del file
    rewind(file);

    // Leggiamo di nuovo i dati
    fread(data, sizeof(char), 12, file);

    // Stampiamo i dati letti
    printf("%s\n", data);

    // Chiudiamo il file
    fclose(file);
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

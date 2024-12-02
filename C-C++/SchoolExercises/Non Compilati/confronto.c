/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/

/*---------/ Testo:
Siano dati due file contenenti testo. Si realizzi un programma che individui e scriva un terzo file "risultati.txt" le parole che compaiono in entrambi i file.
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
#define LUNG 100
#define LUNGPAROLE 1000
//----------------------------------/

//---------/ Funzioni:
FILE *open_file (FILE *fd, char *namefile, char *mode){
	fd=fopen(namefile, mode);
    if (fd==NULL) { 					    
        printf("ERRORE: Apertura file invalida\n");
        exit(-1); 							
    }
	return fd;
}

void close_file(FILE *fd){
	if(fclose(fd)!=0) {             
        printf("ERRORE: Chiusura file invalida\n");	
        exit(-2); 								   
    }
    return;
}

int controlla(const char parola[LUNG], const char parolecomuni[LUNGPAROLE][LUNG], int contaparole) {
    for (int i = 0; i < contaparole; i++) {
        if (strcmp(parola, parolecomuni[i]) == 0) {
            return 1;
        }
    }
    return 0;
}
//----------------------/

//----/* Int Main:
int main() {
	//---------/ Variabili:
    FILE *file0, *file1, *output;
    char parola0[LUNG],parola1[LUNG],parolecomuni[LUNGPAROLE][LUNG];
    int contaparole = 0;
	//----------------------/
    //---------/ Algoritmo Risolutivo:
	open_file(file0,"file0.txt", "r");
	open_file(file1,"file1.txt", "r");
	open_file(output,"output.txt", "w");

    if (file0 == NULL || file1 == NULL || output == NULL) {
        printf("Errore nell'apertura dei file");
        exit(1);
    }

    
    while (fscanf(file0, "%s", parola0) != EOF) {
        fclose(file1);
        file1 = fopen("file1.txt", "r");

        while (fscanf(file1, "%s", parola1) != EOF) {
            if (strcmp(parola0, parola1) == 0 && !controlla(parola0, parolecomuni, contaparole)) {
                strcpy(parolecomuni[contaparole], parola0);
                contaparole++;
                break;
            }
        }
    }

    for (int i = 0; i < contaparole; i++) {
        fprintf(output, "%s\n", parolecomuni[i]);
    }

    printf("Parole comuni scritte in risultati.txt\n");

    close_file(file0);
	close_file(file1);
	close_file(output);
	//---------------------------------/

    return 0;
}

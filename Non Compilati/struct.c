#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include "TheLib-J.h"

#define MAXSTUD 40 - 1

typedef struct stud {
    char nome[40];
    unsigned int matricola;
    unsigned int voto;
} studente;

void popolaArray(studente stud[], int num) {
    int i;
    for (i = 0; i < num; i++) {
        printf("Inserire il tuo nome: ");
        scanf("%s", stud[i].nome);
        printf("Inserire la matricola: ");
        scanf("%u", &stud[i].matricola);
        printf("Inserire il tuo voto: ");
        scanf("%u", &stud[i].voto);
    }
    return;
}

void stampa(studente stud[], int num) {
    int i;
    for (i = 0; i < num; i++) {
        printf("\nNome: %s\nMatricola: %d\nVoto: %d\n", stud[i].nome, stud[i].matricola, stud[i].voto);
    }
    return;
}

void insufficenti(studente stud[], int num, int *insufficienti) {
    int i;
    for (i = 0; i < num; i++) {
        if (stud[i].voto < 6)
            (*insufficienti)++;
    }
    return;
}

int main() {
    studente stud[MAXSTUD];
    int num, numInsufficenti = 0;
    printf("Inserire il numero degli studenti/e: ");
    num = leggi_compreso(1, MAXSTUD);

    popolaArray(stud, num);
    stampa(stud, num);
    insufficenti(stud, num, &numInsufficenti);

    printf("Numero di studenti insufficenti: %d\n", numInsufficenti);

    printf("\n");
    system("PAUSE");
    return 0;
}

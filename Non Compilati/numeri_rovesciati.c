/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
6 - Rovescia numeri

Scrivete tre programmi che leggano una sequenza di interi e la stampino al contrario, allocando la memoria necessaria in modo dinamico attraverso 
l’uso della funzione malloc.

    L’input è dato da un intero n e da una sequenza di n numeri; basta una sola chiamata di malloc per allocare un vettore di dimensione n.
    
    L’input è dato da una sequenza di numeri terminata da 0; non potendo prevedere quanti numeri verranno inseriti, il vettore andrà 
	ridimensionato man mano: partite da una dimensione fissata piccola (es: 2) e raddoppiate la lunghezza del vettore ogni volta che questo si riempie.
	
    L’input è dato da una sequenza di numeri terminata da 0, come nel caso precedente; di nuovo, il vettore andrà ridimensionato 
	man mano: partite da una dimensione fissata (es: 15) e allungate il vettore di una lunghezza fissa (es: 10) ogni volta che questo si riempie.
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>

//-------------------------/

//---------/*	Define:

//----------------------------------/

//---------/ Funzioni:
void es1(){
	int *array;
    int lunghezza, i;

    printf("Inserisci la lunghezza massima dell'array: ");
    scanf("%d", &lunghezza);

    array=malloc(lunghezza);

    for(i=0; i<lunghezza; i++) {
        printf("Posizione %d dell'array: ", i+1);
        scanf("%d", &array[i]);
    }
    
    printf("Array: ");
    for (i=0; i<lunghezza; i++) {
        printf("%d ", array[i]);
    }

    free(array);
    
    return; 
}

void es2() {
    int *array, lunghezza=2, i=0, j;

    array=(int *)malloc(lunghezza * sizeof(int));

    do {
        if (i==lunghezza) {
            lunghezza*=2;
            array=(int *)realloc(array, lunghezza * sizeof(int));
        }

        printf("%d) Inserire: ", i+1);
        scanf("%d", &array[i]);

        i++;
    }while(array[i-1]!=0);

    printf("Array: ");
    for (j=0; j<i; j++) {
        printf("%d ", array[j]);
    }

    free(array);

    return;
}

void es3() {
    int *array, lunghezza=15, i=0, j;

    array=(int *)malloc(lunghezza * sizeof(int));

    do {
        if (i==lunghezza) {
            lunghezza+=10;
            array=(int *)realloc(array, lunghezza * sizeof(int));
        }

        printf("%d) Inserire: ", i+1);
        scanf("%d", &array[i]);

        i++;
    }while(array[i-1]!=0);

    printf("Array: ");
    for (j=0; j<i; j++) {
        printf("%d ", array[j]);
    }

    free(array);

}

//----------------------/

//----/* Int Main:
int main() {
	printf("Es 1: \n");
    es1();
    
    system("CLS");
    
    printf("Es 2: \n");
    es2();
    
    
    printf("\nEs 3: \n");
    es3();

	printf("\n");
	system("PAUSE");
	return 0;
}

/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili

	//algoritmo risolutivo
    int N; // il numero totale di animali
    scanf("%d", &N);
    int max_size = -1; // la dimensione massima degli animali che sono rimasti
    int num_animals = 0; // il numero di animali che sono rimasti
    for (int i = 0; i < N; i++) {
        int size; // la dimensione dell'animale corrente
        scanf("%d", &size);
        if (size > max_size) { // se l'animale è più grande di tutti quelli rimasti, resta al fiume
            max_size = size;
            num_animals++;
        }
    }
    printf("%d\n", num_animals); // stampa il numero di animali rimasti al fiume
    
	printf("\n");
	system("PAUSE");
	return 0;
}

/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
Scrivere una funzione c che prende in ingresso tre array A1, A2, A3. La funzione, per ogni i calcola la somma tra A1[i] e A2[i] e salva il 
risultato in A3[i]. Scrivere un main che inizializzi i due vettori A1 e A2, invochi la funzione di somma ed infine stampi il contenuto di A3[]. 
Solo nella funzione utilizzare il passaggio di parametri per indirizzo ed utilizzare l’aritmetica dei puntatori.
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>

//-------------------------/

//---------/*	Define:
#define MAX 3
//----------------------------------/

//---------/*	Struct:
//----------------------------------/

//---------/*	Funzioni:
int input(int *A){
	int i=0, flag=0;
	while(!flag){
    	printf("Inserisci: ");
    	scanf("%d", A+i);
    	
    	if(*(A+i)==-1){
    		printf("Ciclo interrotto");
    		flag=1;
    		//A=(int *)realloc(A, i + sizeof(int) - 1);
		}
		else{
			//A=(int *)realloc(A, i + sizeof(int) - 1);
    		i++;
		}
	}
	return i;
}

void somma(int *A1, int *A2, int *A3, int lung){
	int i;
	//A3=(int *)realloc(A3, lung + sizeof(int));
	
	for(i=0; i<=lung; i++){
    	*(A3+i)=*(A1+i)+*(A2+i);
	}
	return;
}

void stampa(int *A, int lung){
	int i;
	for(i=0; i<=lung; i++){
		printf("%d\t", *(A+i));
	}
	return;
}
//----------------------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	int *A1 = (int *)calloc(1, sizeof(int)); 
	int *A2 = (int *)calloc(1, sizeof(int));
	int *A3 = (int *)malloc(sizeof(int));
	int lung0, lung1;
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	if (A1 == NULL || A2 == NULL || A3 == NULL) {
        printf("Errore nell'allocazione di memoria.");
        exit(1);
    }
    
    printf("A1 ");
    lung0=input(A1);
    printf("\nA2 ");
    lung1=input(A2);
    
    if(lung0<lung1){
    	lung0=lung1;
	}
	printf("\nA3: \n");
	somma(A1, A2, A3, lung1);
	stampa(A3, lung1);
	
	
	
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

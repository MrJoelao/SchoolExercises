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


//-------------------------/

//---------/*	Define:
#define maxArr 50
#define maxNum 50
#define minNum 0
//----------------------------------/

//---------/ Funzioni:
int leggi_compreso(int min, int max){
    int valore;
    if(min<max){
    	do{
        	scanf("%d",&valore);
        	if(valore<min || valore>max){
           		printf("ERRORE: Valore inserito non valido!, inserisci un valore compreso tra %d e %d: ",min,max);
        	}
    	}while(valore<min || valore>max);	
    	return valore;
    }
    else{
    	printf("ERRORE: Valori di intervallo non validi!, inserisci i numeri in ordine crescente");
    	return -1;
	}
}

int ricercaVal(int array[], int lunghezza, int valore) {
    int i; 
    for (i=0; i<lunghezza; i++) { 
        if (array[i]==valore) { 
            return 0;
        }
    }
    return 1;
}

void casArrUnici(int array[], int n, int minimo, int massimo){
	int i,j;
	
	for(i=0; i<=n; i++){
		array[i]=(rand()%(massimo-minimo+1))+minimo;
		for(j=0; j<=i; j++){
			if(!ricercaVal(array, i, array[i]) && j>0){
				i--;
			}
		}
	}
}

void stampaArr(int arr[], int dimensione, int direzione) {
	int i; 
	printf("Array: ");
	if(direzione<2){
		for (i=0; i<=dimensione; i++){
        printf("%d ", arr[i]);
    	}
    	printf("\n");}
	else{
		for (i=dimensione; i>=0; i--) {
        printf("%d ", arr[i]);
    	}
    	printf("\n");}
	}
	
void minMax(int numeri[], int lunghezza, int *minore, int *maggiore) {
    int i;
	*maggiore=numeri[0],*minore=numeri[0]; 

    for (i=1; i<lunghezza; i++) {	
        if (numeri[i]>*maggiore) {	
            *maggiore=numeri[i]; 	
        }
        if (numeri[i]<*minore) {	
            *minore=numeri[i];
        }
    }
}

void swap (int* a, int* b) {
    int temp = *a; 
    *a = *b;
    *b = temp;	
}

void ordinamento(int array[], int lunghezza) { //selection sort
    int i, j, indice_minimo;

    for (i=0; i<lunghezza-1; i++) {	

        indice_minimo=i;
        for (j=i+1; j<lunghezza; j++) {
            if (array[j]<array[indice_minimo]) {
                indice_minimo=j;
            }
        }

        swap(&array[indice_minimo], &array[i]);	
    }
}



//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	int arrayUnico[maxArr], n, direzione,minimo,massimo;
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	printf("Scegliere la grandezza del vettore: ");
	n=leggi_compreso(1,maxArr);
	
	srand(time(0));
	casArrUnici(arrayUnico, n, minNum, maxNum);
	
	system("CLS");
	
	minMax(arrayUnico,n,&minimo,&massimo);
	
	printf("Il vettore e' stato generato!\n-Max: %d\n-Min: %d\n",minimo,massimo);
	stampaArr(arrayUnico, n, 1);
	
	printf("\nL'array e' stato ordinato!\n\nScegliere in che verso stamparlo:\n 1.Da sinistra verso destra.\n 2.Da destra verso sinistra.\nScelta: ",minimo,massimo);
	ordinamento(arrayUnico,n);
	stampaArr(arrayUnico, n, leggi_compreso(1,2));
	
	
	
	
	/*printf("\n");
	stampaArr(arrayUnico, n, 2);*/
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

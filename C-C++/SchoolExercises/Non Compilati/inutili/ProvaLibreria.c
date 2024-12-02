/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"
int main(){
	//dichiarazione variabili
	int scelta,num0,num1,num2,ris;
	//algoritmo risolutivo
	printf("1. Funzione che verifica che un valore un input sia nel intervello scelto.\n2. Funzione che legge in input un valore maggiore di x.\n3. Funzione che legge in input un valore minore di x.\n4. Funzione che legge in input un valore diverso di un valore scelto.\n5. Funzione per il valore minimo (2 numeri).\n6. Funzione per il valore massimo (2 numeri).\n7. Funzione per il valore minimo (3 numeri).\n8. Funzione per il valore massimo (3 numeri).\n9. Funzione che verifica se un numero e' primo.\n10. Funzione che calcola la potenza di un numero.\n11. MCM, Funzione che calcola il minimo comune multiplo di due numeri a e b.\n12. MCD, Funzione che calcola il massimo comune divisore di due numeri a e b\nInserire un numero:");
		scanf("%d",&scelta);
	switch(scelta){
		case 1:
			system("CLS");
			printf("Questa funzione della libreria serve per ricevere in input un valore che deve essere compreso in un intervallo di numeri scelti dal utente.\nIl valore deve essere compreso tra: ");
				scanf("%d",&num0);
			printf("e: ");
				scanf("%d",&num1);
			printf("Inserire il valore: ");
			printf("Il valore da te inserito e': %d",leggi_compreso(num0,num1));
			break;
	
		case 2:
			system("CLS");
			printf("Questa funzione della libreria serve per ricevere in input un valore che deve maggiore di un numero scelto dal utente.\nIl valore deve essere maggiore di: ");
				scanf("%d",&num0);
			printf("Inserire il valore: ");
			printf("Il valore da te inserito e': %d",leggi_maggiore(num0));
			break;
			
		case 3:
			system("CLS");
			printf("Questa funzione della libreria serve per ricevere in input un valore che deve minore di un numero scelto dal utente.\nIl valore deve essere maggiore di: ");
				scanf("%d",&num0);
			printf("Inserire il valore: ");
			printf("Il valore da te inserito e': %d",leggi_minore(num0));
			break;
			
		case 4:
			system("CLS");
			printf("Questa funzione della libreria serve per ricevere in input un valore che deve diverso di un numero scelto dal utente.\nIl valore deve essere diverso di: ");
				scanf("%d",&num0);
			printf("Inserire il valore: ");
			printf("Il valore da te inserito e': %d",leggi_diverso(num0));
			break;
			
		case 5:
			system("CLS");
			printf("Questa funzione della libreria serve per ricevere in input 2 valori e determinare tra i due il minore.\nN1:");
				scanf("%d",&num0);
			printf("N2:");
				scanf("%d",&num1);
			printf("Il valore da te inserito e': %d",valmin_2(num0,num1));
			break;
			
		case 6:
			system("CLS");
			printf("Questa funzione della libreria serve per ricevere in input 2 valori e determinare tra i due il maggiore.\nN1:");
				scanf("%d",&num0);
			printf("N2:");
				scanf("%d",&num1);
			printf("Il valore da te inserito e': %d",valmax_2(num0,num1));
			break;
			
		case 7:
			system("CLS");
			printf("Questa funzione della libreria serve per ricevere in input 3 valori e determinare tra i due il minore.\nN1:");
				scanf("%d",&num0);
			printf("N2:");
				scanf("%d",&num1);
			printf("N3:");
				scanf("%d",&num2);
			printf("Il valore da te inserito e': %d",valmin_3(num0,num1,num2));
			break;
			
		case 8:
			system("CLS");
			printf("Questa funzione della libreria serve per ricevere in input 3 valori e determinare tra i due il maggiore.\nN1:");
				scanf("%d",&num0);
			printf("N2:");
				scanf("%d",&num1);
			printf("N3:");
				scanf("%d",&num2);
			printf("Il valore da te inserito e': %d",valmax_3(num0,num1,num2));
			break;
			
		case 9:
			system("CLS");
			printf("Questa funzione della libreria serve per ricevere in input un valori e determinare se e' primo restituendo 0, in caso contrario restituisce 1 se il numero inserito non e' primo.\nInserire:");
				scanf("%d",&num0);
			printf("%d",num_primo(num0));
			break;

		case 10:
			system("CLS");
			printf("Questa funzione della libreria serve per calcolare la potenza di un numero inserendo esponente.\nInserire num:");
				scanf("%d",&num0);
			printf("Inserire esponente:");
				scanf("%d",&num1);
			printf("%d",calc_pot(num0,num1));
			break;
			
		case 11:
			system("CLS");
			printf("Questa funzione della libreria serve per calcolare MCM.\nInserire il primo numero:");
				scanf("%d",&num0);
			printf("Inserire il secondo numero:");
				scanf("%d",&num1);
			printf("%d",calc_mcm(num0,num1));
			break;
			
		case 12:
			system("CLS");
			printf("Questa funzione della libreria serve per calcolare MCD.\nInserire il primo numero:");
				scanf("%d",&num0);
			printf("Inserire il secondo numero:");
				scanf("%d",&num1);
			printf("%d",calc_mcd(num0,num1));
			break;
			
	}
	
	printf("\n");
	system("PAUSE");
	return 0;
}

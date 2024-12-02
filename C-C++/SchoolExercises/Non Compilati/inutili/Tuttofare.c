#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *fd; //dichiarazione di un file
	Dato variabile; //dichiarazione dell nuovo tipo di dato "Dato" 
	
	//System Clear:
	system ("cls");

	//struct
	typedef struct datp{
		char stringa;
		float numeroFloat;
		int numeroIntero;
		double numeroDouble;
	}Dato;
	
	printf("%s: %.2f %.2f",anno[i].mese,anno[i].TMax,anno[i].TMin); //per stampa
	fd=open_file(fd,"tempMesi.txt","r"); //aprire un file con la mia funzione, r=read w=write 
	close_file(fd); //chiusura di un file con funzione
	
	int variabile_riferimento;

	switch(variabile_riferimento){
		case 1:
			printf("prova");
				break;
		case 2:
				break;
		case 3:
				break;
		default:
			printf("errore");
				break;
	}              
	
	printf("\n");
	system("PAUSE");
	return 0;
}

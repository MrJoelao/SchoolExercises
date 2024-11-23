/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	int mese;

	//algoritmo risolutivo
	printf("Scrivi il mese\n");
	scanf("%d",&mese);
	switch(mese){
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		printf("Sei nel secondo pentamestre");
		break;
	case 7:
	case 8:
		printf("Sei in vacanza");
	case 9:
	case 10:
	case 11:
	case 12:
		printf("Sei nel primo quadrimestre");
		break;
	default:
		printf("numero inserito non valido");
	}
		

	printf("\n");
	system("PAUSE");
	return 0;
}

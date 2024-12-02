/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"
#define max_vett 50

int main(){
	//dichiarazione variabili
	char stringa[max_vett], stringa2[max_vett]="mamma", car1='a', car2=65; //A: 65 || a:97
	int i;
	//algoritmo risolutivo
	printf("Inserisci stringa: \a");
	scanf("%s",&stringa);
	
	printf("|Versione 1:");
	printf("%s",stringa);
	
	printf("| |Versione 2:");
	for(i=0; i<max_vett; i++){
		printf("%c",stringa[i]);
	}
	printf("| |Versione 3: ");
	for(i=0; i<max_vett && stringa[i]!='\0'; i++){
		printf("%c",stringa[i]);
	}
	printf("|");
	
	printf("\n");
	system("PAUSE");
	return 0;
}

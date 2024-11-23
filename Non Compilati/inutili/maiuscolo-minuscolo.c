/*
Autore: Joel Stephan
Data: 27/03/23
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib-J.h"
#define max_vett 5000

int main(){
	//dichiarazione variabili
	char stringa[max_vett];
	int i,lunghezza=0;
	//algoritmo risolutivo
	printf("Inserire una stringa: ");
	gets(stringa);
	
	for(i=0; i<max_vett && stringa[i]!='\0'; i++){
		
		if(stringa[i]>=65  && stringa[i]<=90){
			stringa[i]+=32;
		}
		else if(stringa[i]>=97 && stringa[i]<=122){
			stringa[i]-=32;
		}
		else{
			lunghezza++;
		}

		
	}
	
	printf("%s",stringa);
	printf("\nLunghezza stringa: %d",i-lunghezza);
	
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

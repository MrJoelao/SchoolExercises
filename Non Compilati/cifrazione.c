/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib-J.h"
#define max_array 1000
#define max 10
#define min 1

int main(){
	//dichiarazione variabili
	char stringa[max_array];
	int chiave;
	//algoritmo risolutivo
	printf("Inserire la chiave: ");
	chiave=leggi_compreso(min,max);
	
	printf("Chiave accettata! \nOpzioni:\n1.Decriptare[0m, bisognera' inserire una messaggio precedentemente criptato e grazie alla chiave verra' decriptato");
	printf("\n2.\x1bESC[1mCriptare\x1bESC[0m, bisognera' inserire una messaggio e grazie alla chiave verra' criptato");
	
	if(leggi_compreso(min,max)){
		
		printf("decriptare");
	}
	else{
		printf("criptare");
	}
	
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

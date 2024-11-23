/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
	Scrivere un programma per la cifratura e decifratura con parola chiave di stringhe minuscole lunghe al più 50 caratteri.  
	Per ogni carattere c della stringa, si considera il carattere k di eguale posizione (modulo la lunghezza della parola chiave) nella parola chiave, e si fa shiftare c di un numero di caratteri equivalente alla posizione nell’alfabeto del carattere k. Il risultato deve essere una stringa di caratteri dell’alfabeto ‘a’-‘z’. 
	Ad esempio data la stringa “ciao” e la parola chiave “no”, la corrispondente parola cifrata è “pwnc”. 
	Applicare l'algoritmo alla stringa costante  “nelmezzodelcammindinostravita” con parola chiave “dante”
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TheLib-J.h"

#define max_vett 50

int main(){
	//dichiarazione variabili
	char scelta,parola[max_vett],chiave[max_vett];
	int i;
	//algoritmo risolutivo
	printf("Benvenuto nel criptTools!, per prima cosa inserisci la frase da De/Criptare: ");
    gets(parola);
	
	printf("Inserisci la parola chiave: ");
    gets(chiave);
    
	//metto tutto in minuscolo
	minuscolo(parola);
	minuscolo(chiave);
	
	printf("scegli cosa vuoi fare:\n  1. Criptare, riesce a criptare un messaggio usando una chiave fornita dal utente.\n  2. Decriptare, riesce a Decriptare un messaggio usando una chiave fornita dal utente.\nScelta: ");
	scelta=leggi_compreso(1,2);
	
	if(scelta<2){
		criptare(parola, chiave);
		printf("Perfetto! Frase criptata: %s",parola);
	}
	else{
		decriptare(parola, chiave);
		printf("Perfetto! Frase decriptata: %s",parola);
	}
	
	printf("\n");
	system("PAUSE");
	return 0;
}
void minuscolo(char stringa[]){
	int i;
	for(i=0; i<strlen(stringa); i++){
        stringa[i]=tolower(stringa[i]);
    }
}

void criptare(char parola[], char chiave[]) {

    int lunghezza_parola,i,shift;
	lunghezza_parola=strlen(parola);
	shift=chiave[0]-'a';

    for (i=0; i<=lunghezza_parola; i++) {
		if((parola[i]+shift)>'z' && parola[i]!=' ')
			parola[i]='a'+('z'-parola[i]+shift);
        else if(parola[i]!=' ')
        	parola[i]+=shift;
    }
	/*if(parola[i]>'a'+shift && parola[i]!=' '){
		parola[i]+=shift;
	}
	else if(parola[i]!=' '){
		parola[i]-=shift;
	}*/
}
void decriptare(char parola[], char chiave[]) {
	
	int lunghezza_parola,i,shift;
	lunghezza_parola=strlen(parola);
	shift=chiave[0]-'a';

  /*  for (i=0; i<=lunghezza_parola; i++) {
		if((parola[i]+shift)>'a' && parola[i]!=' ')
			parola[i]='z'-('a'-parola[i]+shift);
        else if(parola[i]!=' ')
        	parola[i]-=shift;
    }*/
    
	if(parola[i]<'a'+shift && parola[i]!=' '){
		parola[i]-=shift;
	}
	else if(parola[i]!=' '){
		parola[i]+=shift;
	}
	
	
	
}
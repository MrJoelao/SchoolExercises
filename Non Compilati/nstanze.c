/*
Autore: Joel Stephan
Data:
Versione:
Testo:Come saprà, costruire pareti è un’operazione costosa ed i genitori di Luca hanno un budget stabilito per
effettuare i lavori.
L’obiettivo dei lavori è quindi quello di costruire al massimo N pareti, ognuna delle quali può essere
verticale od orizzontale per l’intera lunghezza della stanza (che è sempre di forma rettangolare).
Quante stanze possono essere ottenute al massimo costruendo al più N pareti?

1) Dati di input:
	La prima ed unica riga di input contiene un solo intero: N .
2) Dati di output:
	Deve scrivere una singola riga con un intero: il numero di stanze che possono essere ottenute al massimo
	mediante la costruzione di al più N pareti.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	int n,stanze,verticali,orrizontali;

	//algoritmo risolutivo
	
	printf("Inserire il numero di pareti: ");
	scanf("%d",&n);
	while(n<0){
		printf("Errore: numero inserito non valido! inserisci un numero maggiore di zero: ");
		scanf("%d",&n);
	}
	
	if(n%2==0){
		verticali=(n/2)+1;
		orrizontali=(n/2)+1;
		stanze=verticali*orrizontali;
	}
	else{
		verticali=(n-1)/2+2;
		orrizontali=(n-1)/2+1;
		stanze=verticali*orrizontali;
	}
	
	printf("%d",stanze);
	printf("\n");
	system("PAUSE");
	return 0;
}

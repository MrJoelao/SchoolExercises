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
	int n,i,volte,flag=0;

	//algoritmo risolutivo
	printf("Quanti numeri vuoi inserire?: ");
	scanf("%d",&volte);
	
	
	
	
	if(volte>1){
		
		printf("\nInserisci il numero:");
		scanf("%d",&n);
		i=n;
		
		//ciclo
		for (volte=volte-1; volte>=1; volte--){
			printf("Numeri mancanti:%d. Inserisci un valore:",volte);
			scanf("%d",&n);
			
			//verifica 
			if(i>n){
				flag=1;}
				
			else{
				i=n;}
		}
		
		//output crescente/decrescente
		if(flag==1){
			printf("\nI numeri inseriti dal utente non sono in ordine crescente");}
			
		else{
			printf("\nI numeri inseriti dal utente sono in ordine crescente");}
			
	}
	//messaggio di errore in caso di numero di volte errato
	else{printf("Valore inserito errato, inseirisci un numero maggiore di 1");}
	


	printf("\n");
	system("PAUSE");
	return 0;
}

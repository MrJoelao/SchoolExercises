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
	int num0,den0,num1,den1,i,minimo,numTot,mcm;
	
	//algoritmo risolutivo
	printf("Inserire due frazioni da sommare.\nPrima frazione:\n");
	
	printf(" Numeratore:");
	scanf("%d",&num0);
	printf(" Denominatore:");
	scanf("%d",&den0);
		while(den0<0){
			printf("Errore: denominatore inserito minore di zero. inserisci un numero maggiore di zero.\n Denominatore:");
			scanf("%d",&den0);
		}
	
	printf("Seconda frazione:\n");
	printf(" Numeratore:");
	scanf("%d",&num1);
	
	printf(" Denominatore:");
	scanf("%d",&den1);
		while(den0<0){
			printf("Errore: denominatore inserito minore di zero. inserisci un numero maggiore di zero.\n Denominatore:");
			scanf("%d",&den1);
		}
	
	if(den0<den1){
		minimo=den0;}
	else{
		minimo=den1;}
			
	for( i=1; i<=minimo; i++){
		if(den0%i==0 && den1%i==0){
				mcm=den0*den1/i;
		}
	}
	numTot=(den0/mcm*num0)+(den1/mcm*num1);
	if(numTot%mcm==0){
		printf("Il risultato della somma delle due frazioni e':%d",numTot/mcm);
	}
	else{
		printf("Il risultato della somma delle due frazioni e':%d/%d",numTot,mcm);
		/*if(numTot<mcm){
			minimo=numTot;
		}
		else{
			minimo=mcm;
		}
		
		for( i=1; i<=minimo; i++){
		if(den0%i==0 && den1%i==0){
				numTot=numTot/i;
				mcm=mcm/i;
		}*/
	}
		

	printf("\n");
	system("PAUSE");
	return 0;
}

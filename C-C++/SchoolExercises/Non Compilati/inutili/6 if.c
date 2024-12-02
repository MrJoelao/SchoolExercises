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
	printf("scrivi il numero del mese\n");
	scanf("%d",&mese);
	
	if(mese>0 && mese<=12){
		if(mese>=9 && mese<=12){
		printf("Sei nel primo trimestre");}
	
		else{
			
		if(mese>=1 && mese<=6)
		printf("Sei nel secondo pentamestre");
		else
		printf("Sei in vacanza");}
	}	
	else
	printf("Numero inserito non valido");
		

	printf("\n");
	system("PAUSE");
	return 0;
}

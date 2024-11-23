/*
Autore: Joel Stephan
Data:
Versione: 0
Testo: Verifica di informatica.
*/

#include <stdio.h>
#include <stdlib.h>

void ammessi(){
	int voto0,voto1,i;
	printf("Voto 1:");
	 scanf("%d",&voto0);
	printf("Voto 2:");
	 scanf("%d",&voto1);
	for(i=100;i>=1; i--){
		if(voto0>=i || voto1>=i){
			if(voto0>=i && voto1>=i){
				printf("2");	
			}
			else{
				printf("1");
			}
		}
		else{
			printf("0");
		}	
	}
	return;
}

int main(){
	//dichiarazione variabili
	
	//algoritmo risolutivo
	ammessi();
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

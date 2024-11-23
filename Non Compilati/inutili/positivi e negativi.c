/*
Autore: Joel Stephan
Data: 21/10/22
Versione: 0
Testo: A
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	int n, grande,i=1,quantita=0;

	//algoritmo risolutivo
	printf("Buon Natale \n\n    *    \n   ***   \n  ***** \n *******\n    *  \n    *\n\n");

	printf("Scrivi 10 numeri e ti diro' quanti sono positivi, negativi e nulli\n");
	
	scanf("%d",&n);
	grande=n;
		
	while(quantita<9){
		scanf("%d",&n);
		quantita=quantita+1;
		if(n>grande){
			i=i++;
		}
		else{
			
		}}
					
	
	if(i=0)
	printf("\nI numeri sono stati inseriti in modo crescente");
	else{
	printf("a");
	}
	
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

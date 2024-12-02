/*
Autore: Joel Stephan
Data:
Versione: 0
Testo: leggere da tastiera 10 numeri e dire quanti di essi sono negativi.
	   dopo aver stampato la quantità di numeri negativi, comunicare se c'è 
	   stato almeno un valore nullo all'interno della serie
*/

#include <stdio.h>
#include <stdlib.h>
#define max 10

int main(){
	//dichiarazione variabili
	int num[max],negativi=0,nullo=0,i;
	//algoritmo risolutivo
	printf("Inserire 10 numeri e ti comunichero' quanti numeri sono negativi, e se e' stato inserito un valore nullo: ");
	//ciclo che ri ripete per "max" (10)
	for(i=0; i<max; i++){
		scanf("%d",&num[i]);
		//se il numero 
		if(num[i]<0){
			negativi++;
		}
		if(num[i]==0)nullo=1;
	}
	
	printf("N negativi:%d",negativi);
	if(nullo==1) printf("C'e' stato un valore nullo");
	
	printf("\n");
	system("PAUSE");
	return 0;
}

/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h>

int pari ()
{
int num;
scanf("%d",&num);
if(num%2==0){
	printf("Numero pari");
}
else{
	printf("Numero dispari");
}
return 0;
}

int main(){
	//dichiarazione variabili
	int x;
	
	//algoritmo risolutivo
	printf("Dimmi un numero:");
	pari(x);

	printf("\n");
	system("PAUSE");
	return 0;
}



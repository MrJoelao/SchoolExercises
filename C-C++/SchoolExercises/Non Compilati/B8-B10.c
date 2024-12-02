/*
Autore: Joel Stephan
Data:
Versione:
Testo: Creare un programma in c che trasformi numeri in base 8 in base 10
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	//dichiarazione variabili
	int num,resto,ndec=0,i=0,base;

	//algoritmo risolutivoù
	printf("Base?:");
	scanf("%d",&base);
	printf("Inserire un numero in base %d: ",base);
	scanf("%d",&num);
	
	do{
		resto=num%10;
		if(resto>=base){
			printf("Errore in input");
			ndec=-1;
			break;
		}
		
		ndec=ndec+resto*pow(base,i);
		i++;
		num=num/10;
		
	}while(num!=0);
	
	printf("il numero in base 10 e':%d",ndec);
	printf("\n");
	system("PAUSE");
	return 0;
}

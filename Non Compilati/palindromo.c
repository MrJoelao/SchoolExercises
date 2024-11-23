/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#define vMax 10000
int main(){
	//dichiarazione variabili
	int nNum,num[vMax],j,i,conta=0;
	//algoritmo risolutivo
	printf("Quanti numeri vuoi inserire?: ");
	scanf("%d",&nNum);
	for(i=1; i<=nNum; i++) {
		printf("Numero %d:",i);
		scanf("%d",&num[i]);
		
    }
	
    j=nNum;
    
	for(i=1; i<=nNum; i++) {
		if(num[i]==num[j]){
			conta++;
		}
		j--;
    }
    	
    if(conta>=nNum){
    	printf("E' palindromo");
	}
	else{
		printf("Non e' palindromo");
	}
	
	printf("\n");
	system("PAUSE");
	return 0;
}

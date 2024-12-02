/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
int dec_quadrato(int num){
	int i,j,z,q,w,e;
	for(z=1; z<=num; z++){
		for(i=1; i<=z; i++){
			for(j=1; j<=z; j++){
				printf("+");
			}
			printf("\n");
		}
		printf("\n");
	}
	for(q=num-1; q>=1; q--){
		for(w=1; w<=q; w++){
			for(e=1; e<=q; e++){
				printf("+");
			}
			printf("\n");
		}
		printf("\n");
	}
}

int main(){
	//dichiarazione variabili
	int num,i,j,z;
	scanf("%d",&num);
	//algoritmo risolutivo
	dec_quadrato(num);


	printf("\n");
	system("PAUSE");
	return 0;
}

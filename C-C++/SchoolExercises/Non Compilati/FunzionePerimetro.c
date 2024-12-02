/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>

float CalcolaPerimetro(int base,int altezza){
	if(base>0 && altezza>0){
		return (base*2)+(altezza*2);
	}
	else{
		printf("ERRORE: Lati/o non validi/o\n");
		return -1;
	}
}

int main(){
	//dichiarazione variabili
	float base,altezza;
	//algoritmo risolutivo
	printf("Inserire la base (cm):");
	 scanf("%f",&base);
	printf("Inserire l'altezza (cm):");
	 scanf("%f",&altezza);
	
	printf("Perimetro: %.2f cm",CalcolaPerimetro(base,altezza));
	
	printf("\n");
	system("PAUSE");
	return 0;
}

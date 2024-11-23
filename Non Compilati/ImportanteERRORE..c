/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>

float leggi_maggiore(float min){
    float valore;
    do{
        scanf("%f",&valore);
        if(valore<min){
            printf("ERRORE: Valore inserito non valido!, reinserire: ");
        }
    }while(valore<min);
    return valore;
}

int main(){
	//dichiarazione variabili
	float c;
	const float zeroAssoluto=-273.15;
	//algoritmo risolutivo
	
	c=leggi_maggiore(zeroAssoluto);
	printf("K=%f\nF=%f",c+273.15,(9/5)*c+32);
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

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
	float num,sconto;

	//algoritmo risolutivo
	printf("scrivi il prezzo e ti calcolero' lo sconto\n");
	scanf("%f",&num);
	
	if(num>0){
		if(num<30){
		sconto=num-num/100*12;
		printf("dato che il numero inserito e' minore di 30 lo sconto applicato e' del 12 per cento.\nPrezzo scontato: %.2f",sconto);}
		else{
		sconto=num-num/100*25;
		printf("dato che il numero inserito e' maggiore di 30 lo sconto applicato e' del 25 per cento.\nPrezzo scontato: %.2f",sconto);}}
	else
	printf("il numero inserito deve essere positivo");

	printf("\n");
	system("PAUSE");
	return 0;
}

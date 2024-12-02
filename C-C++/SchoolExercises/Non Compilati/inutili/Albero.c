/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h>





int main() {

	//dichiarazione variabili
	int i, bianchi, asterischi, corteccia, altezza, fusto,ast_u_linea;
	bianchi=0;
	asterischi=0;
	corteccia=0;
	

	//algoritmo risolutivo
	printf("Buon natale e felice anno nuovo:\n\n");
	scanf("%d", &altezza);
	printf("Inserisci l'altezza della fusto dell'albero di natale:");
	scanf("%d", &fusto);
	printf("\n");

for(i=0;i<altezza;i++){
	while(bianchi<(altezza-i)){
		printf(" ");
		bianchi++;}
		
	while(asterischi<i*2+1){
		printf("*");
		asterischi++;
		ast_u_linea=asterischi;}

	printf("\n");
	
	bianchi=0;
	asterischi=0;
}
while(corteccia<fusto)
{
for(i=1;i<(ast_u_linea+1)/2;i++)//centro il fusto
printf(" ");
printf("***");
printf("\n");
corteccia++;
}
system("PAUSE");
}

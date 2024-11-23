/*
Autore: Joel Stephan
Data: 02/10/22
Versione: 0
Testo: 
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	//dichiarazione variabili
	int A,B,C;

	//algoritmo risolutivo
	printf("Dimmi la lunghezza A\n");
	scanf("%d",&A);
	
	printf("Dimmi la lunghezza B\n");
	scanf("%d",&B);
	
	printf("Dimmi la lunghezza C\n");
	scanf("%d",&C);
	
	if(A>0 && B>0 && C>0 && A<C+B && B<A+C && C<A+B){

		//Trinagolo rettangolo
		if(pow(A,2)==(pow(B,2)+pow(C,2)) || pow(B,2)==(pow(A,2)+pow(C,2)) || pow(C,2)==(pow(B,2)+pow(A,2))) 
			printf("E' un rettangolo rettangolo");
		
		//Trinagolo equilatero	
		if(A==B && A==C)
			printf("E' un triangolo equilatero");
		else
		
			//Trinagolo isoscele
			if(A==B && C!=A || B==C && A!=B || C==A && B!=A)
				printf("E' un triangolo iscoscele");
			else
			
				//Trinagolo scaleno
				printf("E' un triangolo scaleno");
	}
	else
	printf("Dati inseriti non validi");


	printf("\n");
	system("PAUSE");
	return 0;
}

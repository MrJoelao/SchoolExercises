/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	//dichiarazione variabili
	int risposta;
	float b,h,l,r,area;

	//algoritmo risolutivo
	printf("Per quale figura vuoi calcolarne area?\n1.Triangolo\n2.Quadrato\n3.Rettangolo\n4.Cerchio\n");
	scanf("%d",&risposta);
	
	switch(risposta){
		case 1:
			printf("Triangolo? bene, dimmi la sua altezza:\n");
			scanf("%f",&h);
			printf("dimmi la sua base:\n");
			scanf("%f",&b);
			
			if(b>0 && h>0){
			area=b*h/2;	
			printf("Area e': %f",area);}
			
			else{
			printf("Errore: altezza e la base devono essere maggiori di zero");}
		break;
		
		case 2:
			printf("Quadrato? bene, dimmmi la lunghezza di un suo lato:\n");
			scanf("%f",&l);
			
			if(l>0){
			area=pow(l,2);
			printf("Area e': %f",area);}
			
			else{
			printf("Errore: il lato deve essere maggiore di zero");}
		break;
		
		case 3:
			printf("Rettangolo? bene, dimmi la sua altezza:\n");
			scanf("%f",&h);
			printf("dimmi la sua base:\n");
			scanf("%f",&b);
			
			if(b>0 && h>0){
			area=b*h;
			printf("Area e': %f",area);}
			
			else{
			printf("Errore: altezza e la base devono essere maggiori di zero");}
		break;
		
		case 4:
			printf("Cerchio? bene, dimmi il suo raggio:\n");
			scanf("%f",&r);
			
			if(r>0){
			area=M_PI*pow(r,2);
			printf("Area e': %f",area);}
			else{
			printf("Errore: il raggio deve essere maggiore di zero");}
		break;
		
		default:
			printf("Scelta non valida, scegliere tra 1-4");
		break;
	}
	printf("\n");
	system("PAUSE");
	return 0;
}

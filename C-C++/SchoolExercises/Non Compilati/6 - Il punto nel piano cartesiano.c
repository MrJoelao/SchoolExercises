/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
6 - Il punto nel piano cartesiano

Data una struct che rappresenta un punto nel piano cartesiano a due dimensioni: 

struct point { double x; double y; }; 

ed il relativo tipo typedef struct point Point;  scrivere le seguenti funzioni che operano su oggetti di tipo Point : 

    double DistanzaDaOrigine (Point p);
    double Distanza (Point p1, Point p2);
    int Quadrante (Point p); in quale quadrante
    int Allineati(Point p1, Point p2, Point p3); se sono allineati 
    int Insterseca(Point p1, Point p2); se il segmento che ha per estremi p1 e p2 interseca un qualunque asse
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>
	#include   "TheLib-J.h"

//-------------------------/

//---------/*	Define:
	#define max 2
//----------------------------------/

typedef struct point { 
	float x; 
	float y; 
	}Point; 

//---------/ Funzioni:

void input(Point *p){
	scanf("%f",&p->x);
	printf(" Y: ");
	scanf("%f",&p->y);
	return;
}

float DistanzaDaOrigine (Point *p){
	return sqrt(pow(p->x,2)+pow(p->y,2));
}
float Distanza (Point *p1, Point *p2){
	return sqrt(pow((p2->x-p1->x),2)+pow((p2->y-p1->y),2));
}
int quadrante(Point *p){
	int ris=0;
	if(p->x<0){
		if(p->y<0){
			ris=3;
		}
		else{
			ris=1;			
		}
	}
	else{
		if(p->y<0){
		ris=4;		
		}
		else{
			ris=2;	
		}
	}
	return ris;
}

//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	Point punti[max];
	int i;
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	
	
	
	for(i=0; i<max; i++){
		printf("Inserire i dati per il punto %d:\n X: ",i+1);
		input(&punti[i]);
		system("cls");
	}
	
	printf("Punto 1: X: %.2f, Y: %.2f\nPunto 2: X: %.2f, Y: %.2f\n\n",punti[0].x,punti[0].y,punti[1].x,punti[1].y);
	printf("-Distanza dall'origine: 1: %.2f, 2: %.2f\n",DistanzaDaOrigine(&punti[0]),DistanzaDaOrigine(&punti[1]));
	printf("-Distanza tra i due punti: %.2f\n",Distanza(&punti[0],&punti[1]));
	printf("Quadrante punto 1: %d, punto 2: %d",quadrante(&punti[0]),quadrante(&punti[1]));
	
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

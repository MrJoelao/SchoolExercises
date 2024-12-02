/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



int e_pot(int a, int b){
	int i, risPot=1;
	if(b>0){
		for(i=1; i<=b; i++){
			risPot=a*risPot;
		}
		printf("%d^%d=%d",a,b,risPot);
	}
	else{
		printf("ERRORE IN INPUT:Inserire un esponente maggiore di zero\n");
		risPot=-1;
	}
	return risPot;
}
int v2_min(int a,int b){
	if(a<b){
		printf("Il valore minimo inserito e': %d",a);
		return a;
		}
	else{
		if(a==b){
			printf("ERRORE IN INPUT:Inserire due valori diversi tra di loro\n");}	
		else{
			printf("Il valore minimo inserito e': %d",b);
			return b;
			}
	}
	
}
int v3_min(int a,int b,int c){
	if(a<b && a<c){
		printf("Il valore minimo inserito e': %d",a);
		return a;
		}	
	else{
			if(b<a && b<c){
				printf("Il valore minimo inserito e': %d",b);
				return b;
				}
			else{
				
			if(a==b && a==c){
				printf("ERRORE IN INPUT:Inserire tre valori diversi tra di loro\n");}	
			else{
				printf("Il valore minimo inserito e': %d",c);
				return c;
				}
			}
		}
}

float distanza(int x1, int y1, int x2, int y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int se_per(int m1, int m2){
	if (m1 * m2 == -1) {
		return 1;
		} 
		else {
		return 0;
		}
}


int main(){
	//dichiarazione variabili
	int  num0,num1,num2,esponente,scelta;
	//algoritmo risolutivo
	printf("1. Potenza tra a e b\n2. Valore minimo tra due numeri\n3. Valore minimo tra tre numeri\n4. Distanza tra due punti in un piano cartesiano\n5. Verifica retta perpendicolare\nScegliere tra le 5: ");
	scanf("%d",&scelta);
	
	switch(scelta){
		case 1:
			system("cls");
			printf("Inserisci un numero: ");
				scanf("%d",&num0);
			printf("Inserisci un esponente: ");
				scanf("%d",&esponente);
				
			e_pot(num0,esponente);
		break;
		
		case 2:
			system("cls");
			printf("Inserisci 2 numeri: ");
				scanf("%d",&num0, &num1);
				
			v2_min(num0,num1);
		break;
		
		case 3:
			system("cls");
			printf("Inserisci tre numeri: ");
				scanf("%d %d %d", &num0, &num1, &num2);
					
			v3_min(num0,num1,num2);
		break;
	
		case 4:
			system("cls");
  			printf("Inserisci le coordinate del punto A (x1, y1): ");
  				scanf("%lf%lf", &num0, &num1);

  		
  			printf("La distanza del punto A dal punto B (5, 3) e': %f\n",distanza(num0, num1, 5, 3));
  		
		break;
		
		case 5:
			system("cls");
			printf("Inserisci il coefficiente angolare della prima retta: ");
				scanf("%f", &num0);
			printf("Inserisci il coefficiente angolare della seconda retta: ");
				scanf("%f", &num1);
				
			printf("Risultato: %d",se_per(num0,num1));
		break;
		
		default:
			printf("ERRORE IN INPUT:Inserire un valore compreso tra 1 e 5\n");
		break;
	}
	
	
	printf("\n");
	system("PAUSE");
	return 0;
}

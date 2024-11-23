#include<stdio.h>

float media (int, int);
/* dati 2 valori ne calcola la media
   IN: n1, n2
   OUT: media
*/

int main(){
int a, b; 
float ris;
printf("inserisci un numero: "); 
scanf("%d", &a); 
printf("inserisci il secondo numero: ");
scanf("%d", &b); 
ris = media(a,b); 
printf("la media e' : %.2f", ris); 
return 0;
}

// funzioni

float media (int n1, int n2){
	return  (n1+n2)/2;
}

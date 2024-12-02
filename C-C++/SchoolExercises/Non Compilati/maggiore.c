#include<stdio.h>

int maggiore (int, int);
/* legge due numeri da tastiera e determina qual'è il maggiore
   IN: n1, n2
   OUT: 1 se n1 / 2 se n2 / 0 se sono uguali
*/

int main(){
int a, b, magg;
printf("inserisci il primo numero: ");
scanf("%d", &a); 
printf("inserisci il secondo numero: ");
scanf("%d", &b); 
magg = maggiore(a, b);
if (magg==0){
	printf("i numeri sono uguali!");
} 
else if (magg==1){
	printf("il numero maggiore e' : %d", a); 
}
else{
	printf("il numero maggiore e' : %d", b);
}
return 0;
}

// funzioni

int maggiore (int n1, int n2){
	if(n1 > n2){
		return 1;
	}
	else if(n2 > n1){
		return 2;
	}
	else {
		return 0;
	}
}

#include<stdio.h>

int primo (int);
/* legge un numero e verifica se è primo
   IN: n
   OUT: 1 se primo 0 se non lo è 
*/

int main(){
int n;
printf("inserisci un numero: ");
scanf("%d", &n); 
n = primo(n); 
if (n == 0){
	printf("il numero non e' primo"); 
}
else{
	printf("il numero e' primo"); 
}
return 0;
}

// funzioni

int primo (int n){
	int i = 2; 
	while(i<n/2 && n != 0){
		
		if(n%i == 0){
			n=0; 
		}
		i++; 
	}
	return n; 
}

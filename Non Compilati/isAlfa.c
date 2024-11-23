#include<stdio.h>

int isAlfa (char);
/* legge un valore da tastiera compreso tra un minimo e un massimo
   IN: carattere
   OUT: 1 se alfabetico e 0 se non alfabetico 
*/

int main(){
char a;
printf("inserisci un carattere: "); 
fflush(stdin); 
scanf("%c", &a);
a = isAlfa(a); 

if(a==0){
	printf("non e' un carattere alfabetico"); 
}
else{
	printf("e' un carattere alfabetico"); 
}
}

int isAlfa (char c){ 
	 if (c >= 'a' && c <='z' || c >='A' && c <= 'Z'){
	 	return 1; 
	 }
	 else 
	 	return 0; 	 
}


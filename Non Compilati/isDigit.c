
#include<stdio.h>

int isDigit (char);
/* legge un valore da tastiera compreso tra un minimo e un massimo
   IN: carattere da verificare
   OUT: 1 se vero / 0 se falso
*/

int main(){
char n;
printf("inserisci un carattere numerico: "); 
fflush(stdin); 
scanf("%c", &n);
n = isDigit(n); 
if(n == 1){
	printf("in carattere e' numerico");
}
else{
	printf("il carattere non e' numerico"); 
}
return 0;
}

// funzioni

int isDigit (char c){ 
	 if (c >= '0' && c <='9'){
	 	return 1; 
	 }
	 else 
	 	return 0; 	 
}
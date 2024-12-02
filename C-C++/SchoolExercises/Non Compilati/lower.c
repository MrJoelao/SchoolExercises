#include<stdio.h>

char lower (char);
/* legge una lettera da tastiera e lo manda in miniscolo
   IN: carattere
   OUT: carattere maiuscolo
*/

int main(){
char a; 
do{
printf("inserisci un carattere: ");
fflush(stdin); 
scanf("%c", &a); 
a = lower(a); 
if ( a == 0){
	printf("non e' un carattere maiuscolo!\n"); 
}
}while(a == 0);
printf("%c",a); 
return 0;
}

char lower (char c){
	 
	 if (c >= 'A' && c <='Z'){
	 	c+=32; 
	 	return c; 
	 }
	 else
	 	return 0; 	 
}
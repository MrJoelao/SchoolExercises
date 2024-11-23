#include<stdio.h>

char upper (char);
/* legge una lettera da tastiera e lo manda in maiuscolo
   IN: carattere
   OUT: carattere maiuscolo
*/

int main(){
char a; 
do{
printf("inserisci un carattere: ");
fflush(stdin); 
scanf("%c", &a); 
a = upper(a); 
if ( a == 0){
	printf("non e' un carattere minuscolo!\n"); 
}
}while(a == 0);
printf("%c",a); 
return 0;
}

char upper (char c){
	 
	 if (c >= 'a' && c <='z'){
	 	c-=32; 
	 	return c; 
	 }
	 else
	 	return 0; 	 
}

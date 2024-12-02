#include<stdio.h>

int shifta (char, int);
/* shifta di n volte il carattere inserito
   IN: carattere da shiftare
   OUT: carattere shiftato or 0 se non era una carattere alfabetico 
*/

int main(){
char a; 
int n; 
printf("inserisci la lettera da shiftare: ");
fflush(stdin);
scanf("%c", &a);
printf("inserisci di quanto va shiftata la lettera: "); 
scanf("%d", &n); 
a = shifta (a, n); 
if(a == 0){
	printf("il carattere inserito non era alfabetico"); 
}
else{
	printf("%c", a); 
}
return 0;
}

// funzioni

int shifta (char c, int i){
	if( c <= 'z' && c>= 'a'){
		if( c + i >= 'z'){
			for(i; i> 0; i-- ){
				
				if (c == 'z'){
					c = 'a'; 
				}
				else{
					c++; 
				}
			}
		}
		else{
			c += i; 
		}
	}
	else if ( c <= 'Z' && c>= 'A'){
		if( c + i >= 'Z'){
				for(i; i> 0; i-- ){
				
				if (c == 'Z'){
					c = 'A'; 
				}
				else{
					c++; 
				}
			}
		}
		else{
			c += i; 
		}
	}
	else  c = 0; 
	return c;
}

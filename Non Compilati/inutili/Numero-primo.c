/*
Autore: Joel Stephan
Data:
Versione:
Testo:
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{   
    int a,primo=0,i;
     
    printf("Inserire il numero in analisi: ");
    scanf("%d",&a);
     
     
    for(i = 2; i < a; i++)
    {
        if(a % i == 0)
            primo = 1;
    }
     
    if(primo == 0)
        printf("Il numero e' primo %d",i);
    else
        printf("Il numero non e' primo %d",i);   
     
	printf("\n");
	system("PAUSE");
	return 0;
}

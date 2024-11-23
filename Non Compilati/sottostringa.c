/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
	2 stringhe, verifico che la seconda stringa sia contenuta nella prima
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>
	#include   "TheLib-J.h"

//-------------------------/

//---------/*	Define:
#define MAX 80
//----------------------------------/

//---------/ Funzioni:
void inputStringa(char stringa[]){
	int i;

    fgets(stringa, MAX, stdin);
	
	for (i=0; i<strlen(stringa)-1; i++) {
        stringa[i]=tolower(stringa[i]);
    }
}


int eSottostringa(char stringa0[], char stringa1[]){
	int i,j=0,flag=1;
	
	for (i=0; i<strlen(stringa0)-1 && i<strlen(stringa1)-1; i++){
		if(stringa0[i]==stringa1[j]){
            j++;
            flag=0;
        }
        else{
            j=0;
            flag=1;
        }
	}
	
	
	return flag;
}
//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	char stringa0[MAX],stringa1[MAX];
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	do{
		
		printf("Inserire la stringa madre: ");
    	inputStringa(stringa0);
    
    	printf("Inserire la sottostringa: ");
    	inputStringa(stringa1);
    
    	if(!eSottostringa(stringa0,stringa1)){
    		printf("La sottostringa e' contenuta\n");
		}
		else{
			printf("La sottostringa non e' contenuta\n");
		}
	
    }while(1>0);
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

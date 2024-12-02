/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
	Calcola i giorni che separano due date
/---------*/


//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	
	#include    <math.h>

//-------------------------/

//---------/*	Define:
//----------------------------------/

//---------/ Funzioni:
int calcolaGioni(int gg, int mm, int aaaa){
	int somma=0;
	if(mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12){
		somma=31+gg;
	}else{
		if(mm==2){
		somma=28+gg;
	}
		else{
		somma=30+gg; }
	} 
	return somma+gg+(aaaa*365);
}

//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	int anno0, anno1, mese0, mese1, giorno0, giorno1,n0,n1,diff;
	
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	printf("data1: ");
	scanf("%d %d %d", &giorno0,&mese0, &anno0);
	printf("data2: ");
	scanf("%d %d %d", &giorno1,&mese1, &anno1);
	
	n0=calcolaGioni(giorno0, mese0, anno0);
	n1=calcolaGioni(giorno1, mese1, anno1);
	
	if(n1<n0){
		diff=(n0-n1);
	}
	else{
		diff=(n1-n0); 
	}
	
	printf("differenza di giorni: %d",diff);
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

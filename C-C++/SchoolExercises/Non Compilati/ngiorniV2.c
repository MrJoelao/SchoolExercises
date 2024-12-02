/*---------/ Informazioni:

	Autore: Joel Stephan
	Data:
	Versione: 0

/------------------------*/
/*---------/ Testo:
	Calcola i giorni che separano due date (modifica: eseguire i/o su file e trovare l'anno bisestile)
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
FILE *open_file (FILE *fd, char *namefile, char *mode){
	fd=fopen(namefile, mode);
    if (fd==NULL) { 					    
        printf("ERRORE: Apertura file invalida\n");
        exit(-1); 							
    }
	return fd;
}

void close_file(FILE *fd){
	if(fclose(fd)!=0) {   
        printf("ERRORE: Chiusura file invalida\n");	
        exit(-2); 								
    }
    return;
}

int calcolaGiorni(int giorno, int mese, int anno, int giorniMese[]){
	int i,somma=0;
	
   	for(i=anno; i>0; i--){
   		if(anno%100!=0 && anno%4==0 || anno%400==0){	
   			somma+=366;
		}
		else{		 
			somma+=365;
		}
	anno--; 
	}
		   
	return somma+giorno+giorniMese[mese-1];
}

//----------------------/

//----/* Int Main:
int main(){
	//---------/ Variabili:
	int anno0, anno1, mese0, mese1, giorno0, giorno1,n0,n1,diff, giorniMese[12]={0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
	FILE *differenza;
	//----------------------/

	//---------/ Algoritmo Risolutivo:
	open_file(differenza,"differenza.txt", "w");
	
	printf("data1: ");
	scanf("%d %d %d", &giorno0,&mese0, &anno0);
	printf("data2: ");
	scanf("%d %d %d", &giorno1,&mese1, &anno1);
	
	n0=calcolaGiorni(giorno0, mese0, anno0, giorniMese);
	n1=calcolaGiorni(giorno1, mese1, anno1, giorniMese);
	
	if(n1<n0){
		diff=(n0-n1);
	}
	else{
		diff=(n1-n0); 
	}
	
	printf("differenza di giorni: %d",diff);
	fprintf(differenza,"differenza di giorni: %d\n",diff);
	close_file(differenza);
	//---------------------------------/

	printf("\n");
	system("PAUSE");
	return 0;
}

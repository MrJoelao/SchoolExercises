/*
Autore: Joel Stephan
Data: 17/10/22
Versione:0
Testo: Esercizio in classe.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	//dichiarazione variabili
	int giorno,mese,anno;
	   
	//algoritmo risolutivo
	printf("Inserire la data di oggi con ogni numero separato da uno spazzio. Esempio: 10 4 2022\n");
	scanf("%d %d %d",&giorno,&mese,&anno);

	switch(mese){   
	case 1:
		if(giorno>0 && giorno<32 && anno>1900){
			printf("Crema %d giorno del mese di Gennaio, %d",giorno,anno);
		}
		else{
		if(anno>1900){printf("Giorno inserito non corretto");}
		else{printf("Anno inserito non corretto");}}
	break;
		
	case 2:
		if(giorno>0 && giorno<30 && anno>=1900){
			if(mese%400==0 || mese&4==0 && !(mese%100==0)){
				printf("Crema %d giorno del mese bisestile di Febbraio, %d",giorno,anno);}
			else{
				if(giorno<29){
					printf("Crema %d giorno del mese di Febbraio, %d",giorno,anno);}
				else{printf("Febrraio nel %d non e' bisestile non puoi inserire un numero maggiore di 28",anno);}
			}	
		}
		else{
		if(anno>1900){printf("Giorno inserito non corretto");}
		else{printf("Anno inserito non corretto");}}
	break;
	
	case 3:
		if(giorno>0 && giorno<32 && anno>=1900){
			printf("Crema %d giorno del mesedi Marzo, %d",giorno,anno);
		}
		else{
		if(anno>1900){printf("Giorno inserito non corretto");}
		else{printf("Anno inserito non corretto");}}
	break;
	
	case 5:
		if(giorno>0 && giorno<31 && anno>=1900){
			printf("Crema %d giorno del mesedi Aprile, %d",giorno,anno);
		}
		else{
		if(anno>1900){printf("Giorno inserito non corretto");}
		else{printf("Anno inserito non corretto");}}
	break;
	
	case 6:
		if(giorno>0 && giorno<32 && anno>=1900){
			printf("Crema %d giorno del mesedi Maggio, %d",giorno,anno);
		}
		else{
		if(anno>1900){printf("Giorno inserito non corretto");}
		else{printf("Anno inserito non corretto");}}
	break;
	
	case 7:
		if(giorno>0 && giorno<31 && anno>=1900){
			printf("Crema %d giorno del mesedi Giugno , %d",giorno,anno);
		}
		else{
		if(anno>1900){printf("Giorno inserito non corretto");}
		else{printf("Anno inserito non corretto");}}
	break;
	
	case 8:
		if(giorno>0 && giorno<32 && anno>=1900){
			printf("Crema %d giorno del mesedi Agosto, %d",giorno,anno);
		}
		else{
		if(anno>1900){printf("Giorno inserito non corretto");}
		else{printf("Anno inserito non corretto");}}
	break;
	
	case 9:
		if(giorno>0 && giorno<31 && anno>=1900){
			printf("Crema %d giorno del mesedi Settembre, %d",giorno,anno);
		}
		else{
		if(anno>1900){printf("Giorno inserito non corretto");}
		else{printf("Anno inserito non corretto");}}
	break;
	
	case 10:
		if(giorno>0 && giorno<32 && anno>=1900){
			printf("Crema %d giorno del mesedi Ottobre, %d",giorno,anno);
		}
		else{
		if(anno>1900){printf("Giorno inserito non corretto");}
		else{printf("Anno inserito non corretto");}}
	break;
	
	case 11:
		if(giorno>0 && giorno<31 && anno>=1900){
			printf("Crema %d giorno del mesedi Novembre, %d",giorno,anno);
		}
		else{
		if(anno>1900){printf("Giorno inserito non corretto");}
		else{printf("Anno inserito non corretto");}}
	break;
	
	case 12:
		if(giorno>0 && giorno<32 && anno>=1900){
			printf("Crema %d giorno del mesedi Dicembre, %d",giorno,anno);
		}
		else{
		if(anno>1900){printf("Giorno inserito non corretto");}
		else{printf("Anno inserito non corretto");}}
	break;
	
	default:
		printf("Mese iserito non valido");
	}
			
	printf("\n");
	system("PAUSE");
	return 0;
}

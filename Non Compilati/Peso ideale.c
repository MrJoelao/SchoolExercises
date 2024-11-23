/*
Autore: Joel Stephan
Data:
Versione: 0
Testo:
Sono date N persone; di ogni persona si vuole calcolare il peso ideale; un modo per calcolare 
il peso ideale è con la seguente formula: p= (h-100)*K, dove p è il peso ideale, h è l’altezza 
in cm e K è una costante che vale

    0.95 per maschi oltre 30 anni
    0.85 per maschi fino a 30 anni
    0.8 per femmine oltre 35 anni
    0.7 per femmine fino a 35

nell’acquisire i dati sono richiesti opportuni controlli; inoltre l’altezza viene acquisita in 
metri e centimetri (es 1 m e 68 cm) con 0<=m<=2 e 0<=cm<=99.
*/

#include <stdio.h>
#include <stdlib.h>
#include "lib-J.h"

//maschi
#define k_m_fino	0.85 //fino a 30 anni
#define k_m_oltre	0.95 //oltre 30 anni
//femmine 
#define k_f_fino 	0.7 //fino a 35
#define k_f_foltre	0.8 //oltre 35 anni

int leggi_altezza(int minM, int maxM, int minCm, int maxCm) {
	int altezza_metri,altezza_centimetri;
	
	printf("Inserisca la sua altezza (m,cm): ");
	altezza_metri=leggi_compreso(minM,maxM);
	printf("m, cm: ");
	altezza_centimetri=leggi_compreso(minCm,maxCm);
	
	return altezza_centimetri+altezza_metri*100;
}

float peso(int sesso,int eta,int altezza){
	float peso;
	if(sesso==1){
		//maschi:
		if(eta<=30)
		peso=(altezza-100)*k_m_fino;
		else
		peso=(altezza-100)*k_m_oltre;
	}
	else{
		//femmine:
		if(eta<=30)
		peso=(altezza-100)*k_f_fino;
		else
		peso=(altezza-100)*k_f_foltre;
	}
	return peso;
}



int main(){
	//dichiarazione variabili
	int altezza_tot,eta,sesso;
	//algoritmo risolutivo
	printf("Benvenuto nel calcolatore del peso ideale!\nPer incominciare ci serviranno dei suoi dati personali.\nInserisca se e' maschio (1) o femmina (2): \n");
	sesso=leggi_compreso(1,2);
	
	//input età
	printf("Inserisca la sua eta': ");
	eta=leggi_compreso(1,116); //https://www.google.com/search?client=firefox-b-d&q=et%C3%A0+massima+raggiunta+da+un+umano
	
	//input altezza utilizzando la funzione "leggi_altezza"
	altezza_tot=leggi_altezza(1,2,0,99);
	
	//output peso usado la funzione "peso"
	printf("Il suo peso ideale e': %.2f kg",peso(sesso,eta,altezza_tot));
	
	printf("\n");
	system("PAUSE");
	return 0;
}

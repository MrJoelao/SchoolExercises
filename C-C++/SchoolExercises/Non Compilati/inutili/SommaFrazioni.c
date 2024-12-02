/*
Autore: Joel Stephan
Data: 08/11/2022
Versione: 3
Testo: Trovare la somma fra due frazioni(intere o reali non cambia).
Analisi:
*/

#include <stdio.h>
#include <stdlib.h>
int numTot,denTot,mcm,mcd;
int calc_mcm (int num0, int num1){
	
	int i,minimo;
	
	if(num0<num1){
			minimo=num0;}
		else{
			minimo=num1;}
			
	for( i=1; i<=minimo; i++){
		if(num0%i==0 && num1%i==0){
				mcm=num0*num1/i;
		}
	}
	denTot=mcm;
	return mcm;
}

int calc_mcd (int num0, int num1){
	
	int i,minimo;
	
	if(num0<num1){
			minimo=num0;}
		else{
			minimo=num1;}
			
	for( i=1; i<=minimo; i++){
		if(num0%i==0 && num1%i==0){
				mcd=i;
		}
	}
	return mcd;
}

int leggi_fraz (int tipologia){
	int num;
		if(tipologia==-1){
			printf(" Denominatore:");
				scanf("%d",&num);
			while(num<0){
				printf("Errore: denominatore inserito minore di zero. inserisci un numero maggiore di zero.\n Denominatore:");
				scanf("%d",&num);
			}
	}
	else{
		printf(" Numeratore:");
			scanf("%d",&num);	
	}
	return num;
}

int somma_fraz (int num0, int den0, int num1, int den1){

	mcm=calc_mcm(den0,den1);
	numTot=(num0*mcm)/(den0)+(num1*mcm)/den1;
	mcd=calc_mcd(numTot,mcm);
	
	return 0;
}
int diff_fraz (int num0, int den0, int num1, int den1){

	mcm=calc_mcm(den0,den1);
	numTot=(num0*mcm)/(den0)-(num1*mcm)/den1;
	mcd=calc_mcd(numTot,mcm);
	
	return 0;
}
int molti_fraz (int num0, int den0, int num1, int den1){
	
		numTot=num0*num1;
		denTot=den0*den1;
	
	return 0;
}
int divi_fraz (int num0, int den0, int num1, int den1){
	
	numTot=num0*den1;
	denTot=den0*num1;

	return 0;
}



int main(){
	//dichiarazione varabili
	int num0,den0,num1,den1,scelta;
	
	//algoritmo risolutivo
		//input 1° frazione
	printf("Inserire due frazioni.\nPrima frazione:\n");
		num0=leggi_fraz(0);
		den0=leggi_fraz(-1);

		//input 2° frazione
	printf("Seconda frazione:\n");
		num1=leggi_fraz(0);
		den1=leggi_fraz(-1);
	//scelta tipologia operazione
	printf("Che tipo di operazione vuoi applicare?\n1. Somma\n2. Differenza\n3. Moltiplicazione\n4. Divisione\n");
		scanf("%d",&scelta);
		
	switch(scelta){
		case 1:
			
			//somma tra frazioni
			somma_fraz(num0,den0,num1,den1);
			break;
		case 2:
			
			//differenza tra frazioni
			diff_fraz(num0,den0,num1,den1);
			break;
		case 3:
			
			//moltiplicazione tra frazioni
			molti_fraz(num0,den0,num1,den1);
			break;
		case 4:
			
			//divisioni tra frazioni
			divi_fraz(num0,den0,num1,den1);
			break;
		default:
			
			//output errore
			printf("ERRORE: Scelta non valida, immettere un valore tra 1-4!");
			break;
	}
	
	if(numTot%denTot==0){
		printf("Il risultato della somma delle due frazioni e':%d",numTot/denTot);
	}
	else{
		printf("Il risultato della somma delle due frazioni e':%d/%d",numTot,denTot);
	}


	printf("\n");
	system("PAUSE");
	return 0;
}

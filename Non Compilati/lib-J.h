#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
#include<math.h>

//libreria di Joel Stephan 3IB (#include "lib-J.h")


//--------------------------/*	Variabili:	*\-------------------------------\\

	int randomInizializzato=0; /*Variabile flag che indica se il generatore è 
								già stato inizializzato*/
	
//-----------------------------------------------------------------------------\\


/*---------------------------------------------------------------------------
	Funzione che verifica che un valore un input sia nel intervello scelto 
-----------------------------------------------------------------------------*/
int leggi_compreso(int min, int max){
    int valore;
     //Verifica che "min" sia minore di "max", in caso contrario restituisco -1 con un messaggio di errore.
    if(min<max){
    	// Continua a chiedere un valore all'utente finché il valore inserito non è compreso tra min e max
    	do{
        	scanf("%d",&valore);
        	 // Se valore è minore di min o maggiore di max, stampa un messaggio di errore
        	if(valore<min || valore>max){
           		printf("ERRORE: Valore inserito non valido!, inserisci un valore compreso tra %d e %d: ",min,max);
        	}
    	}while(valore<min || valore>max);
    	 // Restituisce il valore inserito dall'utente	
    	return valore;
    }
    else{
     	 // Restituisce il messaggio di errore e restituisce -1
    	printf("ERRORE: Valori di intervallo non validi!, inserisci i numeri in ordine crescente");
    	return -1;
	}
}

/*----------------------------------------------------------------------- 
	Funzione che legge in input un valore maggiore di x
-------------------------------------------------------------------------*/
int leggi_maggiore(int min){
    int valore;
    // Continua a chiedere un valore all'utente finché il valore inserito non è minore di min
    do{
        scanf("%d",&valore);
        // Se valore è minore di min, stampa un messaggio di errore
        if(valore<min){
            printf("ERRORE: Valore inserito non valido!, inserisci un valore maggiore di %d: ",min);
        }
    }while(valore<min);
    // Restituisce il valore inserito dall'utente
    return valore;
}

/*----------------------------------------------------------------------- 
	Funzione che legge in input un valore minore di x
-------------------------------------------------------------------------*/
int leggi_minore(int min){
    int valore;
    // Continua a chiedere un valore all'utente finché il valore inserito non è maggiore di min
    do{
        scanf("%d",&valore);
        // Se valore è maggiore di min, stampa un messaggio di errore
        if(valore>min){
            printf("ERRORE: Valore inserito non valido!, inserisci un valore minore di %d: ",min);
        }
    }while(valore>min);
    // Restituisce il valore inserito dall'utente
    return valore;
}

/*---------------------------------------------------------------------- 
	Funzione che legge in input un valore diverso di un valore scelto
------------------------------------------------------------------------*/
int leggi_diverso(int num){
    int valore;
    // Continua a chiedere un valore all'utente finché il valore non è uguale a num
    do{
        scanf("%d",&valore);
        // Se valore è uguale a num, stampa un messaggio di errore
        if(valore==num){
            printf("ERRORE: Valore inserito non valido!, inserisci un valore diverso da %d: ",num);
        }
    }while(valore==num);
    // Restituisce il valore inserito dall'utente
    return valore;
}

/*---------------------------------------------------------------- 
	Funzione per trovare il numero minore in un array di numeri
------------------------------------------------------------------*/
int valmin(int numeri[], int lunghezza) {
    int minore=numeri[0],i; //inizializziamo il numero minore con il primo elemento dell'array
    //ciclo per trovare il numero minore nell'array
    for (i=1; i<lunghezza; i++) {
        //se l'elemento attuale è minore di quello che abbiamo memorizzato
        if (numeri[i]<minore) {
            minore=numeri[i]; //memorizziamo questo elemento come nuovo minore
        }
    }
    return minore;
}

/*--------------------------------------------- 
	Funzione per il valore minimo (2 numeri)
-----------------------------------------------*/
int valmin_2(int a,int b){
    // Controlla se a è minore di b
    if(a<b){
        // Se a è minore di b, restituisce a
        return a;
    }
    else{
        /* Se a non è né minoreallora b deve essere minore di a
        quindi viene restituito il valore di b*/
        return b;
    }
}

/*---------------------------------------------
	Funzione per il valore minimo (3 numeri)
-----------------------------------------------*/
int valmin_3(int a,int b,int c){
    // Controlla se a è il valore minore tra a, b e c
    if(a<b && a<c){
        // Se a è il valore minore, restituisce a
        return a;
    }
    else{
        // Se a non è il valore minore, controlla se b è il valore minore
        if(b<a && b<c){
            // Se b è il valore minore, restituisce b
            return b;
        }
        else{
            /* Se né a né b sono il valore minore e a, allora c deve essere il valore minore
            quindi viene restituito il valore di c */
             return c;
        }
    }
}

/*---------------------------------------------------------------- 
	Funzione per trovare il numero maggiore in un array di numeri
------------------------------------------------------------------*/
int valmax(int numeri[], int lunghezza) {
    int maggiore=numeri[0],i; //inizializziamo il numero maggiore con il primo elemento dell'array
    //ciclo per trovare il numero maggiore nell'array
    for (i=1; i<lunghezza; i++) {
        //se l'elemento attuale è maggiore di quello che abbiamo memorizzato
        if (numeri[i]>maggiore) {
            maggiore=numeri[i]; //memorizziamo questo elemento come nuovo maggiore
        }
    }
    return maggiore;
}

/*----------------------------------------------
	Funzione per il valore massimo (2 numeri)
------------------------------------------------*/
int valmax_2(int a,int b){
    // Controlla se a è minore di b
    if(a>b){
        // Se a è maggiore di b, restituisce a
        return a;
    }
    else{
        /* Se a non è né maggiore di b allora b deve essere maggiore di a
        quindi viene restituito il valore di b*/
        return b;
    }
}

/*---------------------------------------------
	Funzione per il valore massimo (3 numeri)
-----------------------------------------------*/
int valmax_3(int a,int b,int c){
    // Controlla se a è il valore maggiore tra a, b e c
    if(a>b && a>c){
        // Se a è maggiore di b e di c, restituisce a
        return a;
    }
    else{
        // Se a non è il valore maggiore, controlla se b è il valore maggiore
        if(b>a && b>c){
            // Se b è il valore maggiore, restituisce b
            return b;
        }
        else{
            /* Se né a né b sono maggiori di c, allora c deve essere il valore maggiore tra i 3
            quindi viene restituito il valore di c*/
                return c;
        }
    }
}

/*-----------------------------------------------
	Funzione che verifica se un numero è primo
-------------------------------------------------*/
int num_primo(int num){
    // Variabile per memorizzare se il numero è primo o no
    int primo = 0,i;

    // Ciclo che parte da 2 (poiché ogni numero è divisibile per 1)
    // fino a num (escluso) o finché non viene trovato un divisore per num
    for (i=2; i<num && primo==0; i++) {
        // Verifica se il resto della divisione di num per i è uguale a 0
        if (num%i==0) {
            // Se il resto è 0, significa che num è divisibile per i
            // quindi non è un numero primo
            primo=1;
        }
    }
     
    // Restituisce 0 se num è un numero primo, altrimenti restituisce 1
    return primo;
}

/*------------------------------------------------- 
	Fattoriale, calcola il fattoriale di un numero
---------------------------------------------------*/ 
int calc_fat(int num) {
    // Variabile per memorizzare il risultato del calcolo
    int risultato=1;
    // Ciclo che moltiplica il numero per i suoi interi precedenti fino a 1
    for (int i=num; i>1; i--) {
        risultato=risultato*i;
    }
    // Restituzione del risultato
    return risultato;
}

/*----------------------------------------------------------------    
	Media, Funzione per calcolare la media di un array di numeri
------------------------------------------------------------------*/ 
float calc_media(int numeri[], int lunghezza) {
    int somma=0, media,i; // variabile per memorizzare la somma dei numeri
    //ciclo che somma tutti i numeri nell'array
    for (i=0; i<lunghezza; i++) {
        somma=somma+numeri[i];
    }
    //calcola la media dei numeri
    media=somma/lunghezza;
    // restituisce la media calcolata
    return media;
}

/*-----------------------------------------------
	Funzione che calcola la potenza di un numero
-------------------------------------------------*/
int calc_pot(int num, int esponente) {
  int i, risultato=1;

  // Se l'esponente è maggiore o uguale di zero, calcola la potenza di num elevato a esponente
  if (esponente>=0) {
    for (i=1; i<=esponente; i++) {
      risultato=num*risultato;
    }
  }
  // Se l'esponente è minore di zero, stampa un messaggio di errore
  else {
  	printf("\nERRORE IN INPUT:Inserire un esponente positivo\n");
    risultato=-1;
  }
  return risultato;
}

/*--------------------------------------------------------------------------------
	Disposizioni, funzione che calcola le disposizioni, utilizzando il fattoriale
----------------------------------------------------------------------------------*/
int calc_disp(int n, int k) {
	//formula per le disposizioni
	return calc_fat(n)/calc_fat(n-k);
}

/*--------------------------------------------------------------------------------
	Combinazioni, funzione che calcola le combinazioni, utilizzando il fattoriale
----------------------------------------------------------------------------------*/
// 
int calc_comb(int n, int k) {
	//formula per le combinazioni
	return calc_fat(n)/(calc_fat(k)*calc_fat(n-k));
}


/*--------------------------------------------------------------------------
	MCM, Funzione che calcola il minimo comune multiplo di due numeri a e b
----------------------------------------------------------------------------*/
int calc_mcm (int num0, int num1) {
    int i, mcm, minimo;

    // Determina il minimo tra num0 e num1 usando la funzione valmin_2
    minimo=valmin_2(num0,num1);

    // Ciclo che cerca il mcm dei due numeri
    for (i=1; i<=minimo; i++) {
        // Se i è divisore sia di num0 che di num1, calcola il mcm
        if (num0%i==0 && num1%i==0) {
            mcm=num0*num1/i;
        }
    }
    // Restituisce il valore di mcm
    return mcm;
}

/* ------------------------------------------------------------------------------
	MCD, Funzione che calcola il massimo comune divisore di due numeri a e b
---------------------------------------------------------------------------------*/
int calc_mcd (int num0, int num1) {
    int i, mcd, minimo;

	// Determina il minimo tra num0 e num1 usando la funzione valmin_2
	minimo=valmin_2(num0,num1);

    // Ciclo che cerca il mcd dei due numeri
    for (i=2; i<=minimo; i++) {
        // Se i è divisore sia di num0 che di num1, assegna a mcd il valore di i
        if (num0%i==0 && num1%i==0) {
            mcd=i;
        }
    }
    // Restituisce il valore di mcd
    return mcd;
}

/* ---------------------------------------------------------------------------------
	Sconto, Funzione che calcola lo sconto tra prezzo e la percentuale di sconto
------------------------------------------------------------------------------------*/
float calc_sconto (float prezzo, float perc_sconto){
	//Applica lo sconto al prezzo originale utilizzando la formula prezzo((100-perc_sconto)/100)
	prezzo=prezzo*((100-perc_sconto)/100);
	//Restituisce il prezzo scontato
	return prezzo;
}

/*-------------------------------------------------------------------------
	(SYSTEM), funzione necessaria per evitare di mettere srand nel int main
---------------------------------------------------------------------------*/
void system_cas(){
    if(!randomInizializzato){ //se "randomInizializzato" non è stato inizializato (0) fare srand
        srand(time(0));	//questo permette di evitare srand nel int main
        randomInizializzato=1; //una volta inizializato srand metto "randomInizializzato" a 1
    }
}

/* -----------------------------------
	Casuale, Genera un numero casuale 
--------------------------------------*/
int num_cas(){
	//verifica il flag
    if(!randomInizializzato) system_cas();

    return rand();
}

/* -------------------------------------------------------
	Casuale, Genera un numero casuale tra un range scelto
----------------------------------------------------------*/
int cas_compreso(int min, int max){
	//verifica il flag
    if(!randomInizializzato) system_cas();
        
    return (rand()%(max-min+1))+min;
}

/* -------------------------------------------------------------------
	numero giorni, trasforma la data dal fromato gg/mm/aaaa in giorni
----------------------------------------------------------------------*/
int calc_n_giorni (int gg, int mm, int aaaa, int bis){
	
	/* Questa funzione prende in input una data espressa in 
	formato gg/mm/aaaa, e restituisce il numero di giorni trascorsi dall'inizio dell'anno di quella data.*/
	
   	while(aaaa!=bis){	// Cicla finché non si arriva all'anno bisestile
   		if(aaaa%100!=0 && aaaa%4==0){	// Se l'anno è bisestile, il mese di febbraio ha 29 giorni
   			gg+=366;
		}
		else{		 // Altrimenti ha 28 giorni
			gg+=365;
		}
	aaaa--;  // Decrementa l'anno per passare all'anno precedente
	}
		   
	switch(mm){	// Aggiunge il numero di giorni dei mesi trascorsi nell'anno corrente
		case 1:
			gg+=0;
		 break;
		 
		case 2:
			gg+=31;
		 break;

		case 3:
			gg+=60;
		 break;
		
		case 4:
			gg+=91;
		 break;
			
		case 5:
			gg+=121;
		 break;
			
		case 6:
			gg+=152;
		 break;
			
		case 7:
			gg+=182;
		 break;
			
		case 8:
			gg+=213;
		 break;
			
		case 9:
			gg+=244;
		 break;
			
		case 10:
			gg+=274;
		 break;
			
		case 11:
			gg+=305;
		 break;
			
		case 12:
			gg+=335;
		 break;
			 
		default:
			gg=-1;	// in caso di errore restituisce -1
		 break;
		}
		
	return gg;	// Restituisce il numero di giorni trascorsi dall'inizio dell'anno di quella data
}
  
/*----------------------------------------------------
	Differenza date, esegue la differenza tra due date
------------------------------------------------------*/
int diff_data (int gg1, int mm1, int aaaa1, int gg2, int mm2, int aaaa2){
	/* Questa funzione prende in input due date in formato 
	gg/mm/aaaa, e restituisce il numero di giorni trascorsi tra le due date.*/
	
  	int min, diff, bisestile;
  	
  	min=aaaa1; //assegna min a anno1 e
  	
  	if(aaaa2<min){	//verifica qual'è il minore tra i due trovando anno più piccolo
  		min=aaaa2;
	}
	
	if(min%100!=0 && min%4==0){
		bisestile=min; 
	}
	else{
		while(min%100==0 && min%4!=0){
			min--; 
		}
	bisestile=min; 
	}
	
	gg1=calc_n_giorni(gg1,mm1,aaaa1,bisestile); /* Trasforma la prima data in giorni trascorsi dall'inizio 
											dell'anno*/
	gg2=calc_n_giorni(gg2,mm2,aaaa2,bisestile); /* Trasforma la seconda data in giorni trascorsi dall'inizio 
											dell'anno*/
	
	if(gg2<gg1){
		diff=(gg1-gg2);
	}
	else{
		diff=(gg2-gg1); 
	}
	
	return diff; 
  }
  
/*--------------------------------------------
	Swap, scambia i valori tra due variabili
----------------------------------------------*/
void swap (int* a, int* b) { //swap+z per non andare in conflitto con altre funzioni di altre librerie
    int temp = *a; //dichiaro temp e gli asseggno il valore di a
    *a = *b;	//assegno il valore di b ad a
    *b = temp;	//assegno il valore di temp (a) ad b
}

/*-------------------------------------------------------
	array out, stampare gli elementi di un array 
---------------------------------------------------------*/
void array_out(int arr[], int dimensione) {
	int i; //dichiaro i
    for (i=0; i<dimensione; i++) {	//ciclo stampa array
        printf("%d ", arr[i]);
    }
    printf("\n"); //spazio tra i numeri
}

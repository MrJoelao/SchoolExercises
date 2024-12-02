/*


    /$$$$$                     /$$        /$$$$$$   /$$                         /$$                          
   |__  $$                    | $$       /$$__  $$ | $$                        | $$                          
      | $$  /$$$$$$   /$$$$$$ | $$      | $$  \__//$$$$$$    /$$$$$$   /$$$$$$ | $$$$$$$   /$$$$$$  /$$$$$$$ 
      | $$ /$$__  $$ /$$__  $$| $$      |  $$$$$$|_  $$_/   /$$__  $$ /$$__  $$| $$__  $$ |____  $$| $$__  $$
 /$$  | $$| $$  \ $$| $$$$$$$$| $$       \____  $$ | $$    | $$$$$$$$| $$  \ $$| $$  \ $$  /$$$$$$$| $$  \ $$
| $$  | $$| $$  | $$| $$_____/| $$       /$$  \ $$ | $$ /$$| $$_____/| $$  | $$| $$  | $$ /$$__  $$| $$  | $$
|  $$$$$$/|  $$$$$$/|  $$$$$$$| $$      |  $$$$$$/ |  $$$$/|  $$$$$$$| $$$$$$$/| $$  | $$|  $$$$$$$| $$  | $$
 \______/  \______/  \_______/|__/       \______/   \___/   \_______/| $$____/ |__/  |__/ \_______/|__/  |__/
                                                                     | $$                                    
                                                                     | $$                                    
                                                                     |__/                                    

                                                                                                                                                   
*/

/*------------------------------------------/*	Cambiamenti:	*\------------------------------------------*\  
	Versione 2.0 di lib-J.h adesso rinominata TheLib-J.h in modo da non interagire con quella vecchia, i 
	maggiori cambiamenti sono grafici, la creazione di una sezione di funzioni float che ho fatto di fretta 
	quindi non garantisco la massima sicurezza, ordinamento delle funzioni cambiato per una maggiore chiarezza 
	e fix di errori qua e la.
	
	[Versione  2.0, aggiornata al 2/04/23, Joel Stephan 3IB]
	
	Versione 2.1 di Lib-J.h aggiunta la sezione char e file per un maggiore ordine, fix vari (varie funzioni 
	void senza il return) e aggiunta di funzioni generali qua e la.
		
	[Versione  2.1, aggiornata al 21/05/23, Joel Stephan 3IB]
/*-----------------------------------------------------------------------------------------------------------*/

//---------/*	Librerie:	*\---------\\

	#include    <stdio.h>					
	#include    <stdlib.h>
	#include    <time.h> 
	#include    <math.h>
	#include    <string.h>                                                                                 

//-------------------------------------\\

//--------------------------/*	Variabili:	*\-------------------------------\\

	int randomInizializzato=0; /*Variabile flag che indica se il generatore è 
								già stato inizializzato*/
	
//-----------------------------------------------------------------------------\\

/*---------/


  /$$$$$$  /$$             /$$                            
 /$$__  $$|__/            | $$                            
| $$  \__/ /$$  /$$$$$$$ /$$$$$$    /$$$$$$  /$$$$$$/$$$$ 
|  $$$$$$ | $$ /$$_____/|_  $$_/   /$$__  $$| $$_  $$_  $$
 \____  $$| $$|  $$$$$$   | $$    | $$$$$$$$| $$ \ $$ \ $$
 /$$  \ $$| $$ \____  $$  | $$ /$$| $$_____/| $$ | $$ | $$
|  $$$$$$/| $$ /$$$$$$$/  |  $$$$/|  $$$$$$$| $$ | $$ | $$
 \______/ |__/|_______/    \___/   \_______/|__/ |__/ |__/
                                                          
                                                                                                                                                                       
/---------*/

/*-------------------------------------------------------------------------
	(SYSTEM), funzione necessaria per evitare di mettere srand nel int main
---------------------------------------------------------------------------*/
void system_cas(){
    if(!randomInizializzato){ //se "randomInizializzato" non è stato inizializato (0) fare srand
        srand(time(0));	//questo permette di evitare srand nel int main
        randomInizializzato=1; //una volta inizializato srand metto "randomInizializzato" a 1
    }
}

/*---------/


 /$$$$$$$$ /$$                           /$$$$$$             /$$                                  
|__  $$__/|__/                          |_  $$_/            | $$                                  
   | $$    /$$  /$$$$$$   /$$$$$$         | $$   /$$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$   /$$$$$$ 
   | $$   | $$ /$$__  $$ /$$__  $$        | $$  | $$__  $$|_  $$_/   /$$__  $$ /$$__  $$ /$$__  $$
   | $$   | $$| $$  \ $$| $$  \ $$        | $$  | $$  \ $$  | $$    | $$$$$$$$| $$  \__/| $$  \ $$
   | $$   | $$| $$  | $$| $$  | $$        | $$  | $$  | $$  | $$ /$$| $$_____/| $$      | $$  | $$
   | $$   | $$| $$$$$$$/|  $$$$$$/       /$$$$$$| $$  | $$  |  $$$$/|  $$$$$$$| $$      |  $$$$$$/
   |__/   |__/| $$____/  \______/       |______/|__/  |__/   \___/   \_______/|__/       \______/ 
              | $$                                                                                
              | $$                                                                                
              |__/                                                                                

                                                                                                                
/---------*/                                                    

/*------Funzione-leggi------*/

/*-----------------------------------------------------------------------------------------
	leggi_compreso. Funzione che verifica che un valore un input sia nel intervello scelto 
-------------------------------------------------------------------------------------------*/
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

/*------------------------------------------------------------------------ 
	leggi_maggiore. Funzione che legge in input un valore maggiore di min
--------------------------------------------------------------------------*/
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

/*-------------------------------------------------------------------- 
	leggi_minore. Funzione che legge in input un valore minore di max
----------------------------------------------------------------------*/
int leggi_minore(int max){
    int valore;
    // Continua a chiedere un valore all'utente finché il valore inserito non è maggiore di min
    do{
        scanf("%d",&valore);
        // Se valore è maggiore di min, stampa un messaggio di errore
        if(valore>max){
            printf("ERRORE: Valore inserito non valido!, inserisci un valore minore di %d: ",max);
        }
    }while(valore>max);
    // Restituisce il valore inserito dall'utente
    return valore;
}

/*----------------------------------------------------------------------
	leggi_diverso. Funzione che legge in input un valore diverso di num
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

/*-------------------------------------------------------------------- 
	vMin. Funzione per trovare il numero minore in un array di numeri
---------------------------------------------------------------------*/
int vMin(int numeri[], int lunghezza) {
    int minore=numeri[0],i; //inizializzo il numero minore con il primo elemento dell'array
    
    for (i=1; i<lunghezza; i++) {	//ciclo per trovare il numero minore nell'array
        
        if (numeri[i]<minore) {	//se l'elemento attuale è minore di quello che abbiamo memorizzato
            minore=numeri[i]; //memorizzo l'elemento[i] come nuovo minore
        }
    }
    return minore;
}

/*--------------------------------------------------
	vMin_2. Funzione per il valore minimo (2 numeri)
----------------------------------------------------*/
int vMin_2(int a, int b){
    // Controllo se a è minore di b
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

/*--------------------------------------------------
	vMin_3. Funzione per il valore minimo (3 numeri)
----------------------------------------------------*/
int vMin_3(int a,int b,int c){
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

/*----------------------------------------------------------------------
	vMax. Funzione per trovare il numero maggiore in un array di numeri
------------------------------------------------------------------------*/
int vMax(int numeri[], int lunghezza) {
    int maggiore=numeri[0],i; //inizializziamo il numero maggiore con il primo elemento dell'array

    for (i=1; i<lunghezza; i++) {	//ciclo per trovare il numero maggiore nell'array
        if (numeri[i]>maggiore) {	//se l'elemento attuale è maggiore di quello che abbiamo memorizzato
            maggiore=numeri[i]; 	//memorizziamo questo elemento[i] come nuovo maggiore
        }
    }
    return maggiore;
}

/*---------------------------------------------------
	vMax_2. Funzione per il valore massimo (2 numeri)
-----------------------------------------------------*/
int vMax_2(int a,int b){
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
	vMax_3. Funzione per il valore massimo (3 numeri)
-----------------------------------------------*/
int vMax_3(int a,int b,int c){
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
	nPrimo. Funzione che verifica se un numero è primo
-------------------------------------------------*/
int nPrimo(int num){
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
    int somma=0,i; // variabile per memorizzare la somma dei numeri
    float media;
    
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
    minimo=vMin_2(num0,num1);

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
	minimo=vMin_2(num0,num1);

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

/* -----------------------------------
	num_cas, Genera un numero casuale 
--------------------------------------*/
int num_cas(){
	//verifica il flag
    if(!randomInizializzato) system_cas();

    return rand();
}

/* ------------------------------------------------------------
	cas_compreso, Genera un numero casuale tra un range scelto
---------------------------------------------------------------*/
int cas_compreso(int min, int max){
	//verifica il flag
    if(!randomInizializzato) system_cas();
    
    return (rand()%(max-min+1))+min;
}

/* -------------------------------------------------------------------
	calc_n_giorni, trasforma la data dal fromato gg/mm/aaaa in giorni
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
	diff_data, esegue la differenza tra due date
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
  
/*-------------------------------------------
	Swap, scambia i valori tra due variabili
---------------------------------------------*/
void swap (int* a, int* b) {
    int temp = *a; //dichiaro temp e gli asseggno il valore di a
    *a = *b;	//assegno il valore di b ad a
    *b = temp;	//assegno il valore di temp (a) ad b
    
    return;
}

/* ----------------------------------------------------------------------------
	arrOrdinato, funzione che verifica se un array è ordinato in modo crescente
-------------------------------------------------------------------------------*/
int arrOrdinato(int array[], int lunghezza) {
    int i; 
    for (i=1; i<lunghezza; i++) { // ciclo che scorre l'array dall'indice 1 all'indice lunghezza-1
        if (array[i]<array[i-1]) { // se un elemento successivo è minore di quello precedente, l'array non è ordinato
            return 0; // restituisce 0 per indicare che l'array non è ordinato
        }
    }
    return 1; // se il ciclo termina senza restituire 0, l'array è ordinato e restituisce 1
}

/* -----------------------------------------------------------------------------------
	cercaVal, funzione che cerca un valore in un array e restituisce la sua posizione
--------------------------------------------------------------------------------------*/
int cercaVal(int array[], int lunghezza, int valore) {
    int i; 
    for (i=0; i<lunghezza; i++) { // ciclo che scorre l'array dall'indice 0 all'indice lunghezza-1
        if (array[i]==valore) { // se l'elemento corrente è uguale al valore cercato
            return i; // restituisce l'indice dell'elemento corrente
        }
    }
    return -1; // se non viene trovato il valore, restituisce -1 per indicare che il valore non è presente nell'array
}

/*-----------------------------------------------
	array out, stampare gli elementi di un array 
-------------------------------------------------*/
void array_out(int arr[], int dimensione) {
	int i; //dichiaro i
    for (i=0; i<dimensione; i++) {	//ciclo stampa array
        printf("%d ", arr[i]);
    }
    printf("\n"); //spazio tra i numeri
}

/*-------------------------------------------------------------
	sel sort, ordinamento di un array usando il selection sort 
---------------------------------------------------------------*/
void sel_sort(int vett[], int n) {
    int i, j, indice_minimo;

    for (i=0; i<n-1; i++) {	// Ciclo esterno che scorre l'array fino all'elemento n-2

        indice_minimo=i;	// Trova l'elemento minimo nell'array non ordinato
        for (j=i+1; j<n; j++) {
            if (vett[j]<vett[indice_minimo]) {
                indice_minimo=j;
            }
        }

        swap(&vett[indice_minimo], &vett[i]);	// Scambia l'elemento minimo con il primo elemento nell'array non ordinato
    }
}

/*-------------------------------------------------------------------------
	bubble sort, ordinamento di un array usando il bubble sort (ottimizato)
---------------------------------------------------------------------------*/
void bubbleSort(int array[], int n) {
    int scambiato, i, temp; // flag, contatore e variabile temporanea
    
    do {
        scambiato=0; // Inizializza la variabile scambiato a 0
        i=0; // Inizializza il contatore del ciclo while a 0
        
        while (i<n-1) { // Continua finché non abbiamo scansionato tutti gli elementi
            if (array[i]>array[i+1]){ // Se l'elemento corrente è maggiore di quello successivo
                // Esegue lo scambio tra gli elementi
                temp=array[i];
                array[i]=array[i + 1];
                array[i+1]=temp;
                
                scambiato=1; // Imposta la variabile scambiato a 1 per indicare uno scambio
            }
            i++; // Passa all'elemento successivo
        }
        
        n--; // Decrementa n in modo da escludere l'ultimo elemento già ordinato
    } while (scambiato); // Continua finché ci sono scambi da fare
}

/*-------------------------------------------------------------\
	uscita, chiede al utente di uscire dal programma (!uscita()) 
---------------------------------------------------------------*/
int uscita() {
    char risposta; // variabile per memorizzare la risposta dell'utente
    printf("Uscire dal programma? (y or n): "); // stampa il messaggio di richiesta
    scanf(" %c", &risposta); // legge la risposta dell'utente
    if (risposta == 'y' || risposta == 'Y') { // se la risposta è 'y' o 'Y'
        return 1; // restituisce 1 per indicare l'uscita dal programma
    } else {
        return 0; // altrimenti restituisce 0 per indicare di non uscire dal programma
    }
}

/*---------/ 


 /$$$$$$$$ /$$                           /$$$$$$$$ /$$                       /$$    
|__  $$__/|__/                          | $$_____/| $$                      | $$    
   | $$    /$$  /$$$$$$   /$$$$$$       | $$      | $$  /$$$$$$   /$$$$$$  /$$$$$$  
   | $$   | $$ /$$__  $$ /$$__  $$      | $$$$$   | $$ /$$__  $$ |____  $$|_  $$_/  
   | $$   | $$| $$  \ $$| $$  \ $$      | $$__/   | $$| $$  \ $$  /$$$$$$$  | $$    
   | $$   | $$| $$  | $$| $$  | $$      | $$      | $$| $$  | $$ /$$__  $$  | $$ /$$
   | $$   | $$| $$$$$$$/|  $$$$$$/      | $$      | $$|  $$$$$$/|  $$$$$$$  |  $$$$/
   |__/   |__/| $$____/  \______/       |__/      |__/ \______/  \_______/   \___/  
              | $$                                                                  
              | $$                                                                  
              |__/                                                                  

                                                                                                                                                                                
/---------*/

/*------Funzione-leggi------*/

/*--------------------------------
	leggi_compreso_float. [float] 
----------------------------------*/
float leggi_compreso_f(float min, float max){
    float valore;
     //Verifica che "min" sia minore di "max", in caso contrario restituisco -1 con un messaggio di errore.
    if(min<max){
    	// Continua a chiedere un valore all'utente finché il valore inserito non è compreso tra min e max
    	do{
        	scanf("%f",&valore);
        	 // Se valore è minore di min o maggiore di max, stampa un messaggio di errore
        	if(valore<min || valore>max){
           		printf("ERRORE: Valore inserito non valido!, inserisci un valore compreso tra %f e %f: ",min,max);
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

/*--------------------------------
	leggi_maggiore_float. [float]
----------------------------------*/
float leggi_maggiore_f(float  min){
    float valore;
    // Continua a chiedere un valore all'utente finché il valore inserito non è minore di min
    do{
        scanf("%f",&valore);
        // Se valore è minore di min, stampa un messaggio di errore
        if(valore<min){
            printf("ERRORE: Valore inserito non valido!, inserisci un valore maggiore di %f: ",min);
        }
    }while(valore<min);
    // Restituisce il valore inserito dall'utente
    return valore;
}

/*------------------------------
	leggi_minore_float. [float]
--------------------------------*/
float leggi_minore_f(float max){
    float valore;
    // Continua a chiedere un valore all'utente finché il valore inserito non è maggiore di min
    do{
        scanf("%f",&valore);
        // Se valore è maggiore di min, stampa un messaggio di errore
        if(valore>max){
            printf("ERRORE: Valore inserito non valido!, inserisci un valore minore di %f: ",max);
        }
    }while(valore>max);
    // Restituisce il valore inserito dall'utente
    return valore;
}

/*-------------------------------
	leggi_diverso_float. [float]
---------------------------------*/
float leggi_diverso_f(float num){
    float valore;
    // Continua a chiedere un valore all'utente finché il valore non è uguale a num
    do{
        scanf("%f",&valore);
        // Se valore è uguale a num, stampa un messaggio di errore
        if(valore==num){
            printf("ERRORE: Valore inserito non valido!, inserisci un valore diverso da %f: ",num);
        }
    }while(valore==num);
    // Restituisce il valore inserito dall'utente
    return valore;
}

/*----------------------
	vMin_float. [float]
------------------------*/
float vMin_f(float numeri[], int lunghezza) {
    float minore=numeri[0]; //inizializziamo il numero minore con il primo elemento dell'array
    int i;
    //ciclo per trovare il numero minore nell'array
    for (i=1; i<lunghezza; i++) {
        //se l'elemento attuale è minore di quello che abbiamo memorizzato
        if (numeri[i]<minore) {
            minore=numeri[i]; //memorizziamo questo elemento come nuovo minore
        }
    }
    return minore;
}

/*-----------------------
	vMin_2_float [float]
-------------------------*/
float vMin_2_f(float a, float b){
    // Controllo se a è minore di b
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

/*------------------------
	vMin_3_float. [float]
-------------------------*/
float vMin_3_f(float a, float b, float c){
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

/*----------------------
	vMax_float. [float]
------------------------*/
float vMax_f(float numeri[], int lunghezza) {
    float maggiore=numeri[0]; //inizializziamo il numero maggiore con il primo elemento dell'array
    int i;
    //ciclo per trovare il numero maggiore nell'array
    for (i=1; i<lunghezza; i++) {
        //se l'elemento attuale è maggiore di quello che abbiamo memorizzato
        if (numeri[i]>maggiore) {
            maggiore=numeri[i]; //memorizziamo questo elemento come nuovo maggiore
        }
    }
    return maggiore;
}

/*------------------------
	vMax_2_float. [float]
--------------------------*/
float vMax_2_f(float a, float b){
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

/*------------------------
	vMax_3_float. [float]
--------------------------*/
float vMax_3_f(float a, float b, float c){
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

/*------------------------    
	calc_media_f, [float]
--------------------------*/ 
float calc_media_f(float numeri[], int lunghezza) {
    int i; // variabile per memorizzare la somma dei numeri
    float media,somma=0;
    
    //ciclo che somma tutti i numeri nell'array
    for (i=0; i<lunghezza; i++) {
        somma=somma+numeri[i];
    }
    //calcola la media dei numeri
    media=somma/lunghezza;
    // restituisce la media calcolata
    return media;
}

/* ---------------------------------------------------------------------------------
	calc_sconto, Funzione che calcola lo sconto tra prezzo e la percentuale di sconto
------------------------------------------------------------------------------------*/
float calc_sconto (float prezzo, float perc_sconto){
	//Applica lo sconto al prezzo originale utilizzando la formula prezzo((100-perc_sconto)/100)
	prezzo=prezzo*((100-perc_sconto)/100);
	//Restituisce il prezzo scontato
	return prezzo;
}

/* ------------------------
	num_cas_float, [float]
---------------------------*/
float num_cas_f(){
	//verifica il flag
    if(!randomInizializzato) system_cas();

    return rand();
}

/* -----------------------------
	cas_compreso_float, [float]
--------------------------------*/
float cas_compreso_f(int min, int max){
	//verifica il flag
    if(!randomInizializzato) system_cas();
    
    return ((float)rand()/(float)RAND_MAX)*(max-min)+min;
}

/*---------------------------
	array_out_float, [float]
-----------------------------*/
void array_out_f(float arr[], int dimensione) {
	int i; //dichiaro i
    for (i=0; i<dimensione; i++) {	//ciclo stampa array
        printf("%.2f ", arr[i]);
    }
    printf("\n"); //spazio tra i numeri
    
    return;
}

/*---------/


 /$$$$$$$$ /$$                            /$$$$$$  /$$                          
|__  $$__/|__/                           /$$__  $$| $$                          
   | $$    /$$  /$$$$$$   /$$$$$$       | $$  \__/| $$$$$$$   /$$$$$$   /$$$$$$ 
   | $$   | $$ /$$__  $$ /$$__  $$      | $$      | $$__  $$ |____  $$ /$$__  $$
   | $$   | $$| $$  \ $$| $$  \ $$      | $$      | $$  \ $$  /$$$$$$$| $$  \__/
   | $$   | $$| $$  | $$| $$  | $$      | $$    $$| $$  | $$ /$$__  $$| $$      
   | $$   | $$| $$$$$$$/|  $$$$$$/      |  $$$$$$/| $$  | $$|  $$$$$$$| $$      
   |__/   |__/| $$____/  \______/        \______/ |__/  |__/ \_______/|__/      
              | $$                                                              
              | $$                                                              
              |__/                                                              

                                                                                           
/---------*/ 

/*--------------------------------------------------------------------------------------
	parola_compresa, legge in input una parola compresa in un range di caratteri scelto
----------------------------------------------------------------------------------------*/
void parola_compresa(char parola[], int min, int max) {
    do {
        scanf("%s",parola); // Legge una parola dall'input utente e la memorizza nella variabile 'parola'.
        if (strlen(parola)<min || strlen(parola)>max+1) { // Controlla se la lunghezza della parola è inferiore a 'min' o superiore a 'max+1'.
            printf("ERRORE: Parola inserita non valida!, inserisci una parola di minimo %d e massimo %d caratteri: ", min, max); // Stampa un messaggio di errore specificando i limiti di lunghezza della parola.
        }
    } while (strlen(parola)<min || strlen(parola)>max+1); // Continua il ciclo finché la lunghezza della parola non rientra nei limiti specificati.
    
	return;
}


/*-----------------------------------------------------------------------------------------------
	conta_carattere, Funzione per contare il numero di occorrenze di un carattere in una stringa
-------------------------------------------------------------------------------------------------*/
int conta_carattere(char stringa[], char carattere) {
    int lunghezza=strlen(stringa),conteggio=0;
    
    for (int i = 0; i < lunghezza; i++) {
        if (stringa[i] == carattere) { // Verifica se il carattere corrente è uguale al carattere specifico
            conteggio++;
        }
    }
    
    return conteggio;
}

/*---------/


 /$$$$$$$$ /$$                           /$$$$$$$$ /$$ /$$          
|__  $$__/|__/                          | $$_____/|__/| $$          
   | $$    /$$  /$$$$$$   /$$$$$$       | $$       /$$| $$  /$$$$$$ 
   | $$   | $$ /$$__  $$ /$$__  $$      | $$$$$   | $$| $$ /$$__  $$
   | $$   | $$| $$  \ $$| $$  \ $$      | $$__/   | $$| $$| $$$$$$$$
   | $$   | $$| $$  | $$| $$  | $$      | $$      | $$| $$| $$_____/
   | $$   | $$| $$$$$$$/|  $$$$$$/      | $$      | $$| $$|  $$$$$$$
   |__/   |__/| $$____/  \______/       |__/      |__/|__/ \_______/
              | $$                                                  
              | $$                                                  
              |__/                                                  

                                                                              
/---------*/ 

/*-----------------------------------------------------
	open_file, Apre e ne verifica la corretta apertura
-------------------------------------------------------*/
FILE *open_file (FILE *fd, char *namefile, char *mode){
	fd=fopen(namefile, mode);       // apro il file temperature.txt
    if (fd==NULL) { 					    // verificando che apertura sia andata 	
        printf("ERRORE: Apertura file invalida\n"); // a buon fine. in caso contrario esce 
        exit(-1); 								  // dal programma con codice di errore -1
    }
	return fd;
	
	/*Sintassi:
	
    "r": apre un file per la lettura. Il file deve esistere.
    "w": crea un file vuoto per la scrittura. Se esiste già un file con lo stesso nome, il suo contenuto viene cancellato e 
		 il file viene considerato come un nuovo file vuoto.
    "a": aggiunge al file. Le operazioni di scrittura aggiungono dati alla fine del file. Il file viene creato se non esiste.
    "r+": apre un file per l’aggiornamento (lettura e scrittura). Il file deve esistere.
    "w+": crea un file vuoto per la lettura e la scrittura.
    "a+": apre un file per la lettura e l’aggiunta2.
    
	*/
}

/*-------------------------------------------------------
	close_file, Chiude e ne verifica la corretta chiusura
---------------------------------------------------------*/
void close_file(FILE *fd){
	if(fclose(fd)!=0) {                     // chiude il file verificandone la buona
        printf("ERRORE: Chiusura file invalida\n");	// riuscita, in caso contrario esce dal
        exit(-2); 								   // programma con codice di errore -2
    }
    return;
}

/*


 /$$$$$$$$ /$$                 /$$       /$$ /$$                 /$$$$$    /$$      
|__  $$__/| $$                | $$      |__/| $$                |__  $$   | $$      
   | $$   | $$$$$$$   /$$$$$$ | $$       /$$| $$$$$$$              | $$   | $$$$$$$ 
   | $$   | $$__  $$ /$$__  $$| $$      | $$| $$__  $$ /$$$$$$     | $$   | $$__  $$
   | $$   | $$  \ $$| $$$$$$$$| $$      | $$| $$  \ $$|______//$$  | $$   | $$  \ $$
   | $$   | $$  | $$| $$_____/| $$      | $$| $$  | $$       | $$  | $$   | $$  | $$
   | $$   | $$  | $$|  $$$$$$$| $$$$$$$$| $$| $$$$$$$/       |  $$$$$$//$$| $$  | $$
   |__/   |__/  |__/ \_______/|________/|__/|_______/         \______/|__/|__/  |__/
                                                                                                                                                                    
   
   [https://patorjk.com/software/taag/, Asci art generator]                                                                                  
*/                                                                       
                                                                       
                                                                      


//----/* Informazioni:
/* Autore:	Joel Stephan
   Data:
   Versione: 0				 */
//----------------------------\\

//---------/*	Testo:
/*
Data una stringa s, trova la lunghezza del più lungo 
substring
senza ripetere i personaggi.

 

Esempio 1:

Ingresso: s = "abcabcbb"
Uscita: 3
Spiegazione: La risposta è "abc", con la lunghezza di 3.
Esempio 2:

Ingresso: s = "bbbbb"
Uscita: 1
Spiegazione: La risposta è "b", con la lunghezza di 1.
Esempio 3:

Ingresso: s = "pwwkew"
Uscita: 3
Spiegazione: La risposta è "wke", con la lunghezza di 3.
Si noti che la risposta deve essere una sottostringa, "pwke" è una sottosequenza e non una sottostringa.
 

vincoli:

0 <= s.length <= 5 * 104
sè composto da lettere, cifre, simboli e spazi inglesi.
*/
//----------------------------------\\

//---------/*	Librerie:

	#include    <stdio.h>
	#include    <stdlib.h>
	#include    <string.h>
	#include    <ctype.h>
	#include    <time.h>
	#include    <math.h>

//-----------------------\\

//---------/*	Define:
	#define MAX 128
//---------------------\\

//----/* Funzioni:

// Funzione che cerca un valore in un array dato un intervallo
int cercaVal(char array[], int inizio, int fine, char valore) {
  for (int i=inizio; i<fine; i++) {
    if (array[i]==valore) {
      return 1; // Restituisce 1 se il valore è trovato
    }
  }
  return 0; // Restituisce 0 se il valore non è trovato
}

// Funzione per calcolare la lunghezza della sottostringa più lunga senza caratteri duplicati
int lengthOfLongestSubstring(char * s) {
	int i,j,leng,max,lunghezza; // Dichiaro le variabili
	
	leng=strlen(s); // Calcola la lunghezza totale della stringa
	max=0; // Inizializza la lunghezza massima trovata a 0

	// Ciclo esterno: itera attraverso tutti i caratteri della stringa
	for (i=0; i<leng; i++){
		// Ciclo interno: itera attraverso i caratteri successivi nella stringa
		for (j=i+1; j<=leng; j++){
			// Verifica se ci sono caratteri duplicati nella sottostringa corrente
      		if (s[i]!=s[leng-1-j]){
      			// Se la sottostringa corrente non ha caratteri duplicati,calcola la lunghezza e verifica se è la più lunga finora
        		lunghezza=j-i;
        		
        		if (lunghezza > max) {
          			max=lunghezza; // Aggiorna la lunghezza massima
        		}	   
      		}
			else {
        		break; // Esci dal ciclo interno se trovi un carattere duplicato
			}
   		}
  }

  return max; // Restituisce la lunghezza massima trovata
}



//---------------\\

//----/* Int Main:
int main(){
 //---------/*	Variabili:
	char input[MAX] = "pwwkew";
	int result;
 //-----------------------\\
	
 //---------/*	Algoritmo Risolutivo:
 result = lengthOfLongestSubstring(input);
 printf("La lunghezza della sottostringa piu' lunga senza caratteri duplicati e': %d\n", result);
 //----------------------------------\\

	printf("\n");
	system("PAUSE");
	return 0;
}
	
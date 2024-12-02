//Semplice programma che mostra come si apre un file di testo in lettura e vari modi per leggere testo e numeri da quel file 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define PERCORSO "esempio2.txt"

#define LEN 256

//Legge una riga di testo dal file di testo dato in input. Ritorna 0 se l'operazione è andata a buon fine, 1 se si è raggiunta la fine del file
int leggiStringaDaFile(FILE *f, char s[], int len);

int main(){
    char temp[LEN];
    int n;
    double d;
    FILE *f=fopen(PERCORSO,"r"); //apri il file esempio2.txt in lettura. Si aspetta un file di testo codificato in ASCII
    if(f==NULL){ //file non trovato o accesso negato
        printf("Impossibile aprire il file %s\n",PERCORSO);
        return 0;
    }
    
    //file aperto correttamente, posso iniziare a leggere
    //una volta aperto, posso trattare il file sostanzialmente come se fosse la tastiera
    
    //posso leggere testo con una versione leggermente modificata della leggiStringa
    if(leggiStringaDaFile(f,temp,LEN)){ //errore
        printf("Errore di lettura\n");
    }else{ //ok
        printf("Ho letto \"%s\"\n",temp);
    }
    
    //posso leggere numeri con la fscanf, che funziona come la scanf normale ma ha come primo parametro il file da cui leggere
    fscanf(f,"%d",&n);
    printf("Letto int %d\n",n);
    fscanf(f,"%lf",&d);
    printf("Letto double %lf\n",d);
    //siccome non sappiamo cosa c'è nel file, è poco furbo usare la fscanf (rischio di far crashare il programma se c'è un carattere inaspettato), è meglio leggersi la riga in una stringa e poi usare atof e funzioni simili (magari dopo aver verificato che non sia spazzatura)
    leggiStringaDaFile(f,temp,LEN);
    d=atof(temp);
    printf("Letto double %lf\n",d);
    
    //posso andare avanti a leggere finchè non raggiungo la fine del file (questo esempio stampa le righe una per una col numero di fianco)
    n=1;
    while(leggiStringaDaFile(f,temp,LEN)==0){
        printf("%d\t%s\n",n,temp);
        n++;
    }
    printf("***FINE DEL FILE***\n");
    
    //posso resettare il file e tornare all'inizio
    fseek(f,0,SEEK_SET); //imposta il "cursore" nel file al carattere 0 dall'inizio del file
    //potreste anche usare rewind(f), è la versione old school della stessa cosa
    
    //e così posso rileggerlo in un altro modo se mi serve
    while(1){
        n=fgetc(f); //leggi un carattere dal file (non è un errore che lo metto in un int, la specifica della funzione ritorna int)
        if(n==EOF) break; //se ho raggiunto la fine del file, interrompo il ciclo infinito
        printf("%c",n); //altrimenti stampo il carattere che ho letto
    }
    printf("***FINE DEL FILE***\n");
    
    //quando ho finito di usare il file, lo chiudo
    fclose(f);
    
    //un file può essere aperto in lettura da più applicazioni contemporaneamente, ma da una sola in scrittura
    
    return 0;
    
}

int leggiStringaDaFile(FILE *f, char s[], int len){
    //feof prende in input il file e ritorna 1 se è stata raggiunta la fine del file (e quindi non c'è altro da leggere), 0 altrimenti
    if(feof(f)) return 1; //funzione chiamata su un file dove è già stata raggiunta la fine
    //fgets funziona come al solito, ma anzichè dargli stdin (la tastiera) gli diamo il file. Ritorna NULL se si è verificato un errore o se il file è già finito, per cui la mettiamo direttamente in un if
    if(fgets(s,len,f)){ //lettura ok
        s[strlen(s)-1]='\0'; //come al solito, vogliamo togliere lo \n alla fine della riga
        return 0; //tutto ok
    }else{ //lettura fallita, probabilmente perchè il file è finito
        return 1;
    };
}

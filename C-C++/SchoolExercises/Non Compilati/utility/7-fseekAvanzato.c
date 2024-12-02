/*
 Questo programma mostra come estrarre una parola casuale dal file parole.txt
 Il file contiene un elenco di parole italiane separate da uno \n
 L'idea è di ottenere la dimensione del file, poi spostarsi in un punto a caso nel file, e andare indietro un carattere per volta fino a quando non incontro lo \n della riga prima o l'inizio del file
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define MAXLEN 256

int main(){
    long len;
    char s[MAXLEN];
    FILE* f=fopen("parole.txt","r");
    if(f==NULL){
        printf("Manca il dizionario...");
        return 0;
    }
    srand(time(0));
    //ottengo la dimensione del file
    fseek(f,0,SEEK_END); //mi sposto alla fine del file
    len=ftell(f); //ottengo la posizione del cursore all'interno del file, questo sarà la lunghezza in byte del file
    //scelgo un punto a caso nel file e mi sposto lì
    fseek(f,(long)(len*((float)rand()/(float)RAND_MAX)),SEEK_SET);
    //mi sposto indietro di un carattere per volta fino a quando non raggiungo l'inizio del file o lo \n della parola precedente
    while(ftell(f)>0&&fgetc(f)!='\n'){
        fseek(f,-2,SEEK_CUR); //mi sposto indietro di 2 anzichè di 1 perchè la fgetc mi sposta avanti il cursore di 1
    }
    //a questo punto sono sicuro di essere all'inizio di una parola, posso leggerla con una fscanf (tanto è garantito che sia una parola sola, non ci crea problemi con gli spazi)
    fscanf(f,"%s",s);
    printf("Parola a caso: %s\n",s);
    //chiudo il file e ho finito
    fclose(f);
    return 0;
}

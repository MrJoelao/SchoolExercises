//Semplice programma che mostra come si apre un file di testo in append
//Ogni volta che viene eseguito aggiunge un numero casuale al file random.txt

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int n;
    FILE *f=fopen("random.txt","a"); //tenta di aprire random.txt in append, ossia in scrittura ma se il file esiste già scrive in fondo al file anzichè cancellarne il contenuto
    if(f==NULL){ //fallito
        printf("Errore nell'apertura del file\n");
        return 0;
    }
    //aperto correttamente
    //una volta aperto, un file in append si comporta come un file aperto in scrittura
    
    //genero un numero casuale e lo aggiungo in fondo al file
    srand(time(0));
    n=rand();
    fprintf(f,"%d\n",n);
    
    //come al solito, quando ho finito di scrivere chiudo il file
    fflush(f);
    fclose(f);
    
    return 0;
}

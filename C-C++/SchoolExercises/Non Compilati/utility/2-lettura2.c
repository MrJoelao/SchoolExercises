//Semplice programma che somma tutti i numeri presenti nel file di testo numeri.txt leggendoli con fscanf (non è il modo più intelligente di farlo, quando si lavora coi file di testo è meglio trattarli come testo e poi usare funzioni tipo atoi!)

#include<stdio.h>

#define PERCORSO "numeri.txt"

int main(){
    int n,r,tot=0;
    FILE *f=fopen(PERCORSO,"r");
    if(f==NULL){
        printf("Impossibile aprire il file %s\n",PERCORSO);
        return 0;
    }
    
    while(fscanf(f,"%d",&n)>0){ //fscanf ritorna un valore >0 se ha letto qualcosa, se fallisce ritorna 0 o un negativo
        tot+=n;
    }
        
    printf("Totale: %d\n",tot);
    return 0;
}

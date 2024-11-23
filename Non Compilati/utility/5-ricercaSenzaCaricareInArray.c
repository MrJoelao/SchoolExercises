/*
 Questo programma trova i due prodotti più costosi nel file prodotti.txt
 Il file è troppo grande per essere caricato interamente in un array, per cui leggiamo il file più volte.
*/

#include<stdio.h>
#include<string.h>

#define MAXLEN 256

typedef struct{
    char nome[MAXLEN];
    float prezzo;
} Prodotto;

int main(){
    int r;
    Prodotto p1,p2,temp;
    FILE *f=fopen("prodotti.txt","r");
    if(f==NULL){
        printf("Errore: prodotti.txt non trovato");
        return 0;
    }
    strcpy(p1.nome,"Non trovato");
    p1.prezzo=0;
    strcpy(p2.nome,"Non trovato");
    p2.prezzo=0;
    //cerco il prodotto più costoso nel file e lo copio in p1
    while(fscanf(f,"%s %f",temp.nome,&temp.prezzo)>0){
        if(temp.prezzo>p1.prezzo){
            p1=temp;
        }
    }
    //adesso in p1 ho il prodotto più costoso, torno all'inizio del file e cerco il prodotto più costoso che non sia p1
    fseek(f,0,SEEK_SET);
    while(fscanf(f,"%s %f",temp.nome,&temp.prezzo)>0){
        if(temp.prezzo>p2.prezzo&&strcmp(p1.nome,temp.nome)){
            p2=temp;
        }
    }
    //ho finito, chiudo il file
    fclose(f);
    printf("Prodotti più costosi:\n");
    printf("%s %.2f€\n",p1.nome,p1.prezzo);
    printf("%s %.2f€\n",p2.nome,p2.prezzo);
    return 0;
}

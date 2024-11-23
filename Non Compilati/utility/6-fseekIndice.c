/*
 Questo programma mostra come creare un "indice" di un file di testo per poter saltare con fseek e leggere righe specifiche
*/

#include<stdio.h>
#include<string.h>

#define MAXLEN 256
#define MAXENTRIES 1024

int main(){
    long indice[MAXENTRIES]; //array con le posizioni dell'inizio di ogni riga del file
    long p;
    int nRighe=0;
    int n,r;
    char s[MAXLEN];
    FILE *f=fopen("esempio3.txt","r");
    if(f==NULL){
        printf("Errore\n");
        return 0;
    }
    //leggo il file riga per riga, ogni volta prima di leggere la riga mi segno la posizione nell'array indice
    while(1){
        p=ftell(f);
        if(fgets(s,MAXLEN,f)){
            indice[nRighe]=p;
            nRighe++;
        }else break;
    }
    //adesso l'array indice contiene le posizioni di inizio di ogni riga nel file, posso saltare dove voglio
    while(1){
        printf("Il file contiene %d righe, quale vuoi visualizzare? [0-%d]\n",nRighe,nRighe-1);
        scanf("%d",&n);
        if(n>=0&&n<nRighe){
            fseek(f,indice[n],SEEK_SET); //mi sposto alla posizione che ho salvato nell'indice per la riga n
            fgets(s,MAXLEN,f); //leggo una riga e la stampo (\n incluso)
            printf("Riga %d: %s",n,s);
        }else{
            printf("Fuori dal file\n");
        }
    }
    fclose(f);
    return 0;
}

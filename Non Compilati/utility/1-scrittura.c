//Semplice programma che mostra come si apre un file di testo in scrittura e vari modi per scrivere del testo su quel file

#include<stdio.h>

#define PERCORSO "esempio1a.txt"
#define PERCORSO2 "esempio1b.txt"

void esempio(FILE*);

int main(){
    int i,j;
    
    FILE *f=fopen(PERCORSO,"w"); //apro il file esempio1a.txt in scrittura. Se il file non esiste viene creato, se esiste già viene svuotato. Di default, i file di testo in C usano la codifica ASCII
    if(f==NULL){ //errore nell'apertura del file. Può succedere se non c'è spazio su disco o se l'utente non ha i permessi per scrivere nella cartella corrente
        printf("Errore: impossibile aprire il file %s\n",PERCORSO);
        return 0;
    }
    //file aperto correttamente, posso iniziare a scriverci sopra
    //una volta aperto in scrittura posso "stampare" sul file come se fosse lo schermo
    
    //fprintf funziona esattamente come una normale printf, ma ha come primo parametro il file su cui scrivere l'output
    
    fprintf(f,"Hello world!\n\n");
    
    for(i=1;i<10;i++){
        for(j=1;j<=i;j++){
            fprintf(f,"%d\t",j);
        }
        fprintf(f,"\n");
    }
    
    fprintf(f,"\n");
    
    //un altro modo per scrivere stringhe sul file è fputs
    
    char s[]="Questo testo è scritto con fputs\n";
    
    fputs(s,f); //equivalente a fprintf(f,"%s",s);
    
    //nulla mi vieta di aprire più file contemporaneamente
    FILE *f2=fopen(PERCORSO2,"w");
    if(f2==NULL){ //errore nell'apertura del file
        printf("Errore: impossibile aprire il file %s\n",PERCORSO2);
        return 0;
    }
    //file aperto correttamente, posso iniziare a scriverci sopra
    fputs("Questo è il secondo file\n",f2);
    
    //i file possono essere passati a delle funzioni
    esempio(f2);
    
    //alla fine, prima di chiudere il programma, devo chiudere i file
    
    fflush(f); //mi assicuro che quello che ho scritto su f sia stato effettivamente scritto sul disco
    fclose(f); //e lo chiudo, così possono usarlo altri programmi
    
    //stessa cosa per f2
    fflush(f2);
    fclose(f2);
    
    //se tento di usare f o f2 quì il programma crasha perchè sono già chiusi, ma posso riaprirli se serve
    
    //nota: lo standard unix prevede che tutti i file di testo terminino con una riga vuota, quindi se serve si può stampare uno \n prima di chiudere il file
    
    return 0;
}

void esempio(FILE *f){
    fputs("Questo testo è stato scritto dalla funzione esempio\n",f);
}

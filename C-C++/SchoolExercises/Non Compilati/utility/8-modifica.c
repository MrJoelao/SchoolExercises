/*
 * Questo programma mostra come usare la possibilità di aprire un file sia in lettura che in scrittura usando r+ o w+ per modificare il suo contenuto. In questo caso legge e codifica con il cifrario di cesare il file cesare.txt
*/

#include<stdio.h>
#include<string.h>

#define SHIFT -3
#define PERCORSO "cesare.txt"

#define MAXLEN 256

//Codifica un'intera stringa usando il cifrario di cesare
void cesare(char[]);

int main(){
    char s[MAXLEN];
    int i;
    long ptr;
    FILE *f=fopen(PERCORSO,"r+"); //apro in lettura con la possibilità di scrivere se mi serve. Il cursore all'interno del file si trova all'inizio    
    if(!f){
        printf("Impossibile aprire %s\n",PERCORSO);
        return 0;
    }
    while(1){
        ptr=ftell(f); //salvo la posizione del file (sono all'inizio di una riga)
        if(fgets(s,MAXLEN,f)){ //provo a leggere l'intera riga (\n incluso)
            //ho letto una riga, codifico ogni carattere
            cesare(s);
            //torno all'inizio della riga e la sovrascrivo con quella crittografata. In questo caso non c'è rischio che la lunghezza sia cambiata, scrivendo sovrascriverò solo quella riga. Se s fosse più lunga dell'originale invece sarebbe più complicato
            fseek(f,ptr,SEEK_SET);
            fputs(s,f); //e scrivo s al posto dell'originale
        }else break;
    }
    fflush(f);
    fclose(f);
    printf("%s è stato crittografato\n",PERCORSO);
    return 0;
}

void cesare(char s[]){
    int i, len=strlen(s);
    int temp;
    for(i=0;i<len;i++){
        if(s[i]>='A'&&s[i]<='Z'){
            temp=s[i]-'A'+SHIFT;
            if(temp<0) temp+=26;
            s[i]=temp%26+'A';
        }else if(s[i]>='a'&&s[i]<='z'){
            temp=s[i]-'a'+SHIFT;
            if(temp<0) temp+=26;
            s[i]=temp%26+'a';
        }
    }
}

/*
 Scrivere un programma per gestire una libreria musicale.

 Ogni brano nella libreria ha un titolo, un artista, un album, il genere, l'anno di uscita, e una durata.

 Il programma deve permettere di:
    * Inserire un nuovo brano (CREATE)
    * Visualizzare tutti i brani nella libreria (RETRIEVE)
    * Cercare brani per titolo/artista/album (RETRIEVE)
    * Modificare le informazioni di un brano (UPDATE)
    * Cancellare un brano (DELETE)
    * Cancellare tutti i brani nella libreria (DELETE)
    * Generare casualmente dei brani di test (CREATE)

 */
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

#define LEN 256
#define MAXSONGS 1024

typedef struct{
    char titolo[LEN];
    char artista[LEN];
    char album[LEN];
    char genere[LEN];
    int anno;
    int durata; //in secondi
} Brano;

//OPERAZIONI CRUD
//Legge dall'utente le informazioni su un Brano e ritorna un Brano con le info inserite
Brano nuovoBrano();
//Riempie la collezione con n brani casuali, eliminando quello che c'è già dentro (utile per demo)
void generaBraniCasuali(Brano collezione[], int *nBrani, int n);
//Stampa le informazioni su un Brano dato in input
void stampaInfoBrano(Brano b);
//Visualizza tutti i brani inseriti nel programma
void elencaBrani(Brano collezione[], int nBrani);
//Visualizza tutti i brani inseriti nel programma che contengono la stringa data in input (case insensitive) nel titolo, artista o album
void cercaBrani(Brano collezione[], int nBrani, char daTrovare[]);
//Modifica le informazioni di un Brano dato in input prendendole dall'utente. Il Brano va passato per indirizzo
void modificaBrano(Brano *b);
//Rimuove un Brano dal programma dato il suo id (posizione nell'array). Non fa nulla se l'id non è valido
void cancellaBrano(Brano collezione[], int *nBrani, int id);

//FUNZIONI DA LIBRERIE
int leggiInt(int min, int max);
void leggiStringa(char s[], int len);
int stringaVuota(char s[]);
int trovaInStringa(char s[], char t[]);
void flushInput();
char getCharacter(void);
void premiUnTasto();
void stringaCasuale(char s[], int len);

int main(){
    Brano collezione[MAXSONGS];
    Brano b;
    int nBrani=0;
    int sel;
    char s[LEN];
    srand(time(0));
    while(1){
        printf("Scegli un'operazione:\n\n");
        printf("1. Aggiungi brano\n");
        printf("2. Ricerca brani\n");
        printf("3. Modifica informazioni brano\n");
        printf("4. Cancella brano\n");
        printf("5. Elenco brani\n");
        printf("6. Genera brani casuali\n");
        printf("7. Elimina tutti i brani\n");
        printf("8. Chiudi applicazione\n\n");
        sel=leggiInt(1,8);
        switch(sel){
            case 1:{
                if(nBrani<MAXSONGS){
                    collezione[nBrani]=nuovoBrano();
                    nBrani++;
                    printf("Aggiunto!\n\n\n");
                }else{
                    printf("Errore: database pieno (limite: %d)\n\n\n",MAXSONGS);
                }
                premiUnTasto();
            } break;
            case 2:{
                printf("Cerca per titolo/artista/album: ");
                leggiStringa(s,LEN);
                cercaBrani(collezione,nBrani,s);
                premiUnTasto();
            } break;
            case 3:{
                if(nBrani==0){
                    printf("Nessun brano inserito!\n\n");
                }else{
                    printf("ID del brano da modificare [0-%d, -1 per annullare]: ",nBrani-1);
                    sel=leggiInt(-1,nBrani-1);
                    if(sel>=0){
                        modificaBrano(&collezione[sel]);
                        printf("Salvato!\n\n\n");
                    }
                }
                premiUnTasto();
            } break;
            case 4:{
                if(nBrani==0){
                    printf("Nessun brano inserito!\n\n");
                }else{
                    printf("ID del brano da cancellare [0-%d, -1 per annullare]: ",nBrani-1);
                    sel=leggiInt(-1,nBrani-1);
                    if(sel>=0){
                        cancellaBrano(collezione,&nBrani,sel);
                        printf("Cancellato!\n\n\n");
                    }
                }
                premiUnTasto();
            } break;
            case 5:{
                elencaBrani(collezione,nBrani);
                premiUnTasto();
            } break;
            case 6:{
                printf("Tutti i brani nel programma saranno cancellati!\n");
                printf("Quanti brani vuoi generare? [0-%d, -1 per annullare]: ",MAXSONGS);
                sel=leggiInt(-1,MAXSONGS);
                if(sel>=0){
                    generaBraniCasuali(collezione,&nBrani,sel);
                    printf("Brani inseriti!\n\n\n");
                    premiUnTasto();
                }
            } break;
            case 7:{
                nBrani=0;
                printf("Elenco svuotato!\n\n\n");
                premiUnTasto();
            } break;
            case 8:{
                printf("Ciao ciao!\n\n");
                return 0;
            } break;
        }
    }
}


//CREATE

Brano nuovoBrano(){
    Brano b;
    int min,sec;
    printf("Titolo:\t\t");
    leggiStringa(b.titolo,LEN);
    printf("Artista:\t");
    leggiStringa(b.artista,LEN);
    printf("Album:\t\t");
    leggiStringa(b.album,LEN);
    printf("Genere:\t\t");
    leggiStringa(b.genere,LEN);
    printf("Anno:\t\t");
    scanf("%d",&b.anno);
    printf("Durata (MM:SS):\t");
    scanf("%d:%d",&min,&sec);
    b.durata=min*60+sec;
    return b;
}

void generaBraniCasuali(Brano collezione[], int *nBrani, int n){
    int i;
    Brano b;
    for(i=0;i<n;i++){
        stringaCasuale(b.titolo,rand()%10+5);
        stringaCasuale(b.artista,rand()%10+5);
        stringaCasuale(b.album,rand()%10+5);
        stringaCasuale(b.genere,rand()%10+5);
        b.anno=rand()%50+1970;
        b.durata=rand()%300+100;
        collezione[i]=b;
    }
    *nBrani=n;
}

//FINE CREATE


//RETRIEVE

void stampaInfoBrano(Brano b){
    printf("Titolo:\t\t%s\n",b.titolo);
    printf("Artista:\t%s\n",b.artista);
    printf("Album:\t\t%s\n",b.album);
    printf("Genere:\t\t%s\n",b.genere);
    printf("Anno:\t\t%d\n",b.anno);
    printf("Durata:\t\t%02d:%02d\n",b.durata/60,b.durata%60);
    printf("\n");
}

void elencaBrani(Brano collezione[], int nBrani){
    int i;
    if(nBrani>0){
        for(i=0;i<nBrani;i++){
            printf("ID:\t\t%d\n",i);
            stampaInfoBrano(collezione[i]);
        }
    }else{
        printf("Nessun risultato\n\n");
    }
}

void cercaBrani(Brano collezione[], int nBrani, char daTrovare[]){
    int i, trovato=0;
    for(i=0;i<nBrani;i++){
        if(trovaInStringa(collezione[i].titolo,daTrovare) || trovaInStringa(collezione[i].artista,daTrovare) || trovaInStringa(collezione[i].album,daTrovare)){
            printf("ID:\t\t%d\n",i);
            stampaInfoBrano(collezione[i]);
            trovato=1;
        }
    }
    if(!trovato){
        printf("Nessun risultato\n\n");
    }
}

int stringaVuota(char s[]){
    int i, len=strlen(s);
    for(i=0;i<len;i++){
        if(s[i]!=' '&&s[i]!='\n'&&s[i]!='\t'&&s[i]!='\r') return 0;
    }
    return 1;
}

int trovaInStringa(char s[], char t[]){
    int lenS=strlen(s), lenT=strlen(t);
    int i,j,flag,n=0;
    char ts,tt;
    for(i=0;i<lenS-lenT+1;i++){
        flag=1;
        for(j=0;j<lenT&&flag;j++){
            ts=tolower(s[i+j]);
            tt=tolower(t[j]);
            if(ts!=tt) flag=0;
        }
        if(flag) return 1;
    }
    return 0;
}

//FINE RETRIEVE


//UPDATE

void modificaBrano(Brano *b){
    char temp[LEN];
    int min,sec;
    printf("Titolo [%s]: ",b->titolo);
    leggiStringa(temp,LEN);
    if(!stringaVuota(temp)) strcpy(b->titolo,temp);
    printf("Artista [%s]: ",b->artista);
    leggiStringa(temp,LEN);
    if(!stringaVuota(temp)) strcpy(b->artista,temp);
    printf("Album [%s]: ",b->album);
    leggiStringa(temp,LEN);
    if(!stringaVuota(temp)) strcpy(b->album,temp);
    printf("Genere [%s]: ",b->genere);
    leggiStringa(temp,LEN);
    if(!stringaVuota(temp)) strcpy(b->genere,temp);
    printf("Anno [%d]: ",b->anno);
    leggiStringa(temp,LEN);
    if(!stringaVuota(temp)) b->anno=atoi(temp);
    printf("Durata (MM:SS) [%d:%d]: ",b->durata/60,b->durata%60);
    leggiStringa(temp,LEN);
    if(!stringaVuota(temp)){
        sscanf(temp,"%d:%d",&min,&sec);
        b->durata=min*60+sec;
    }
}

//FINE UPDATE


//DELETE

void cancellaBrano(Brano collezione[], int *nBrani, int id){
    if(id<0||id>=*nBrani) return;
    int i;
    for(i=id;i<*nBrani-1;i++){
        collezione[i]=collezione[i+1];
    }
    (*nBrani)--;
}

//FINE DELETE




//FUNZIONI VARIE DA LIBRERIE
int leggiInt(int min, int max){
    int n;
    do{
        scanf("%d",&n);
    }while(n<min||n>max);
    return n;
}

void leggiStringa(char s[], int len){
    flushInput();
    fgets(s,len,stdin);
    s[strlen(s)-1]='\0';
}

void premiUnTasto(){
    printf("Premi un tasto per continuare\n");
    flushInput();
    getCharacter();
}

void stringaCasuale(char s[], int len){
    int i;
    for(i=0;i<len;i++){
        s[i]=rand()%26+'a';
    }
    s[len]='\0';
}

#ifdef __unix__
#include<stdio_ext.h>
#include<termios.h>
#include<unistd.h>
void flushInput(){
    __fpurge(stdin);
}
char getCharacter(void){
    struct termios oldt,newt;
    int ch;
    tcgetattr(STDIN_FILENO,&oldt);
    newt=oldt;
    newt.c_lflag&=~(ICANON|ECHO);
    tcsetattr(STDIN_FILENO,TCSANOW,&newt);
    ch=getchar();
    tcsetattr(STDIN_FILENO,TCSANOW,&oldt);
    return ch;
}
#endif

#ifdef _WIN32
void flushInput(){
    fflush(stdin);
}
char getCharacter(void){
    return _getch();
}
#endif

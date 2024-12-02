/*
 Questo programma è una versione espansa dell'esempio del database musicale visto negli esercizi sulle struct.
 
 Questa versione salva tutti i dati inseriti su un file di testo ogni volta che si aggiunge/modifica/rimuove un brano, e quando il programma viene avviato i dati vengono caricati da questo file.
 
 Il formato del file di testo è molto semplice: vengono memorizzati il titolo, l'artista, l'album, il genere, l'anno e la durata tutti separati da uno \n, e al termine di ogni brano viene lasciata una riga vuota (\n\n).
 
 Esempio:
 ---INIZIO DEL FILE---
 Pjanoo (Club Mix)
 Eric Prydz
 Pjanoo CD Maxi
 Progressive House
 2008
 451
 
 All Of The Lights
 Kanye West ft. Rihanna, Kid Cudi
 All Of The Lights (Single)
 Hip hop
 2011
 300
 
 ---FINE DEL FILE---

 */
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>

#define LEN 256
#define MAXSONGS 1024

//Il nome del file di testo dove salvare/caricare i brani
#define SALVATAGGIO "musica.txt"

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

//OPERAZIONI SU FILE
//Legge una riga di testo dal file di testo dato in input. Ritorna 0 se l'operazione è andata a buon fine, 1 se si è raggiunta la fine del file
int leggiStringaDaFile(FILE *f, char s[], int len);
//Carica un brano dal file di testo dato in input. Ritorna 0 se l'operazione è andata a buon fine, 1 se si è raggiunta la fine del file. Il brano caricato viene messo nella struct passata per indirizzo
int leggiBranoDaFile(FILE *f, Brano *b);
//Carica tutti i brani dal file di testo SALVATAGGIO. I dati caricati vengono messi direttamente nell'array collezione dato in input assieme alla sua dimensione logica passata per indirizzo. Prende in input anche la dimensione fisica dell'array collezione per non sforare l'array. Se non è possibile caricare il file di testo, inizializza l'array senza brani. Ritorna 1 se è stato possibile caricare da file, 0 altrimenti
int caricaStato(Brano collezione[], int *nBrani, int maxLen);
//Scrive un brano dato in input sul file di testo dato in input
void scriviBranoSuFile(FILE *f, Brano b);
//Salva tutti i brani sul file di testo SALVATAGGIO. Prende in input l'array collezione e la sua dimensione logica. Se il file esiste già viene sovrascritto, se non è possibile creare il file non fa nulla.
void salvaStato(Brano collezione[], int nBrani);

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
    caricaStato(collezione,&nBrani,MAXSONGS); //all'avvio del programma, tento di caricare il database dal file
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
                    salvaStato(collezione,nBrani); //dopo aver aggiunto un nuovo brano, salvo tutto il datbase sul file
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
                        salvaStato(collezione,nBrani); //dopo aver modificato un nuovo brano, salvo tutto il datbase sul file
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
                        salvaStato(collezione,nBrani); //dopo aver cancellato un nuovo brano, salvo tutto il datbase sul file
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
                    salvaStato(collezione,nBrani); //dopo aver generato brani casuali, salvo tutto il datbase sul file
                    printf("Brani inseriti!\n\n\n");
                    premiUnTasto();
                }
            } break;
            case 7:{
                nBrani=0;
                salvaStato(collezione,nBrani); //dopo aver cancellato, salvo tutto il datbase sul file
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

//OPERAZIONI SU FILE

int leggiStringaDaFile(FILE *f, char s[], int len){
    if(feof(f)) return 1; //funzione chiamata su un file dove è già stata raggiunta la fine
    if(fgets(s,len,f)){ //lettura ok
        s[strlen(s)-1]='\0';
        return 0;
    }else{ //lettura fallita, probabilmente perchè il file è finito
        return 1;
    };
}

int leggiBranoDaFile(FILE *f, Brano *b){
    int err;
    char temp[LEN];
    if(feof(f)) return 1; //funzione chiamata su un file dove è già stata raggiunta la fine
    if(leggiStringaDaFile(f,b->titolo,LEN)) return 1; //tenta di leggere il titolo della canzone, se fallisce ritorna 1
    if(leggiStringaDaFile(f,b->artista,LEN)) return 1;
    if(leggiStringaDaFile(f,b->album,LEN)) return 1;
    if(leggiStringaDaFile(f,b->genere,LEN)) return 1;
    if(leggiStringaDaFile(f,temp,LEN)) return 1; //leggi l'anno e mettilo nella stringa temp per essere convertito, se fallisce ritorna 1
    b->anno=atoi(temp);
    if(leggiStringaDaFile(f,temp,LEN)) return 1; //come prima ma per la durata
    b->durata=atoi(temp);
    //da fare: assicurarsi che i valori letti per anno e durata abbiano senso
    //tutto ok, ritorno 0
    return 0;
}

int caricaStato(Brano collezione[], int *nBrani, int maxLen){
    FILE *f;
    int fine=0;
    *nBrani=0;
    char temp[LEN];
    f=fopen(SALVATAGGIO,"r"); //tenta di aprire il file SALVATAGGIO (musica.txt) in lettura
    if(f==NULL){ //non esiste o non è possibile aprirlo, non carico nulla e ritorno
        return 0;
    }else{ //aperto, comincio a caricare
        do{
            fine=leggiBranoDaFile(f,&collezione[*nBrani]); //tenta di leggere un brano dal file di testo, se riesce lo mette nell'array altrimenti la funzione ritorna 1 facendo finire il ciclo
            if(!fine){ //lettura riuscita
                fine=leggiStringaDaFile(f,temp,LEN); //leggo la riga vuota che c'è tra un brano e un altro nel file e la butto via. Se raggiungo la fine del file la funzione ritorna 1 facendo finire il ciclo
                (*nBrani)++; //aumento di 1 la dimensione logica
                if(*nBrani>=maxLen) fine=1; //se l'array è pieno non tento di leggere altro
            }
        }while(!fine);
        //caricamento completato, chiudo il file
        fclose(f);
        return 1;
    }
}

void scriviBranoSuFile(FILE *f, Brano b){
    fprintf(f,"%s\n",b.titolo);
    fprintf(f,"%s\n",b.artista);
    fprintf(f,"%s\n",b.album);
    fprintf(f,"%s\n",b.genere);
    fprintf(f,"%d\n",b.anno);
    fprintf(f,"%d\n",b.durata);
}

void salvaStato(Brano collezione[], int nBrani){
    int i;
    FILE *f=fopen(SALVATAGGIO,"w"); //tenta di aprire il file SALVATAGGIO (musica.txt nella cartella corrente) in scrittura, creandolo se non esiste già, svuotandolo se esiste già
    if(f==NULL){ //non è stato possibile aprire il file, non posso salvare
        return;
    }else{ //file aperto, salvo tutti i brani separati da uno \n
        for(i=0;i<nBrani;i++){
            scriviBranoSuFile(f,collezione[i]);
            fprintf(f,"\n");
        }
        //prima di chiudere il file aspetto che sia stato effettivamente scritto su disco per evitare perdite di dati
        fflush(f);
        fclose(f);
    }
}

//FINE OPERAZIONI SU FILE

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
 

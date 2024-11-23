/*
 Questo programma è una versione espansa dell'esempio 2 che permette di aggiungere, rimuovere e cercare persone memorizzate in un array di struct.
 
 Vengono implementate le operazioni fondamentali che si possono fare su un'array di struct (operazioni CRUD): CREATE, RETRIEVE, UPDATE, DELETE (crea, cerca, modifica, cancella)
 
 Il programma gestisce un elenco di persone (fino a 1000), e permette all'utente di eseguire le seguenti operazioni:
    * Visualizzare l'elenco delle persone (RETRIEVE)
    * Cercare persone per nome/cognome (RETRIEVE)
    * Inserire una nuova persona (CREATE)
    * Modificare una persona (UPDATE)
    * Eliminare una persona (DELETE)
    * Eliminare tutte le persone (DELETE)
 
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAX_STRING 256
#define MAX_PERSONE 1000

typedef struct{
    int g;
    int m;
    int a;
} Data;

typedef struct{
    char nome[MAX_STRING];
    char cognome[MAX_STRING];
    char sesso;
    Data dataNascita;
} Persona;

//Inizializza una Persona con dei dati che non facciano crashare il programma
Persona inizializzaPersona();
//Stampa le informazioni di una persona data in input
void stampaPersona(Persona);
//Stampa l'elenco di tutte le persone col relativo ID. Prende in input l'array di struct e la sua dimensione logica
void stampaPersone(Persona[], int);
//Stampa tutte le persone nell'array di struct che contengono nel nome o nel cognome la stringa cercata. Prende in input l'array di struct, la sua dimensione logica e la stringa da cercare. La ricerca è case insensitive. Ritorna 0 se la ricerca non ha avuto risultati, 1 altrimenti
int cercaPersone(Persona[], int, char*);
//Modifica le informazioni di una Persona passata in input per puntatore. Questa funzione è usata sia quando si crea una nuova persona (per chiedere le informazioni all'utente) sia quando si vuole modificare una persona già esistente
void modificaPersona(Persona*);
//Elimina una Persona dall'array di struct. Prende in input l'array di struct, la sua dimensione logica (per puntatore), e l'id della Persona da eliminare (posizione nell'array). Se l'id non è valido non fa niente
void eliminaPersona(Persona[], int*, int);
//Stampa una Data in formato GG/MM/AAAA
void stampaData(Data);
//Legge da tastiera una data in formato GG/MM/AAAA verificando che sia valida e la ritorna
Data leggiData();
//Legge da tastiera il sesso di una persona (può essere solo m o f, case insensitive) e lo ritorna
char leggiSesso();

//Funzioni varie da libreria
void leggiStringa(char*,int);
int leggiInteroTra(int,int);
void minuscolizza(char*);
void flushInput();

int main(){
    Persona persone[MAX_PERSONE];
    int nPersone=0;
    char temp[MAX_STRING];
    Persona p;
    int sel;
    while(1){
        printf("\n\nStato array: %d/%d\n",nPersone,MAX_PERSONE);
        printf("Cosa vuoi fare?\n");
        printf("1. Visualizza tutte le persone\n");
        printf("2. Cerca per nome/cognome\n");
        printf("3. Nuova persona\n");
        printf("4. Modifica persona\n");
        printf("5. Elimina persona\n");
        printf("6. Elimina tutti i dati\n");
        printf("7. Esci\n\n");
        sel=leggiInteroTra(1,7);
        switch(sel){
            case 1:{ //Visualizza tutte le persone (RETRIEVE)
                if(nPersone==0){
                    printf("Nessuna persona inserita\n");
                }else{
                    stampaPersone(persone,nPersone);
                }
            } break;
            case 2:{ //Cerca per nome/cognome (RETRIEVE)
                if(nPersone==0){
                    printf("Nessuna persona inserita\n");
                }else{
                    printf("Inserisci il nome o il cognome, anche parziale: ");
                    leggiStringa(temp,MAX_STRING);
                    sel=cercaPersone(persone,nPersone,temp);
                    if(!sel) printf("Nessun risultato trovato\n");
                }
            } break;
            case 3:{ //Nuova persona (CREATE)
                if(nPersone==MAX_PERSONE){
                    printf("Array pieno\n");
                }else{
                    persone[nPersone]=inizializzaPersona();
                    modificaPersona(&persone[nPersone]);
                    nPersone++;
                    printf("Inserita\n");
                }
            } break;
            case 4:{ //Modifica persona (UPDATE)
                printf("Inserisci l'ID della persona da modificare [0-%d, -1 per annullare]: ",nPersone-1);
                sel=leggiInteroTra(-1,nPersone-1);
                if(sel!=-1) modificaPersona(&persone[sel]);
                printf("Modificata\n");
            } break;
            case 5:{ //Elimina persona (DELETE)
                if(nPersone==0){
                    printf("Nessuna persona inserita\n");
                }else{
                    printf("Inserisci l'ID della persona da eliminare [0-%d, -1 per annullare]: ",nPersone-1);
                    sel=leggiInteroTra(-1,nPersone-1);
                    eliminaPersona(persone,&nPersone,sel);
                    printf("Eliminata\n");
                }
            } break;
            case 6:{ //Elimina tutte le persone (DELETE)
                nPersone=0; //non è necessario svuotare realmente l'array, basta impostare la dimensione logica a 0
                printf("Dati eliminati\n");
            } break;
            case 7:{ //Esci
                return 0;
            } break;
        }
    }
}

Persona inizializzaPersona(){
    Persona p;
    strcpy(p.nome,"");
    strcpy(p.cognome,"");
    p.sesso='i';
    p.dataNascita.g=1;
    p.dataNascita.m=1;
    p.dataNascita.a=0;
    return p;
}

void stampaPersona(Persona p){
    printf("Nome e cognome: %s %s\n",p.nome,p.cognome);
    printf("Sesso: %s\n",p.sesso=='m'?"Maschio":p.sesso=='f'?"Femmina":"Indefinito");
    printf("Data di nascita: ");
    stampaData(p.dataNascita);
    printf("\n");
}

void stampaPersone(Persona persone[], int len){
    int i;
    for(i=0;i<len;i++){
        printf("ID: %d\n",i);
        stampaPersona(persone[i]);
        printf("\n");
    }
}

int cercaPersone(Persona persone[], int len, char *s){
    /*
     Questa funzione di ricerca può sembrare un po' strana, spieghiamola:
     L'utente può cercare ad esempio "federico dossena"
     Nei dati potrebbe esserci una persona con nome Federico e cognome Dossena, ma sono due stringhe separate, quindi per ogni Persona faccio questo:
        * Unisci nome e cognome in una sola stringa temp e convertila in minuscolo
        * Se la stringa cercata è presente in temp, allora stampo questa Persona
        * Altrimenti provo a unire cognome e nome nella stringa temp e convertirla in minuscolo
        * Se la stringa cercata è presente in temp, allora stampo questa Persona
        * Altrimenti, non stampo questa persona
    In questo modo, se l'utente riuscirà a trovare la persona con nome Federico e cognome Dossena scrivendo "federico dossena", "federico", "FEDERICO", "dossena", "dossena federico", "dosse", ecc.
    Alla fine, la funzione ritorna 1 se ha trovato almeno una persona che rispecchia la stringa cercata, 0 altrimnenti.
    
    Non è comunque una ricerca perfetta, ad esempio non troverebbe "federico  dossena" perchè ci sono due spazi, ma è meglio di una semplice strcmp.
    
    */
    char temp[MAX_STRING*2+1]; //se unisco nome e cognome questa stringa deve essere grande per contenere entrambe più lo spazio in mezzo
    int i, trovato, almenoUno=0;
    minuscolizza(s);
    for(i=0;i<len;i++){
        trovato=0;
        strcpy(temp,persone[i].nome);
        strcat(temp," ");
        strcat(temp,persone[i].cognome);
        minuscolizza(temp);
        if(strstr(temp,s)) trovato=1;
        else{
            strcpy(temp,persone[i].cognome);
            strcat(temp," ");
            strcat(temp,persone[i].nome);
            minuscolizza(temp);
            if(strstr(temp,s)) trovato=1;
        }
        if(trovato){
            almenoUno=1;
            printf("ID: %d\n",i);
            stampaPersona(persone[i]);
            printf("\n");
        }
    }
    return almenoUno;
}

void modificaPersona(Persona* p){
    printf("Nome: ");
    leggiStringa(p->nome,MAX_STRING);
    printf("Cognome: ");
    leggiStringa(p->cognome,MAX_STRING);
    printf("Sesso [m/f]: ");
    p->sesso=leggiSesso();
    printf("Data di nascita [GG/MM/AAAA]: ");
    p->dataNascita=leggiData();
}

void eliminaPersona(Persona persone[], int *len, int id){
    int i;
    if(id<0||id>=*len) return;
    for(i=id;i<*len-1;i++){
        persone[i]=persone[i+1];
    }
    (*len)--;
}

void stampaData(Data d){
    printf("%d/%d/%d",d.g,d.m,d.a);
}

Data leggiData(){
    Data d;
    int maxG;
    while(1){
        flushInput();
        scanf("%d/%d/%d",&d.g,&d.m,&d.a);
        flushInput();
        if(d.g>=1&&d.g<=31&&d.m>=1&&d.m<=12){
            if(d.m==11||d.m==4||d.m==6||d.m==9) maxG=30;
            else if(d.m==2){
                if(d.a%4==0&&d.a%100!=0||d.a%400==0) maxG=29; else maxG=28;
            }else maxG=31;
            if(d.g<=maxG) return d;
        }
        printf("Non valida, riprova: ");
    }
}

char leggiSesso(){
    char temp;
    while(1){
        flushInput();
        scanf("%c",&temp);
        flushInput();
        if(temp=='m'||temp=='M') return 'm';
        if(temp=='f'||temp=='F') return 'f';
        printf("Non valido, riprova: ");
    }
}

//FUNZIONI VARIE DA LIBRERIA

void leggiStringa(char *s, int len){
    flushInput();
    fgets(s,len,stdin);
    s[strlen(s)-1]='\0';
}

int leggiInteroTra(int min, int max){
    int n;
    do{
        flushInput();
        scanf("%d",&n);
        flushInput();
    }while(n<min||n>max);
    return n;
}

void minuscolizza(char *s){
    int i,l=strlen(s);
    for(i=0;i<l;i++){
        s[i]=tolower(s[i]);
    }
}

#ifdef __unix__
#include<stdio_ext.h>
void flushInput(){
    __fpurge(stdin);
}
#endif
#ifdef _WIN32
void flushInput(){
    fflush(stdin);
}
#endif

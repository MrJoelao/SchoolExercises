/*
 Questo programma mostra come si può passare una struct per indirizzo ad una funzione così che possa modificarla.
 
 La struct Persona è composta da nome, cognome, sesso e data di nascita. La data di nascita è a sua volta un'altra struct Data con le sue funzioni per leggerla e stamparla.
 
 Attenzione: quando si passa una struct ad una funzione per copia, sia le variabili che gli array al suo interno vengono copiati! Quando si passa per indirizzo ovviamente no. Questo meccanismo può essere abusato per ritornare array dalle funzioni, cosa normalmente non possibile.
 
*/

#include<stdio.h>
#include<string.h>

#define MAX_STRING 64

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

Persona inizializzaPersona();
void stampaData(Data);
Data leggiData();
void stampaPersona(Persona);
void modificaPersona(Persona*);
char leggiSesso();
void leggiStringa(char*,int);
int leggiInteroTra(int,int);
void flushInput();

int main(){
    Persona p;
    int sel;
    p=inizializzaPersona();
    while(1){
        printf("\n\nCosa vuoi fare?\n");
        printf("1. Visualizza Persona\n");
        printf("2. Modifica Persona\n");
        printf("3. Esci\n\n");
        sel=leggiInteroTra(1,3);
        switch(sel){
            case 1:{
                stampaPersona(p);
            } break;
            case 2:{
                modificaPersona(&p);
            } break;
            case 3:{
                return 0;
            } break;
        }
    }
}

Persona inizializzaPersona(){
    //I campi all'interno di una struct hanno un valore iniziale sconosciuto, questa funzione li inizializza a dei valori "sani" che non facciano crashare il programma se si tenta di stampare la struct
    Persona p;
    //nome e cognome inizializzati con una stringa vuota
    strcpy(p.nome,"");
    strcpy(p.cognome,"");
    //sesso indefinito
    p.sesso='i';
    //data di nascita 1/1/0
    p.dataNascita.g=1;
    p.dataNascita.m=1;
    p.dataNascita.a=0;
    return p;
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

void stampaPersona(Persona p){
    printf("Nome e cognome: %s %s\n",p.nome,p.cognome);
    printf("Sesso: %s\n",p.sesso=='m'?"Maschio":p.sesso=='f'?"Femmina":"Indefinito");
    printf("Data di nascita: ");
    stampaData(p.dataNascita);
    printf("\n");
}

void modificaPersona(Persona* p){
    //p è stato passato per indirizzo, per cui questa funzione può modificare il valore reale della variabile anzichè una copia
    //Attenzione alla notazione: scrivere p->nome è equivalente a scrivere (*p).nome
    printf("Nome: ");
    leggiStringa(p->nome,MAX_STRING);
    printf("Cognome: ");
    leggiStringa(p->cognome,MAX_STRING);
    printf("Sesso [m/f]: ");
    p->sesso=leggiSesso();
    printf("Data di nascita [GG/MM/AAAA]: ");
    p->dataNascita=leggiData();
    printf("Modificato\n");
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

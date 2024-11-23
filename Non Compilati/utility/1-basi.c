/*
 Questo programma mostra come si definisce e utilizza una semplice struct Punto formata da due float x e y.
 
 Vengono implementate delle funzioni per leggere un Punto, stampare un Punto e calcolare la distanza tra due variabili di tipo Punto.
 
 Come qualsiasi variabile, le struct vengono passate per copia da/verso le funzioni.
*/

#include<stdio.h>
#include<math.h>

typedef struct{
    float x;
    float y;
} Punto;

Punto leggiPunto();
void stampaPunto(Punto);
float distanza(Punto,Punto);

int main(){
    Punto p1, p2;
    float d;
    printf("Inserisci le coordinate di un punto in formato x,y: ");
    p1=leggiPunto();
    printf("Inserisci un altro punto in formato x,y: ");
    p2=leggiPunto();
    d=distanza(p1,p2);
    printf("La distanza tra ");
    stampaPunto(p1);
    printf(" e ");
    stampaPunto(p2);
    printf(" è %.2f\n",d);
    return 0;
}

Punto leggiPunto(){
    Punto p;
    scanf("%f,%f",&p.x,&p.y);
    return p;
}

void stampaPunto(Punto p){
    printf("%.2f,%.2f",p.x,p.y);
}

float distanza(Punto a, Punto b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
}

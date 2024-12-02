#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#ifndef LIBRERIA_H
int INTLEGGI (int,int);
float FLOATLEGGI (float,float);
int MCD (int,int);
int MCM (int,int);
int POTENZA (int,int);
int MEDIA (float,int);
int MAX (int,int);
int MIN (int,int);
int PRIMI (int);
int CASUALE (int,int);
int FATTORIALE (int);
int DISPOSIZIONE (int,int);
int COMBINAZIONE (int,int);
#endif

int INTLEGGI (int min,int max){
	int valore;
		if(min<max){
			do{
				scanf("%d",&valore);
				if(valore<min || valore>max){
					printf("Valore non valido\nReinserire il numero: ");
				}
			}while(valore<min || valore>max);
		}
	return valore;
}

float FLOATLEGGI (float min,float max){
	float valore;
		if(min<max){
			do{
				scanf("%f",&valore);
				if(valore<min || valore>max){
					printf("Valore non valido\nReinserire il numero: ");
				}
			}while(valore<min || valore>max);
		}
	return valore;
}

int MCD (int n1,int n2){
	int i,mcd;
		for (i=1; i<=n2; i++){
			if (n1%i==0 && n2%i==0){
				mcd=i;
			}	
		}
	return mcd;
}

int MCM (int n1,int n2){
	int i, j,mcm;
		for (i=1; i<=n2; i++){
			if (n1%i==0 && n2%i==0){
				j=i;
				mcm=(n1*n2)/j;
			}	
		}
		return mcm;
}

int POTENZA (int n1,int n2){
	int pot;
		pot=pow(n1,n2);
	return pot;
}

int MEDIA (float v,int n){
	float vmedio;
		vmedio=v/n;
	return vmedio;
}

int  MAX (int n1,int n2){
	int	max=0;
		if (n1==n2){
			max=0;
		}
		if (n1>n2){
			max=1;
		}
		if (n2>n1){
			max=2;
		}
	return max;
}

int MIN (int n1,int n2){
	int min=0;
		if(n1==n2){
			min=0;
		}
		if(n1<n2){
			min=1;
		}
		if(n2<n1){
			min=2;
		}
	return min;
}

int PRIMI (int n) {
  if (n <= 1) return 0;
  if (n <= 3) return 1;
  if (n % 2 == 0 || n % 3 == 0) return 0;
  int i;
  for (i = 5; i <= sqrt(n); i += 6) {
    if (n % i == 0 || n % (i + 2) == 0) {
      return 0;
    }
  }
  return 1;
}

int CASUALE (int min,int max){
	srand(time(NULL));
	return rand() % (max-min+1)+min;
}

int FATTORIALE (int n){
	int fatt=1,i;
		for(i=1;i<=n;i++){
			fatt=fatt*i;
		}
	return fatt;
}

int DISPOSIZIONE (int n,int k){
	int disp,fatt1=1,fatt2=1,i;
		for(i=1;i<=n;i++){
			fatt1=fatt1*i;
		}
		for(i=1;i<=n-k;i++){
			fatt2=fatt2*i;
		}
		disp=fatt1/fatt2;
	return disp;
}

int COMBINAZIONE (int n,int k){
	int comb,i,fatt1=1,fatt2=1,fatt3=1;
		for(i=1;i<=n;i++){
			fatt1=fatt1*i;
		}
		for(i=1;i<=k;i++){
			fatt2=fatt2*i;
		}
		for(i=1;i<=n-k;i++){
			fatt3=fatt3*i;
		}
		comb=fatt1/(fatt2*fatt3);
	return comb;
}

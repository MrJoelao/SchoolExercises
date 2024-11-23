#include<stdio.h>
#include<math.h>

float distanza (int, int, int, int);
/* date lle coordinate x e y di due punti ne calcola la distanaza
   IN: xa, yq, xb, yb
   OUT: distanza 
*/

int main(){
int x1,x2,y1,y2;
float dis;
printf("inserisci la coordinata x del primo punto: ");
scanf("%d", &x1);
printf("inserisci la coordinata y del primo punto: ");
scanf("%d", &y1);
printf("inserisci la coordinata x del secondo punto: ");
scanf("%d", &x2);
printf("inserisci la coordinata y del secondo punto: ");
scanf("%d", &y2);
dis = distanza(x1,y1,x2,y2); 
printf("la distanza e' di: %.2f", dis);
return 0;
}

// funzioni

float distanza (int xa, int ya, int xb, int yb){
	int salvo, ix = 0, iy = 0, somma; 
	double dist; 
	if(xb<xa){
		//inverto i punti qualora saino stati inseriti al contrario 
		salvo = xa; 
		xa = xb; 
		xb = salvo; 
		
		salvo = yb; 
		ya = yb; 
		yb = salvo; 
	}
		//calcolo la distanza sull'asse delle "x" dei punti
	if(xa < 0 && xb >=0){
		
		while(xa <= xb){
			ix ++; 
			xa ++; 
		}
		
	}
	else if(xa < 0 && xb <0){
		
		ix = -xa + xb; 
	}
	
	else {
		
		ix = xb - xa; 
	}
	
		//calcolo la distanza sull'asse delle "y" dei punti
	if (yb > ya){
		if(ya < 0 && yb >=0){
		
			while(ya <= yb){
				iy ++; 
				ya ++; 
			}
			
	}
			else if(ya < 0 && yb <0){
		
			iy = -ya + yb; 
		}
	
		else {
		
			iy = yb - ya; 
		}
	}
	
	else if (yb < ya){
	
	if(yb < 0 && ya >=0){
		
			while(yb <= ya){
				iy ++; 
				yb ++; 
			}
			
	}
			else if(yb < 0 && ya <0){
		
			iy = -yb + ya; 
		}
	
		else {
		
			iy = ya - yb; 
		}	
	}
	else{
		return ix; 
	}	
	
	ix = pow (ix,2); 
	iy = pow (iy,2); 
	somma = ix + iy; 
	return sqrt(somma); 
}

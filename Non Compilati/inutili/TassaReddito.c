/*
Autore: Joel Stephan
Data: 18/10/22
Versione:0
Testo:
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	//dichiarazione variabili
	int scelta;
	float importo,tassa,importof;
	//algoritmo risolutivo
	printf("1. Guadagno di 0-10k\n2. Guadagno di 10-20k\n3. Guadagno di 20-35k\n4. Guadagno di 35-60k\n5. Guadagno di 60-100k\n6. Guadagno oltre i 100k\nScegliere tra le 6:\n");
	scanf("%d",&scelta);
	
	switch(scelta){
		case 1:
			printf("Sei esentato dal pagamento");
		break;
		
		case 2:
			//inserimento importo
			printf("Immetere il propio reddito:\n");
			scanf("%f",&importo);
			
			//verifica dei dati
			if(importo>9999 && importo<20001){
				
			//calcolo
			tassa=importo/100*12;
			importof=importo-tassa;
			
			//output
			system ("cls"); 
			printf("|Fascia scelta: %d|\n\nDati pagamento: \nReddito: \t %.2f Eur.\nTasse pagate: \t %.2f Eur.\nReditto lordo: \t %.2f Eur.\n",scelta,importo,tassa,importof);
			}
			else{
			printf("Importo inserito troppo alto/basso per la fascia scelta"); }
		break;
		
	case 3:
			//inserimento importo
			printf("Immetere il propio reddito:\n");
			scanf("%f",&importo);
			
			//verifica dei dati
			if(importo>19999 && importo<35001){
				
			//calcolo
			tassa=importo/100*18;
			importof=importo-tassa;
			
			//output
			system ("cls"); 
			printf("Con un reddito di %.2f Eur. paghi di tasse %.2f Eur. con un reditto lordo di %.2f Eur.",importo,tassa,importof);
			}
			else{
			printf("Importo inserito troppo alto/basso per la fascia scelta"); }
		break;
		
	case 4:
			//inserimento importo
			printf("Immetere il propio reddito:\n");
			scanf("%f",&importo);
			
			//verifica dei dati
			if(importo>34999 && importo<60001){
				
			//calcolo
			tassa=importo/100*27;
			importof=importo-tassa;
			
			//output
			system ("cls"); 
			printf("Con un reddito di %.2f Eur. paghi di tasse %.2f Eur. con un reditto lordo di %.2f Eur.",importo,tassa,importof);
			}
			else{
			printf("Importo inserito troppo alto/basso per la fascia scelta"); }
		break;
		
	case 5:
			//inserimento importo
			printf("Immetere il propio reddito:\n");
			scanf("%f",&importo);
			
			//verifica dei dati
			if(importo>59999 && importo<100001){
				
			//calcolo
			tassa=importo/100*48;
			importof=importo-tassa;
			
			//output
			system ("cls"); 
			printf("Con un reddito di %.2f Eur. paghi di tasse %.2f Eur. con un reditto lordo di %.2f Eur.",importo,tassa,importof);
			}
			else{
			printf("Importo inserito troppo alto/basso per la fascia scelta"); }
		break;
		
	case 6:
			//inserimento importo
			printf("Immetere il propio reddito:\n");
			scanf("%f",&importo);
			
			//verifica dei dati
			if(importo>99999){
				
			//calcolo
			tassa=importo/100*60;
			importof=importo-tassa;
			
			//output
			system ("cls"); 
			printf("Con un reddito di %.2f Eur. paghi di tasse %.2f Eur. con un reditto lordo di %.2f Eur.",importo,tassa,importof);
			}
			else{
			printf("Importo inserito troppo alto/basso per la fascia scelta"); }
		break;
		
	default:
		//oltre alla scelta 6 output di errore
			printf("Scelta non valida");
		break;}

	printf("\n");
	system("PAUSE");
	return 0;
}

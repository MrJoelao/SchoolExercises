#include <stdio.h>
#include <stdlib.h>



int main(int argc, char *argv[]) {
	float resto;
	int num, base=2;
	
	printf("Inserire un numero: ");
	scanf("%d",&num);
	
	int ndec = 0;
	int i;
	system("cls");
	printf("Numero inserito : %d\n\n", num);
	printf("NUM BINARIO\t\tRESTO\n\n");
	
	do{
		resto=num%10;
		num = num / 10;
		printf("%d\t\t\t%d\n",num,resto);
		if(resto >= base){
			printf("Errore in input\n");
			ndec = -1;
			break;
		}
		ndec = ndec + resto* pow(base, ++i);
		printf("Valore di i = %d\n", i);
		
	}while(++num != 0);
	printf("Numero in base(10) = %d\n", ndec);
	
	
	return 0;
}
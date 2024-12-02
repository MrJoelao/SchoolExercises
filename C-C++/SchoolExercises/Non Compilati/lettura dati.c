/*
testo: Siano dati due file contenenti testo. Si realizzi un programma che individui e scriva un terzo file "risultati.txt" le parole che compaiono in entrambi i file.
alunno:
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int i1,j1;
int i2,j2;
char ch;
FILE *f1;
FILE *f2;
FILE *risultati;
char parolefile1[1000][15];
char parolefile2[1000][15];
char parolecomuni[1000][15];

FILE *open_file (FILE *fd, char *namefile, char *mode){
	fd=fopen(namefile, mode);
    if (fd==NULL) { 					    
        printf("ERRORE: Apertura file invalida\n");
        exit(-1); 							
    }
	return fd;
}

void close_file(FILE *fd){
	if(fclose(fd)!=0) {                     
        printf("ERRORE: Chiusura file invalida\n");	
        exit(-2); 								   
    }
    return;
}

void dividiparole1(){
	
	ch=fgetc(f1);
	i1=0;
	j1=0;
	while(ch!=EOF){
		if (ch!=' '){
		parolefile1[i1][j1]=ch;
		j1++;

		}else{
			i1++;
			j1=0;
		}
		ch=fgetc(f1);
	}

printf ("Il file 1 contiene %d parole\n", i1);
}

void dividiparole2(){
	
	ch=fgetc(f2);
	i2=0;
	j2=0;
	while(ch!=EOF){
		if (ch!=' '){
		parolefile2[i2][j2]=ch;
		j2++;

		}else{
			i2++;
			j2=0;
		}
		ch=fgetc(f2);
	}

printf ("Il file 2 contiene %d parole\n", i2);
}


void cercaparolecomuni(){
int uguali; 

	printf ("\n\nSONO LA FUNZIONE CERCA PAROLE COMUNI\n\n");
	
	printf ("i1 vale %d\n", i1);
	printf ("i2 vale %d\n", i2);
	
	printf ("\nStampo il contenuto di parolefile1\n");
for (int h=0; h<=i1;h++){
		printf ("%s ", parolefile1[h]);
	}
	
	printf ("\nStampo il contenuto di parolefile2\n");
for (int h=0; h<=i2;h++){
		printf ("%s ", parolefile2[h]);
	}

for (int a=0; a<=i1; a++)
{
	for (int b=0; b<=i2; b++)
	{
		uguali=strcmp(parolefile1[a], parolefile2[b]);
		if (uguali==0)
		{
			
			printf ("\nho trovato una parola comune: %s=%s\n", parolefile1[a],parolefile2[b]);
			printf ("inserisco la parola %s in risultati.txt\n", parolefile1[a]);
			risultati=fopen("risultati.txt", "a");
			fprintf(risultati, "%s", parolefile1[a]);
			fprintf(risultati, "%s", "\n");
		
			close_file (risultati);
			
		}
	}	
}





}

int main () {
int h;
	
	//apro il file 1 e trasferisco le parole dentro all'array parolefile1
	
	f1=fopen("f1.txt", "r");
	dividiparole1();
	close_file (f1);
	
	//apro il file 2 e trasferisco le parole dentro all'array parolefile2
	
	f2=fopen("f2.txt", "r");
	dividiparole2();
	close_file (f2);
	
	printf ("chiamo la funzione cerca parole comuni");
	cercaparolecomuni();
	
	

	
	printf ("\n");
	system("PAUSE");
	return 0;
}
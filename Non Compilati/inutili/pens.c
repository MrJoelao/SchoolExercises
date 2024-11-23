/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <stdio.h>
#include <assert.h>

// constraints
#define MAXN 1000000

// input data
int N, i,somma=0,sp,tmp0=0,contaSenzaPenne=0;
int pens;

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d",&N);
	scanf("%d",&pens);
    for(i=1; i<N; i++){
    	tmp0=pens;
        scanf("%d",&pens);
        if(tmp0>1 || pens>1){
        	if(pens>1){
				pens=pens-1;
				tmp0=tmp0+1;
			}
			else{
				tmp0=tmp0-1;
				pens=pens+1;
			}
        
		}
		else{
			contaSenzaPenne=contaSenzaPenne+1;
		}	
		printf("fine\n");
	}
    
    printf("%d\n",contaSenzaPenne);
    return 0;
}

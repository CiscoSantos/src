#include <stdio.h>
#include <stdlib.h>

int digital_root(int n) {
    // .....
  int numer, deno, quoc, rest, temp;
  deno = 10;
  int dezenas[1000];
  int indice=0;
  numer = n;
  int root =0;
  int condicao=1;
  if (numer > 10){
     while(numer > 10){
  	for(int i=0; i <= indice;i++){
		dezenas[i]=0;			
	}
	indice=0;
	root=0;
	while (numer >= 10){
		dezenas[indice] = numer % deno;
		  numer = numer/10;
 	  	  printf("%d,  %d   ,\n",numer, dezenas[indice]);
 	  	  indice++;
		  if (numer<10){
 	  	     dezenas[indice]= numer;
 	  	  }
 	    }
     	    for (int i=0;i <= indice;i++){
		printf("\nvalor_root_parcial%d\n",root);
	    	root = dezenas[i] + root;
	    }
	    printf("\nvalor_root_final: %d\n",root);

	    if(root < 10 ){
		condicao=0;
		return root;	
	    }
	    if(root == 10){
	    	condicao=0;
		return 1;
	    }
	    else{
	   	numer = root;

	   }
     }
 }
  else{
    return numer;
  }
}


int main(void)
{
	int numero=2147483647,novo=0;
	novo=digital_root(numero);
	printf("\nSaida final:%d\n",novo);
	return 0;
}




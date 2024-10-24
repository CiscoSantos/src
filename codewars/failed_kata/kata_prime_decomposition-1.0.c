#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int calc_prime(int numero)
{
        int is_prime=true;
        for(int i=2; i<numero;i++)
        {
                if( (numero != 2) && (numero % i == 0) ) is_prime=false;;
        }
        return is_prime;
}

//int prime_counter(int number)
//{
//	int p_counter=0;
//	for(int j=1;j<=number;j++)
//	{
//		if(calc_prime(j)) 
//		{
//			p_counter++; 
//		}
////		printf(" %d - %d\n" ,j,p_counter);
//	}
//	return p_counter;
//}

//char* factors(int lst) {
int factors(int lst) {
	
//	printf("Numero a ser decomposto: %d\n",lst);
	int counter = lst/2;
	printf("Quantidade de numeros primos: %d\n",counter);
	bool divisivel;
	int* vec = malloc(counter*sizeof(int));
	int temp = lst;
//	printf("%d",prime_counter);
	for(int i=2;i<=lst;i++)
	{
		vec[i]=0;
		if(calc_prime(i))
		{	
			divisivel=true;
			do
			{	
				if((temp % i) == 0 )
				{
					printf("%d divisivel por %d \n;",temp,i);
					temp = temp/i;
					vec[i]=vec[i]+1;
				}
				else
				{
					divisivel = false;
				}
			}while(divisivel==true);
		
		}
	}
	
	for(int k=0; k<=counter;k++)
	{
		if(vec[k]!=0){
			printf("\n %d - %d ",k,vec[k]);
		}
	}
	
	return 0;


}


void main()
{
	//char* answ;
	int answ,num;
	printf("Numero a ser processado: ");
	scanf("%d",&num);
	answ = factors(num);
	

}


/* Exemplo de resposta 1
#include <math.h>
#include <stdio.h>

int divide(int* n, int d) {
  int c = 0;
  while (*n % d == 0) {
    *n /= d;
    ++c;
  }
  return c;
}

char* factors(int n) {
  char* s = malloc(64 * sizeof(char));
  char* e = s + 64;
  char* b = s;
  for (int d = 2; d <= n; ++d) {
    int c = divide(&n, d);
    if (c == 0) continue;
    b += c > 1 ? snprintf(b, e - b, "(%d**%d)", d, c)
               : snprintf(b, e - b, "(%d)", d);
  }
  return s; 
  }
 
 -------------------------------------------------
 Exemplo de resposta 2
 
 #include <stdlib.h>
#include <stdio.h>

char* factors(int lst) {
  char* out = calloc(100,sizeof(char));
  int counter;
  for (int i =2;i<=lst;i++){
    counter=0;
    while(lst%i==0){
      counter++;
      lst/=i;
      }
    if (counter>1) sprintf(out,"%s(%i**%i)",out,i,counter);
    else if (counter==1) sprintf(out,"%s(%i)",out,i);
    }
  return out;
}
 
 
 
 * */



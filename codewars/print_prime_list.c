#include <stdio.h>
#include <stdbool.h>

int calc_prime(int numero)
{	
	int verdadeiro=1;
	for(int i=2; i<numero;i++)
	{
		if( (numero != 2) && (numero % i == 0) ) verdadeiro=0;
	}
	return verdadeiro;


}

void main()
{
	int lst=0;
	int prime_counter=0;
	printf("\nDigite o numero a ser procesado: ");
	scanf("%d",&lst);
        for(int j=1;j<=lst;j++)
        {
                if(calc_prime(j))
		{ 
			prime_counter++;
			printf(" %d ",j );
		}
        }
	printf("\nNumero de primos: %d ",prime_counter);
	
}

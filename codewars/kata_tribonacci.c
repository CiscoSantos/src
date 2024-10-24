#include <stdlib.h>
#include <stdio.h>

long long *tribonacci(const long long signature[3], size_t n) {

  
	long long * lista = malloc ((n + 3) * sizeof(long long) );
	lista[0] = signature[0];
	lista[1] = signature[1];
	lista[2] = signature[2];
//	for(int i=0; i <3;i++)
//	{
//		printf("---- %lld ----",lista[i]);
//	}
	for(int i=3;i<n;i++)
	{
		lista[i] = lista[i-1]+lista[i-2]+lista[i-3];
	}
	for(int i=0; i <n;i++)
	{
		printf(", %lld",lista[i]);
	}
  	printf("\n");
  
  
}


long long *tribonacci(const long long signature[3], size_t n);

int main (void)
{
	const long long signature[3] = {0, 0, 1};
	tribonacci(signature,10);


}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>



long long thirt(long long n)
{	
	int temp = n;
	int fator;
	int resto =0;
	for(int i=1;i<n;i++){
		fator = i;
		resto = temp % 10;
		temp = (temp - resto)/10;
		if (temp == 0) break;
	}
	temp = n;	
	int* div = malloc(fator*sizeof(int));
	int* seq1 = malloc(fator*sizeof(int));
	for(int i=1; i<=fator ;i++){
		resto = temp % 10;
		div[i-1] = resto;
		temp = (temp - resto)/10;
		if (temp == 0) break;
	}
	int seq2[6] = {1, 10, 9, 12, 3, 4};
	int cont = fator;
	do{
		for(int j=0; j<6;j++)
		{
			seq1[fator-cont]=seq2[j];
			cont--;
			if(cont==0) break ;
		}
	}while(cont>0);
	long soma = 0;
	long volta = 0;
        for(int i=0; i<fator;i++)
        {
                soma=soma + div[i]*seq1[i];

        }
	long temp2;
	if(soma==n)
	{
		return soma;
	}
	else
	{
		 temp2 = thirt(soma);
		 return temp2;
	}
}


void main(){

	long saida;
	saida = thirt(1219890);
	printf("\nSaida:%d \n",saida);
	saida =	thirt(8529);
	printf("\nSaida:%d \n",saida);
	saida =	thirt(85299258);
	printf("\nSaida:%d \n",saida);
	saida =	thirt(5634);
	printf("\nSaida:%d \n",saida);
	saida =	thirt(1111111111);
	printf("\nSaida:%d \n",saida);
	saida =	thirt(987654321);
	printf("\nSaida:%d \n",saida);

}

/* Melhor resposta 
 *
long long thirt(long long n)
{
    int remainders[6] = {1, 10, 9, 12, 3, 4};
    int iRem = 0;
    long long m = n, sum = 0;
    
    while (n > 0)
    {
      sum += (n % 10) * remainders[iRem++];
      n /= 10;
      if (iRem >= 6) iRem = 0;
    }
    
    return (sum == m)?(m):(thirt(sum));
}
 *
 *  "?:"  é um operador de expressão condicional " '?X:Y' If Condition is true ? then value X : otherwise value Y"

 *
 */




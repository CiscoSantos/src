#include <stdio.h>


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
	int primo;
	int continua = 0;
	do
	{
		printf("Digite o numero a ser testado: ");
		scanf("%d",&primo);
		primo = calc_prime(primo);
		if(primo == 0 ) printf("\nNão é primo!\n");
		if(primo == 1 ) printf("\nÉ primo!\n");
		printf("\nContinua?");
		scanf("%d",&continua);
	}while(continua == 0);

}

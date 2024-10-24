#include <stdio.h>

int main(void)
{
	int lista[] = {1,2,3,4,5,6,7,8,9,10};
	int *lista_ptr = lista;
	for(int i = 0;i<10;i++)
	{
		printf("\nLista: %p - Ponteiro: %p",&lista[i],lista_ptr+i);
	}
	printf("\n");
	double lista2[] = {1,2,3,4,5,6,7,8,9,10};
	double *lista2_ptr = lista2;
	for(int i = 0;i<10;i++)
	{
		printf("\nLista: %p - Ponteiro: %p",&lista2[i],lista2_ptr+i);
	}
	printf("\n");
	char lista3[] = {'1','2','3','4','5','6','7','8','9','0'};
	char *lista3_ptr = lista3;
	for(int i = 0;i<10;i++)
	{
		printf("\nLista: %p - Ponteiro: %p",&lista3[i],lista3_ptr+i);
	}
	printf("\n");
	
	

	int inteiro = 0;
	int *inteiro_ptr = &inteiro;
	printf("\n %d , %d , %p , %p \n",inteiro,*inteiro_ptr,inteiro_ptr,&*inteiro_ptr);

}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int processa(int *arr1, int size1, int *arr2, int size2)
{
	int total=size1;
/*	for(int i=0;i<size1;i++)
	{
		printf("%d\n",arr1[i]);
	}
*/	
	int* lista = (int *) malloc(sizeof(int) * size1);
	int k = 0;
	
	bool inedito = true;
	for(int i=0;i<size2;i++)
	{
		for(int j=0;j<size1;j++)
		{
			if(arr1[j] == arr2[i])
			{
				total--;
				inedito = false;
			}
		}
		if(inedito==true)
		{
			lista[k]=arr2[i];
			k++;
		}
		else
		{
			inedito = true;
		}
	}
	printf("Total: %d\n",total);
	for(int h=0;h<size1;h++)
	{
		printf("%d - ",lista[h]);
	}
	printf("\n");
}



int main(void)
{
	const int arr1[12] = {1, 2, 2, 2, 2, 2, 4, 5, 7, 9, 11, 14};
	const int arr2[4] = {1, 2, 3, 14};
	const int expected[1] = {2};    
	processa(arr1, 12, arr2, 4);
}

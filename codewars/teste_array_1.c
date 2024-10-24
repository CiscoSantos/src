#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int processa(int *arr1, int n1, int *arr2, int n2)
{
	int total=n1;
/*	for(int i=0;i<n1;i++)
	{
		printf("%d\n",arr1[i]);
	}
*/	
	int* lista = (int *) malloc(sizeof(int) * n1);
	int k = 0;
	
	bool inedito = true;
	for(int i=0;i<n1;i++)
	{
		for(int j=0;j<n2;j++)
		{
			if(arr2[j] == arr1[i])
			{
				total--;
				inedito = false;
			}
		}
		if(inedito==true)
		{
			lista[k]=arr1[i];
			k++;
		}
		else
		{
			inedito = true;
		}
	}
	printf("Total: %d\n",total);
	for(int h=0;h<total;h++)
	{
		printf("%d - ",lista[h]);
	}
	printf("\n");
}



int main(void)
{
	const int arr1[12] = {1, 2, 2, 2, 2, 2, 4, 5, 7, 9, 11, 14};
	const int arr2[5] = {1, 2, 7, 3, 14};
	const int expected[1] = {2};    
	processa(arr1, 12, arr2, 5);
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


int calc_y(int x)
{
	int y = 2 * x +1;
	return y;
}

int calc_z(int x)
{
	int z = 3 * x + 1;
	return z;
}



void sort_array(int* array,int index)
{
	index--;
//	printf("\n%d",index);	
	for(int i=0;i<index;i++){
		//printf("(%d %d)",array[i],array[i+1]);
		if(array[i] > array[i+1]){
			int temp = array[i+1];
		       	array[i+1] = array[i];
			array[i] = temp;
			i=0;	
		}
		
	}	
	printf("\n");
	for(int i=0;i<=index;i++){
		printf("%d -",array[i]);
	}
}

bool exist_already(int* vetor,int numero, int indice)
{	
	indice--;
	for(int i=0;i<indice;i++){
//		printf("- %d/%d - ",numero,vetor[i]);
		if(numero == vetor[i])
		{
			return false;
		}
	}
	return true;

}


int dblLinear(int n)
{
//	int n = 10;	
	int* valor = malloc((n*3)*sizeof(int));
	valor[0]=1;
	int indice=1;
	for(int i = 0; i<n ;i++){
		valor[indice] = calc_y(valor[i]);
		indice++;
		valor[indice]= calc_z(valor[i]);
		indice++;
		sort_array(valor,indice);
	}
	

}


int main(){
	
	dblLinear(10);
	dblLinear(20);
	return 0;

}

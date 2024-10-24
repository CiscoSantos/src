#include <stdio.h>
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
	for(int i=0;i<index;i++){
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
		if(numero == vetor[i])
		{
			return false;
		}
	}
	return true;

}


int dblLinear(int n)
{
	int* valor = malloc((n*3)*sizeof(int));
	valor[0]=1;
	int indice=1;
	for(int i = 0; i<n ;i++){
		int ypsilon = calc_y(valor[i]);
		bool test = exist_already(valor,ypsilon,indice);
		if(test){
			valor[indice] = ypsilon;
			indice++;
		}
		int zee = calc_z(valor[i]); 		
		test = exist_already(valor,zee,indice);
		if(test){
			valor[indice]= zee;
			indice++;
		}
		sort_array(valor,indice);
	}
	return(valor[n]);
	

}


int main(){
	
	printf("\n@@%d@@\n",dblLinear(10));
	//printf("\n@@%d@@\n",dblLinear(20));
	printf("\n@@%d@@\n",dblLinear(30));
	//printf("\n@@%d@@\n",dblLinear(50));
	printf("\n@@%d@@\n",dblLinear(10000));
	return 0;

}

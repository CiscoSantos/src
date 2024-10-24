#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int* mat[] = {{1,2,3},{4,5,6},{7,8,9}};
	for(int i = 0; i<3; i++)
	{
		for(int j; j < 3; j++)
		{
			printf("%d",mat[i][j]);
		}
		printf("\n");	
	}
}

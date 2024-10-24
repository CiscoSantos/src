#include <stdio.h>
#include <math.h>
#include <stdlib.h>



//int multi(int* dev,int* seq,int conta)
//{
//	int* nova= malloc(conta*sizeof(int));
//	for(int i=0; i<conta;i++)
//	{
//		
//	
//	}
//
//
//}



long long thirt(long long n)
{	
	int temp = n;
	int fator;
	int resto =0;
	for(int i=1;i<n;i++){
		fator = i;
		resto = temp % 10;
		temp = (temp - resto)/10;
		printf("Numero temp: %d;  Numero resto: %d;\n",temp,resto);
		if (temp == 0) break;
	}
	temp = n;	
	printf("Numero: %d;  Numero de dezenas: %d;\n",n,fator);
	int* div = malloc(fator*sizeof(int));
	int* seq1 = malloc(fator*sizeof(int));
	for(int i=1; i<=fator ;i++){
		resto = temp % 10;
		div[i-1] = resto;
		temp = (temp - resto)/10;
		printf("Numero valor div: %d; Numero temp: %d;\n",div[i-1],temp);
		if (temp == 0) break;
	}
	int seq2[6] = {1, 10, 9, 12, 3, 4};
	
	int cont = fator;
	do{
		for(int j=0; j<6;j++)
		{
			seq1[fator-cont]=seq2[j];
		//	printf(" %d ",seq1[cont]);	

			cont--;
			if(cont==0) break ;
		}
	}while(cont>0);

	for(int i=0; i<fator ;i++)
	{
		printf(" %d ",div[i]);	
	}
	printf("\n");


}


void main(){


//	thirt(1219890);
	thirt(8529);
//	thirt(85299258);
//	thirt(5634);
//     	thirt(1111111111);
//	thirt(987654321);

}

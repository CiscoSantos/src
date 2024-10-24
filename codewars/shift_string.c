#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char *encrypt_this(const char *str)
{
	int cont = 0;
	while(str[cont] != '\0')
	{
		cont++;
	}
	printf("\n%d\n",cont);
	
	int i = 0;
	int first_letter;
	bool first = true;
	char temp1,temp2;
	
	while(str[i] != '\0' )
	{
		for(int j = i;j<cont;j++ )
		{
			temp1 = str[j];
			temp2 = str[j+1];
			str[j+1] = temp1;
			temp1=temp2;
					
		}
		if(first == true)
		{
			str[i]=" ";
		}	

	
	}
/*	int cont = 0;
	int first_letter;
	bool first = true;
	while(str[cont] != '\0')
	{	
		if(str[cont] == ' ')
		{
			cont++;
			first=0;
		}	
		if(first==true)
		{
			first_letter = str[cont];
			first = false;
			printf("%d",first_letter);
		}
		printf("%c",str[cont]);
		cont++;
	}
	printf("\n");*/
}

char *get_asc(const char *str)
{
//	int asc = str[0];
//	printf("Asc = %d\n",asc);
//	char letra[3];
//	int conta = 0;
//	int resto = 0;
//	do
//	{	
//		resto = asc % 10;
//		letra[conta] = 48 + resto;
//		asc = (asc - resto) / 10;
//		conta++;
//	}while(asc>0);
//	if (conta==2)
//	{
//		letra[3]= '\0';
//	}
//	printf("\n%c%c%c\n",letra[2],letra[1],letra[0]);
}


void main()
{
	encrypt_this(""); //== "72olle"
	encrypt_this("Hello"); //== "72olle"
	encrypt_this("good"); //== "103doo"
	encrypt_this("hello world"); //== "104olle 119drlo"
}


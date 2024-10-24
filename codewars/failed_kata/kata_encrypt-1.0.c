#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

char *encrypt_this(const char *str)
{
	int cont = 0;
	int first_letter;
	bool first = true;
	while(str[cont] != '\0')
	{	
		if(str[cont] == ' ')
		{
			printf("%c",str[cont]);
			cont++;
			first=true;
		}	
		if(first==true)
		{
			first_letter = str[cont];
			first = false;
			printf("%d",first_letter);
		//	continue;
		}
		else
		{
		printf("%c",str[cont]);
		cont++;
		}
	}
	printf("\n");
}


void main()
{
	encrypt_this(""); //== "72olle"
	encrypt_this("Hello"); //== "72olle"
	encrypt_this("good"); //== "103doo"
	encrypt_this("hello world"); //== "104olle 119drlo"
}


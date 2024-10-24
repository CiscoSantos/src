#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* vertMirror(char* strng) {
	
	int n = 0;
	int lenght = strlen(strng);
	printf("\ntamanho strng:%d\n",lenght);
	int line = 0;
	int column = 0;
	char* s_saida = malloc(lenght);
	
	
	printf("\n\n%d\n\n%d\n",strlen(s_saida));
	
	for(int i=0;i<lenght;i++){
		n++;
		char temp = strng[i];
		if( temp == 10  ) break;
	}
	
	printf("\n%s\n",strng);

	for(int i=0;i<=lenght;i++)
	{	
		printf("\n(i==%d)",i);
		column++;
		if( column == n  )
		{
			for(int j=1;j<=n;j++)
			{
				//if(i==lenght) s_saida[i]='\0';
				char temp;
			        strcpy(temp,strng[i-j]);
				if (i ==0 )
				{
				       	strcpy(s_saida,temp);
				}
				strcat(s_saida,temp);
			//	s_saida[line*n+j]=strng[i-j];
			//	printf("%c",s_saida[line*n+j]);
			}
			line++;
			column=0;
			//printf("\n\n%d\n\n%d\n",strlen(s_saida));
		}
	}

//	for(int i=0;i < strlen(s_saida);i++)
//	{
//		printf("O valor de s_saida[%d]=%c\n",i,s_saida[i]);
//	
//	}
//	char* s_saida = strng;
//	printf("\n%s",strng);
	printf("\n\n%d\n\n%d\n",strlen(s_saida));
		
	return s_saida;
}
char* horMirror(char* strng) {


	return "a";
}
typedef char* (*generic_func_t) (char*);
char* oper(generic_func_t f, char* s) {
    
}


int main(void)
{
	
	char* s_string = "abcd\nefgh\nijkl\nmnop";
	vertMirror(s_string);
//	printf("\n",vertMirror(s_string));
//	printf("\n%s",horMirror(s_string));




}


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int testa_str(const char *frase)
{
	return strlen(frase);

}

int testa_str2(const char *frase,const char *frase2)
{
	printf("%c",*frase);
	printf("%c",*(frase+1));
	printf("%c",*(frase+2));
	printf("%c",*(frase+3));
	printf("%c",*(frase+4));
	printf("%c",*(frase+5));

}

/*
int comp_str(const char *full_text, const char *search_text)
{
	int conta = 0;


}*/
int search_substr(const char *full_text, const char *search_text,bool allow_overlap)
{	
	int conta = 0;
	int size1 = strlen(full_text);
	int size2 = strlen(search_text);
	printf("\n%d,%d\n",size1,size2);
	for(int i = 0 ; i < size1; i++)
	{	
		if(*(full_text+i) == *search_text)
		{
			for(int j = 0; j < size2;j++ )
			{	
				if(j == (size2-1)) conta++;
				printf("%c%c --",*(full_text+i+j),*(search_text+j));
				if(*(full_text+i+j) != *(search_text+j)) break;
				if(*(full_text+i+j) == *(search_text+j) && (*(full_text+j+1) != '\0')) continue;
				//if(*(full_text+i+j) == *(search_text+j) && (*(full_text+j+1) == '\0')) conta++;
				//if(*(full_text+i+j) != *(search_text+j)) break;
			}
		}
	
	}
	return conta;
}

int main(void)
{
	int tamanho = testa_str("atirei o pau no gato");
	printf("\n%d\n",tamanho);

	int vezes = search_substr("gato gato gato","gato",true);
	printf("\n%d\n",vezes);

}

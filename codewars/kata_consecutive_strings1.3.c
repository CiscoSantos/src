#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* longestConsec(char* strarr[], int n, int k) {

	if( n == 0 ) return "";
	if( n < k )  return "";
	if( k <= 0 ) return "";
	
	int major=0;
	char* major_str;
	for(int i=0;i<=n-k;i++)
	{
		int t_size_str=0;
		for(int j=k-1;j>=0;j--)
		{
			t_size_str = t_size_str + strlen(strarr[i+j]);
		}
		printf("\n%d\n",t_size_str);
		char* str_soma;
		str_soma = malloc(t_size_str);
		char* temp1 = strarr[i];
		strcpy(str_soma,temp1);
		for(int j=1;j<k;j++)
		{
			char* temp2 = strarr[i+j];
			strcat(str_soma,temp2);					
		}
		printf("\n%s\n",str_soma);
		
		if( strlen(str_soma)>major )
		{
			major= strlen(str_soma);
			major_str = malloc(strlen(str_soma));
			strcpy(major_str,str_soma);		
		} 		
	}

	printf("\n%s\n",major_str);

//	char* temp = strarr[0];
//	char* temp2 = strarr[1];
//	char* char_cat;
//	char_cat = malloc(strlen(temp)+strlen(temp2)); /* make space for the new string (should check the return value ...) */
//	printf("\n%p\n",char_cat);
//	strcpy(char_cat,temp); /*copia a primeira string para a nova variavel*/
//	strcat(char_cat,temp2); /*concatena a segunda string a primeira*/
//	printf("\n%s\n",char_cat);
//	printf("\n%d\n",strlen(char_cat));


}


char* longestConsec(char* strarr[], int n, int k);

 int main(void)
{
	char* a1[] = {"ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"};
	char* a2 = longestConsec(a1,5,2);
}

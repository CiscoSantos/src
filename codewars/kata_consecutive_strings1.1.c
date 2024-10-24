#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



char* longestConsec(char* strarr[], int n, int k) {

//	printf("%s%s\n",strarr[0],strarr[1]);
//	int t=strlen(strarr[0]);
//	int u=strlen(strarr[1]);
//	int s=t+u;
//	char * temp = (char *) malloc(sizeof(char) * s);
//	temp = strarr[0];
//	printf("\n%s\n",temp);

	char* frase  = "Atirei o pau no gato!";
	printf("\n%s\n",frase);
	char* frase2 ="Mas o gato não morreu!";
	printf("\n%s\n",frase2);

	printf("\n%s\n",strcat(frase,frase2));
//      char* temp3 = (char *) malloc(sizeof(char) * s);
//	temp3 = strarr[0];
//	strcat(temp3,strarr[1]);
//	char * temp = strcat(strarr[1],strarr[2]);
//	printf("\n$s\n",temp3);

	return strarr;

}


char* longestConsec(char* strarr[], int n, int k);

 int main(void)
{
	char* a1[] = {"ejjjjmmtthh", "zxxuueeg", "aanlljrrrxx", "dqqqaaabbb", "oocccffuucccjjjkkkjyyyeehh"};
	char* a2 = longestConsec(a1,5,2);
}

#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



char* longestConsec(char* strarr[], int n, int k) {

	printf("%s%s\n",strarr[0],strarr[1]);
	int t=0;
	int u=0;
	int s=0;
	t = strlen(strarr[0]);
	char * temp = strarr[0];
	printf("\n%s\n",temp);
//	strcat(temp,strarr[1]);
	printf("\n%s\n",strcat(temp,strarr[1]));
//	char* temp1 = (char *) malloc(sizeof(char) * t);
//	u = strlen(strarr[1]);
//        char* temp2 = (char *) malloc(sizeof(char) * u);
//	s = t+u;
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

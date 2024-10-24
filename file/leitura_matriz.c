#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv){

	int i,ch;
	FILE *fp;
//	char *conteudo;	
 		
	fp = fopen("rola.txt","r+");
	if(fp==NULL){
		printf("Deu merda e o arquivo não foi aberto.");
		exit(0);
	}
	i=0;
	printf("                           ");
	while(!feof(fp))
	{
		if(ch==32){
			 i++;
			 printf("                            ");
			 if(i==3){
				printf("\n                          ");
				i=0;
			 }	
		}
		printf("%c",ch);
		ch=fgetc(fp);

	}


	fclose(fp);
	return 0;

}

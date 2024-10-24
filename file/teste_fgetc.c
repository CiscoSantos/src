#include <stdio.h>
#include <stdlib.h>


int main(){

	int i,ch;
	FILE *fp;
//	char *conteudo;	
	
	fp = fopen("writing_to_file.txt","r+");
	if(fp==NULL){
		printf("Deu merda e o arquivo não foi aberto.");
		exit(0);
	}
	i=0;
	while((ch=fgetc(fp))!=EOF){
		i++;
		if(ch==10) printf("\n------------------------\n");
		printf("%c",ch);
				
	}
	fclose(fp);
	printf("\nNumero campos:%d .\n",i);
	return 0;

}

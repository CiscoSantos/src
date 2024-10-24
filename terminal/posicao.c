#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>


int main(){
	

	FILE *fp;
	int i,j,k,l,m,ch,t;
	int linha,coluna;	
	fp = fopen("teste.txt","r+");
	char buffer[30];
	
	if(fp==NULL){
		printf("Deu merda e o arquivo não foi aberto.");
		exit(0);
	}

	int linhas,colunas;
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	
 	linhas=w.ws_row;
	colunas=w.ws_col;
	int i;
	for(i=0;i<100;i++){	
		printf("\033[%d;%dHHello\n",i,i);
	}
	
	k=0;
	while(!feof(fp)){
					
		ch=fgetc(fp);
		if(ch!=32){
			buffer[j]=ch;
			j++;
		}
		if(ch==32){
			for(k=0;k<j;k++){
				printf("\033[%d;%dHHello\n",i,i);
			}			
				
		}
		
	}

	fclose(fp);
	return 0;

}

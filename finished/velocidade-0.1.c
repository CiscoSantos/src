#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){

	FILE *fp;
	int i,j,k,l,ch,carro;
	int linha,coluna;	
	fp = fopen("teste.txt","r+");
	char buffer[30];
	
	if(fp==NULL){
		printf("Deu merda e o arquivo não foi aberto.");
		exit(0);
	}
	
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	
	linha=w.ws_row;
	coluna=w.ws_col;
	i=0;
	j=0;
	l=200000;
//	printf("\e[1;1H\e[2J");
	while(!feof(fp)){
					
		ch=fgetc(fp);
		if(ch!=32){
			buffer[j]=ch;
			j++;
		}
		if(ch==32){
			printf("\e[1;1H\e[2J");
			carro=1;
			usleep(l);
			for(k=0;k<j;k++){
				printf("\033[%d;%dH%c",linha/2,coluna/2+carro,buffer[k]);
				carro++;
			}
			fflush(stdout);	 
			i++;
			j=0;
		}
	}

	
	fclose(fp);
	return 0;
}

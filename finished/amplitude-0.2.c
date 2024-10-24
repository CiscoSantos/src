#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){

	FILE *fp;
	int i,j,k,l,m,ch,t,carro;
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
	t=1;
	l=800000;
	m=1;
	printf("\e[1;1H\e[2J");
	while(!feof(fp)){
					
		ch=fgetc(fp);
		if(ch!=32){
			buffer[j]=ch;
			j++;
		}
		if(ch==32){
			switch(t){			
				case 1:
					carro=1;
					for(k=0;k<j;k++){
						printf("\033[%d;%dH%c",m,carro,buffer[k]);
						carro++;
					}
					fflush(stdout);	 
					i++;
					t++;
					j=0;
					break;
				case 2:
					carro=1;
					for(k=0;k<j;k++){
						printf("\033[%d;%dH%c",m,coluna/2+carro,buffer[k]);
						carro++;
					}	 
					fflush(stdout);	 
					i++;
					t++;
					j=0;
					break;
				case 3:
					carro=1;
					for(k=0;k<j;k++){
						printf("\033[%d;%dH%c",m,coluna-j+carro,buffer[k]);
						carro++;
					}	 
					fflush(stdout);	 
					i++;
					t=1;
					m++;
					j=0;
					usleep(l);
					break;

			}
	
		}

	

	}

	
	fclose(fp);
	return 0;
}

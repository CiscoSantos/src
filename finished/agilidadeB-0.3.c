#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){

	FILE *fp;
	int i,j,k,l,m,ch,t;
	int linha,coluna;	
	fp = fopen(argv[1],"r+");
	char buffer[100];
	
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
	l=500000;
	while(!feof(fp)){
					
		ch=fgetc(fp);
		if(ch!=32){
			buffer[j]=ch;
			j++;
		}
		if(ch==32 && j>0){
			switch(t){			
				case 1:
					printf("\e[1;1H\e[2J");
					m=1;
					usleep(l);					
					for(k=0;k<j;k++){
						printf("\033[%d;%dH%c",0,m,buffer[k]);
						m++;
					}
					fflush(stdout);	 
					i++;
					t++;
					m=0;
					j=0;
					break;
				case 2:
					printf("\e[1;1H\e[2J");
					m=1;
					usleep(l);					
					for(k=0;k<j;k++){
						printf("\033[%d;%dH%c",linha-1,m,buffer[k]);
						//printf("\033[%d;%dH%c",linha-1,coluna-j+m,buffer[k]);
						m++;
					}	 
					fflush(stdout);	 
					i++;
					t++;
					m=0;
					j=0;
					break;
				case 3:
					printf("\e[1;1H\e[2J");
					m=1;
					usleep(l);					
					for(k=0;k<j;k++){
						printf("\033[%d;%dH%c",0,coluna-j+m,buffer[k]);
						//printf("\033[%d;%dH%c",linha-1,m,buffer[k]);
						m++;
					}	 
					fflush(stdout);	 
					i++;
					t++;
					m=0;
					j=0;
					break;
				case 4:
					printf("\e[1;1H\e[2J");
					usleep(l);					
					for(k=0;k<j;k++){
						//printf("\033[%d;%dH%c",0,coluna-j+m,buffer[k]);
						printf("\033[%d;%dH%c",linha-1,coluna-j+m,buffer[k]);
						m++;
					}	 
					fflush(stdout);	 
					i++;
					t=1;
					m=0;
					j=0;
					break;
			}
	
		}

	

	}

	
	fclose(fp);
	return 0;
}

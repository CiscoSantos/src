#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){

	FILE *fp;
	int i,j,k,l,m,ch,t;
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
	while(!feof(fp)){
					
		ch=fgetc(fp);
		if(ch!=32){
			buffer[j]=ch;
			j++;
		}
		if(ch==32){
			switch(t){			
				case 1:
					printf("\n");
					usleep(l);
					for(k=0;k<j;k++){
						printf("%c",buffer[k]);
					}
					fflush(stdout);	 
					i++;
					t++;
					m=j;
					j=0;
					break;
				case 2:
					usleep(l);
					for (l=0;l<coluna/2-m;l++){
						printf(" ");
					}
					for(k=0;k<j;k++){
						printf("%c",buffer[k]);
					}	 
					fflush(stdout);	 
					i++;
					t++;
					m=j;
					j=0;
					break;
				case 3:
					usleep(l);
					for (l=0;l<coluna/2-(m+j);l++){
                                                printf(" ");
                                        }
					for(k=0;k<j;k++){
						printf("%c",buffer[k]);
					}	 
					fflush(stdout);	 
					i++;
					t=1;
					j=0;
					break;

			}
	
		}

	

	}

	
	fclose(fp);
	return 0;
}

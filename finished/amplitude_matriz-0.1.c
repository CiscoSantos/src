#include <stdio.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>


int main(int argc, char *argv[]){

//	FILE *fp;
	int i,j,k,l,m,ch,t,carro;
	float intervalo,intervalo_count;
	int linha,coluna,espaco;	
//	fp = fopen(argv[1],"r+");
	char buffer;
	
/*	if(fp==NULL){
		printf("Deu merda e o arquivo não foi aberto.");
		exit(0);
	} */
	
	struct winsize w;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	
	linha=w.ws_row;
	coluna=w.ws_col;
	sscanf(argv[1], "%f", &intervalo);
	intervalo=intervalo*60;
	intervalo_count=0;
	espaco=0;
	i=0;
	j=0;
	t=1;
	l=800000;
	m=1;
	srand(time(NULL));
	while(t<linha){

		if(intervalo_count==intervalo){
			break;
		}
		intervalo_count=intervalo_count+1;
		for(m=0;m<=linha-1;m++){		
			for(k=0;k<=(coluna)/2;k++){
				ch = rand() % 26 + 65;
				buffer= (char) ch;
				printf("%c",buffer);
				for(j=0;j<=espaco;j++){
					printf(" ");
				}
			}
		} 
		usleep(l);
		printf("\e[1;1H\e[2J");
				
//		j++;
		
			
/*			switch(t){			
				case 1:
					printf("\e[1;1H\e[2J");
					carro=1;
					for(k=0;k<j;k++){
						printf("\033[%d;%dH%c",linha/2,carro,buffer);
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
						printf("\033[%d;%dH%c",linha/2,coluna/2+carro,buffer);
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
						printf("\033[%d;%dH%c",linha/2,coluna-j+carro,buffer);
						carro++;
					}	 
					fflush(stdout);	 
					i++;
					t=1;
					m++;
					j=0;
					usleep(l);
					break;

	
		}*/

	}

	
//	fclose(fp);
	return 0;
}

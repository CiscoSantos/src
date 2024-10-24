#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

void main();
int menu();
void game_over();
void imprimi_campo();
void imprimi_cobra();
int sorteia(int limite);
void imprimi_fruta();
void imprimi();
int campo[20][30];
struct lista {
	int habil; // instancia da estrutura que ira indicar se o gomo do corpo foi habilitado a existir, essa habilitacao ocorre apos a cobra ingerir uma fruta;
	int coord_xis; //coordenada horizontal do campo na qual o gomo do corpo da cobra sera impresso;
	int coord_ypsilon; //coordenada vertical do campo na qual o gomo do corpo da cobra sera impresso;
	struct lista * proximo; // ponteiro que ira apontar para o proximo gomo da cobra, no caso um novo elemento da matris comosta por estruturas lista, a ser impresso na tela;
} cobra[100]; // declaracao da matriz de estruturas listas que sera usada como o corpo da cobra;
int primeira_vez=0;// a variavel primeira_vez sempre usada todo come‡o de jogo para inicializar o corpo da cobra, isto e, os primeiros gomos com a qual ela come‡a;
int direcao;
int comeu=1; //specie de flag que indica se a fruta foi comida ou nao para que seja imprimida uma nova
int fruta[2];
struct lista * rabo;
struct lista * cabeca;
int score=0;

void atraso()
{
	int t0,t1;
	 t0 = clock();
     do{
	t1 = clock();
    }while( t1 < t0 + 0.1 * CLOCKS_PER_SEC );
}

void init_campo()
{	
	int i,j;
	for(i=0;i<20;i++) 
	{
		for(j=0;j<30;j++)
		{
			if(i==0 || i==19 || j==0 || j==29)
			{
				campo[i][j]=1;
			}
			else
			{
				campo[i][j]=0;
			} 
		}
	}
}

void imprimi_campo()  // funcao que vai imprimir na tela o campo, tambem ‚ nela que sera feita atribuicao de valores para a matriz do campo. Essa atribuicao e importante porque delimitara os limites do campo;
{
	int i,j; //declaracao dos contadores;
	clrscr();
	gotoxy(40,5);
	printf("SCORE: %d",score*100);
	for(i=0;i<20;i++) // laco que fara variar as linhas da o campo
	{
		gotoxy(2,i+2); // funcao usada para configura o local na tela onde serao impressos os elementos da matriz;
		for(j=0;j<30;j++) // laco que fara variar as colunas;
		{
			if(campo[i][j]==0)
			{
				printf(" ");
			}
			if(campo[i][j]==1)
			{
				printf("%c",219);
			}
			if(campo[i][j]==3)
			{
				printf("F");
			}
		}
	}
}

void imprimi_cobra() //funcao responsavel por imprimir a cobra na tela;
{
	int i,j;
	if(primeira_vez==0) // condicional usado para inicializar o corpo da cobra quando esta funcao e chamada pela primeira vez;
	{
		direcao=1;// define a direcao como horizontal da esquerda para a direita, quando direcao for igual a dois o sentido sera da direita para a esquerda, quando direcao valer 3 o movimento sera vertical de baixo para cima e or fim no caso de direao valer 4 o movimento sera vertical de cima para baixo;
		for(i=0;i<3;i++)
		{
			cobra[i].habil=1;
			cobra[i].coord_xis=10;
			cobra[i].coord_ypsilon=i+5;
		}
		rabo=&cobra[0];
		cabeca=&cobra[2];
		cobra[2].proximo=&cobra[0];
		cobra[1].proximo=&cobra[2];
		cobra[0].proximo=&cobra[1];
		primeira_vez++;
		if(primeira_vez==1) imprimi_cobra();  // chamada recursiva para forcar a funcao a imprimir o corpo da cobra na sua primeira chamada;

	}
	else  //condicional que ira imprimir a cobra depois que esta for inicializada;
	{
		for(i=0;i<100;i++)// este laca e usado para imprimir os muitos pedacos da cobra
		{
			if(cobra[i].habil==1)//expressao condicional que ira limitar a impressao aos gomos da cobra que ja foram habilitados;
			{	
				gotoxy(cobra[i].coord_ypsilon+2, cobra[i].coord_xis+2); //funcao usada para formatar a saida nas coordenadas que o gomo do corpo deve ser impresso;
				printf("%c",245);
			}
			else continue; // condicionalque ira quebrar o la‡o quando os gomos acabarem;
		}
	}
}

int sorteia(int limite)
{
	int volta;
	srand(time(NULL));
	volta=rand()%limite;
	return volta;

}


void imprimi_fruta()
{
	if(comeu==1)
	{
		do
		{
			do
			{
				fruta[0]=sorteia(30);
			}while(fruta[0]==0 || fruta[0]==29);
			do
			{
				fruta[1]=sorteia(20);
			}while(fruta[0]==0 || fruta[0]==19);
		}while(campo[fruta[1]][fruta[0]]==1 || campo[fruta[1]][fruta[0]]==2 || campo[fruta[1]][fruta[0]]==3 );
		campo[fruta[1]][fruta[0]]=3;
		comeu=0;
	}
	else campo[fruta[1]][fruta[0]]=3;
}

void imprimi()
{
	int tecla[2],atual=3; ////atual sera a variavel que quardara o indice da matriz cobra, sempre apontando pra qual gomo do corpo deve ser habilitado
	double i;
	do
	{
		init_campo();
		imprimi_fruta();
		imprimi_campo();
		imprimi_cobra();
		if(kbhit()!=0)
		{
			tecla[0]=getch();
			tecla[1]=getch();
			if(tecla[1]==72)
			{
				if(direcao==1 || direcao==2)
				{
					direcao=4;
				}
			}
			if(tecla[1]==80)
			{
				if(direcao==1 || direcao==2)
				{
					direcao=3;
				}
			}
			if(tecla[1]==75)
			{
				if(direcao==3 || direcao==4)
				{
					direcao=2;
				}
			}
			if(tecla[1]==77)
			{
				if(direcao==3 || direcao==4)
				{
					direcao=1;
				}
			}
		}
		else
		{
			switch(direcao)
			{
				case 1:
					  rabo->coord_xis= cabeca->coord_xis;
					  rabo->coord_ypsilon= cabeca->coord_ypsilon+1;
					  cabeca=cabeca->proximo;
					  rabo=rabo->proximo;
					  if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==1) game_over();
				      if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==3) 
					  {
						campo[cabeca->coord_xis][cabeca->coord_ypsilon]=0;
						cobra[atual].habil=1;
						cobra[atual].coord_xis=cabeca->coord_xis;
						cobra[atual].coord_ypsilon=cabeca->coord_ypsilon+1;
						cobra[atual].proximo=cabeca;
						cabeca=&cobra[atual];						
						rabo->proximo=&cobra[atual];
						atual++;
						comeu=1;
						score++;
						}
					  break;
				case 2:
					  rabo->coord_xis=cabeca->coord_xis;
					  rabo->coord_ypsilon= cabeca->coord_ypsilon-1;
					  cabeca=cabeca->proximo;
					  rabo=rabo->proximo;
					  if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==1) game_over();
           			  if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==3) 
					  {
						campo[cabeca->coord_xis][cabeca->coord_ypsilon]=0;
						cobra[atual].habil=1;
						cobra[atual].coord_xis=cabeca->coord_xis;
						cobra[atual].coord_ypsilon=cabeca->coord_ypsilon-1;
						cobra[atual].proximo=cabeca;
						cabeca=&cobra[atual];						
						rabo->proximo=&cobra[atual];
						atual++;
						comeu=1;
						score++;
					  }				  
				      break;
				case 3:
					  rabo->coord_xis=cabeca->coord_xis+1;
					  rabo->coord_ypsilon= cabeca->coord_ypsilon;
					  cabeca=cabeca->proximo;
					  rabo=rabo->proximo;	
					  if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==1) game_over();
					  if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==3) 
					  {
						campo[cabeca->coord_xis][cabeca->coord_ypsilon]=0;
						cobra[atual].habil=1;
						cobra[atual].coord_xis=cabeca->coord_xis+1;
						cobra[atual].coord_ypsilon=cabeca->coord_ypsilon;
						cobra[atual].proximo=cabeca;
						cabeca=&cobra[atual];						
						rabo->proximo=&cobra[atual];
						atual++;
						comeu=1;
						score++;
					  }					  
				      break;
				case 4:
					  rabo->coord_ypsilon=cabeca->coord_ypsilon;
				      rabo->coord_xis=cabeca->coord_xis-1;
					  cabeca=cabeca->proximo;
					  rabo=rabo->proximo;
					  if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==1) game_over();
				      if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==3) 
					  {
						campo[cabeca->coord_xis][cabeca->coord_ypsilon]=0;
						cobra[atual].habil=1;
						cobra[atual].coord_xis=cabeca->coord_xis-1;
						cobra[atual].coord_ypsilon=cabeca->coord_ypsilon;
						cobra[atual].proximo=cabeca;
						cabeca=&cobra[atual];						
						rabo->proximo=&cobra[atual];
						atual++;
						comeu=1;
						score++;
					  }
					  break;
			}
		}
		atraso();
	 }while(tecla[0]!=65);
}

void game_over()
{
		clrscr();
		gotoxy(30,30);
		printf("Game Over");
		getch();
}

void main()
{
	int jogar;
	clrscr();
	printf("Quer jogar?(Nao=1/Sim=0)");
	scanf("%d",&jogar);
	if(jogar==1)
	{
		printf("Pior proce Papudo!!!!!");
	}
	if(jogar==0)
	{
		_setcursortype(_NOCURSOR); // funcao do console que impede que o cursor fique visivel
		imprimi();
		getch();
	}
	getch();
	clrscr();
}

/* Valores para o campo : quando o campo for igual a 1 teremos uma parede;
				quando o cmpo for igual a 2 teremos a cobra
				e quando o campo for igual a 3 sera impresso a fruta
				0 sera o valor de espaços em branco
*/
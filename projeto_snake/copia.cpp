#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*Bloco de declaração de variaveis globais e prototipos de estruturas e funções */

int main(int argc, char *argv[]);
int menu();
void game_over();
void imprimi_campo();
void imprimi_cobra();
int sorteia(int limite);
void imprimi_fruta();
void jogo();
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
int opc_lab=1, opc_nivel=1; /*Variáveis globais que servirão para marcar a opção do labirinto e do nível selecionado pelo usuário.Se o usuário não selecionar nenhuma opção, por padrão o jogo começa no labirinto 1 e no nível 1.*/
int score=0;
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void atraso()
{
	int t0,t1;
	switch(opc_nivel)
	{
	case 1:
		t0 = clock();
		do{
			t1 = clock();
		}while( t1 < t0 + 0.5 * CLOCKS_PER_SEC );
		break;
	case 2:
		t0 = clock();
		do{
			t1 = clock();
		}while( t1 < t0 + 0.4 * CLOCKS_PER_SEC );
		break;
	case 3:
		t0 = clock();
		do{
			t1 = clock();
		}while( t1 < t0 + 0.2 * CLOCKS_PER_SEC );
		break;
	case 4:
		t0 = clock();
		do{
			t1 = clock();
		}while( t1 < t0 + 0.1 * CLOCKS_PER_SEC );
		break;
	
	}
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

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

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void imprimi_campo()  // funcao que vai imprimir na tela o campo, tambem ‚ nela que sera feita atribuicao de valores para a matriz do campo. Essa atribuicao e importante porque delimitara os limites do campo;
{
	int i,j; //declaracao dos contadores;

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
				printf("%c",3);
			}
		}
	}
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void imprimi_cobra() //funcao responsavel por imprimir a cobra na tela;
{
	int i,j;
	if(primeira_vez==0) // condicional usado para inicializar o corpo da cobra quando esta funcao e chamada pela primeira vez;
	{
		direcao=1;// define a direcao como horizontal da esquerda para a direita, quando direcao for igual a dois o sentido sera da direita para a esquerda, quando direcao valer 3 o movimento sera vertical de baixo para cima e or fim no caso de direao valer 4 o movimento sera vertical de cima para baixo;
		for(i=0;i<100;i++)
		{
			if(i<3)//condicional usado para habilitar os tres gomos iniciais da cobra
			{
				cobra[i].habil=1;
				cobra[i].coord_xis=10;
				cobra[i].coord_ypsilon=i+5;
			}
			if(i>=3)//condicional usado para zerar os demias gomos para evitar que eventuais lixos de memoria como informações de outras partidas atrapalhem o jogo
			{
				cobra[i].habil=0;
			}
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
				printf("%c",4);
				campo[cobra[i].coord_xis][cobra[i].coord_ypsilon]=2;
			}
			else continue; // condicionalque ira quebrar o la‡o quando os gomos acabarem;
		}
	}
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

int sorteia(int limite)
{
	int volta;
	srand(time(NULL));
	volta=rand()%limite;
	return volta;

}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

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

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void jogo()
{
	int tecla[2],atual=3,fim=0; ////atual sera a variavel que quardara o indice da matriz cobra, sempre apontando pra qual gomo do corpo deve ser habilitado
	double i;
	primeira_vez=0;
	score=0;
	clrscr();
	_setcursortype(_NOCURSOR);
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
					  if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==1 || campo[cabeca->coord_xis][cabeca->coord_ypsilon]==2)
					  { 
						fim=1;
						break;
					  }
				      if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==3) 
					  {
					//	campo[cabeca->coord_xis][cabeca->coord_ypsilon]=0;
						cobra[atual].habil=1;
						cobra[atual].coord_xis=cabeca->coord_xis;
						cobra[atual].coord_ypsilon=cabeca->coord_ypsilon+1;
						
						cabeca->proximo=&cobra[atual];
						cobra[atual].proximo=rabo;
						cabeca=&cobra[atual];						
						
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
					  if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==1 || campo[cabeca->coord_xis][cabeca->coord_ypsilon]==2)
					  { 
						fim=1;
						break;
					  }
           			  if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==3) 
					  {
					//	campo[cabeca->coord_xis][cabeca->coord_ypsilon]=0;
						cobra[atual].habil=1;
						cobra[atual].coord_xis=cabeca->coord_xis;
						cobra[atual].coord_ypsilon=cabeca->coord_ypsilon-1;
						
						cabeca->proximo=&cobra[atual];
						cobra[atual].proximo=rabo;
						cabeca=&cobra[atual];						
											
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
					  if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==1 || campo[cabeca->coord_xis][cabeca->coord_ypsilon]==2)
					  { 
						fim=1;
						break;
					  }
					  if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==3) 
					  {
					//	campo[cabeca->coord_xis][cabeca->coord_ypsilon]=0;
						cobra[atual].habil=1;
						cobra[atual].coord_xis=cabeca->coord_xis+1;
						cobra[atual].coord_ypsilon=cabeca->coord_ypsilon;
						
						cabeca->proximo=&cobra[atual];
						cobra[atual].proximo=rabo;
						cabeca=&cobra[atual];						
						
						
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
					  if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==1 || campo[cabeca->coord_xis][cabeca->coord_ypsilon]==2)
					  { 
						fim=1;
						break;
					  }
				      if(campo[cabeca->coord_xis][cabeca->coord_ypsilon]==3)
					  {
					//	campo[cabeca->coord_xis][cabeca->coord_ypsilon]=0;
						cobra[atual].habil=1;
						cobra[atual].coord_xis=cabeca->coord_xis-1;
						cobra[atual].coord_ypsilon=cabeca->coord_ypsilon;

						cabeca->proximo=&cobra[atual];
						cobra[atual].proximo=rabo;
						cabeca=&cobra[atual];

						atual++;
						comeu=1;
						score++;
					  }
					  break;
			}
		}
		if(fim==1) break;
		atraso();
	 }while(tecla[0]!=65);
	 if(fim==1) game_over();
}


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/




/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Mostra ao usuário o menu para escolher o labirinto que deseja jogar
void menu_lab()
{
     int opcao, posicao=9, aux=0;
     clrscr();
     gotoxy(31,9);
     cprintf("Labirinto 1");
     gotoxy(31,10);
     cprintf("Labirinto 2");     //Aqui o usuáriuo navega pelas opções de Labirintos
     gotoxy(31,11);
     cprintf("Labirinto 3");
     gotoxy(31,12);
     cprintf("Labirinto 4");
     gotoxy(31,9);

     do
     {
	  if(kbhit()!=0)//se o usuário apertou alguma tecla, trata-se conforme as especificações abaixo.
	  {
	       opcao=getch();

	       switch(opcao)
	       {
		    case 80://Vai para baixo, cuidando para que não ultrapasse o tamanho do menu
			 if(posicao<12)
			 {
			      posicao++;
			      gotoxy(31,posicao);
			 }
			 break;
		    case 72://Vai para cima, cuidando para que não ultrapasse o tamanho do menu
			 if(posicao>9)
			 {
			      posicao--;
			      gotoxy(31,posicao);
			 }
			 break;
		    case 13://Se o usuário aperta enter em cima de uma das opçõe, seleciona uma das opções do labirinto.
			 switch(posicao)
			 {
			      case 9:
				   opc_lab=1;
				   break;
			      case 10:
				   opc_lab=2;
				   break;
			      case 11:
				   opc_lab=3;
				   break;
			      case 12:
				   opc_lab=4;
				   break;
			 }
			 aux++;//Fará com que o laço seja quebrado.
			 break;
	       }
	  }
     }while(aux==0);
}
/*-----------------------------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Mostra ao usuário as opções de nível

void menu_nivel()
{
     int opcao, posicao=9, aux=0;

     clrscr();
     gotoxy(31,9);
     cprintf("Nivel 1");
     gotoxy(31,10);
     cprintf("Nivel 2");
     gotoxy(31,11);          //Usuário navega pelas opoções de nível
     cprintf("Nivel 3");
     gotoxy(31,12);
     cprintf("Nivel 4");
     gotoxy(31,9);

      do
     {
	  if(kbhit()!=0)//Usuário apertou alguma tecla
	  {
	       opcao=getch();

	       switch(opcao)
	       {
		    case 80://Apertou seta para cima
			 if(posicao<12)
			 {
			      posicao++;
			      gotoxy(31,posicao);
			 }
			 break;//Apertou seta para baixo
		    case 72:
			 if(posicao>9)
			 {
			      posicao--;
			      gotoxy(31,posicao);
			 }
			 break;
		    case 13://Apertou Enter. Selecionará a opção de nível desejada.
			 switch(posicao)
			 {
			      case 9:
				   opc_nivel=1;
				   break;
			      case 10:
				   opc_nivel=2;
				   break;
			      case 11:
				   opc_nivel=3;
				   break;
			      case 12:
				   opc_nivel=4;
				   break;
			 }
			 aux++;//Quebra o laço após o usuário escolher uma opção
			 break;
	       }
	  }
     }while(aux==0);
}


/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Vai mostrar ao usuário o menu

int menu_princ()
{
     int opcao, posicao=10, aux=0, denovo=0;
	 _setcursortype(_SOLIDCURSOR);
     clrscr();//Função que limpa tela
     gotoxy(31,10);
     cprintf("Iniciar jogo");
     gotoxy(31,11);
     cprintf("Labirintos");     //Imprime as opções mais ou menos no meio do prompt
     gotoxy(31,12);
     cprintf("Nivel");
     gotoxy(31,13);
     cprintf("Sair");
     gotoxy(31,10);

     do
     {
	  if(kbhit()!=0)//Se kbhit retorna um número diferente de 0, seignifica que o usuário digitou um caracter
	  {
	       opcao=getch();//variável opção, guardo o valor correspondente a opção digitada pelo usuário
			   switch(opcao)
	       {
		    case 80://Se o usuário digitou tecla para baixo (valor 80 na tabela ASCCI) movimenta cursor para baixo
			 if(posicao<13)//Condicional que faz com que o cursor não ultrapasse a posição do menu
			 {
			      posicao++;
			      gotoxy(31,posicao);
			 }
			 break;
		    case 72://Se o usuário digitou seta para cima (valor 72 na tabela ASCCI) movimenta o cursor para cima
			 if(posicao>10)//Condicional que faz com que o cursor não ultrapasse a posição do menu
			 {
			      posicao--;
			      gotoxy(31,posicao);
			 }
			 break;
		    case 13://Se usuário digita Enter(código 13 na tabela ASCCI) chama a função correspondente a opção selecionada pelo usuário
			 switch(posicao)
			 {
			      case 10:
				   jogo();
				   break;
			      case 11:
				   menu_lab();//Chama o menu labirinto
				   denovo++;//adiciona a viariável de novo para imprimir o menu principal quando a função retorna
				   break;
			      case 12:
				   menu_nivel();//Chama o menu labirinto
				   denovo++;//adiciona a viariável de novo para imprimir o menu principal quando a função retorna
				   break;
			      case 13:
				   aux++;//Se o usuário não quiser jogar a opção sair, faz com que o jogo não seja executado.
				   denovo=-1;
				}
			 break;
	       }
	  }

	  if(denovo>0)//Condicional que vai imprimir o menu principal novamente.
		      //Isso acontece toda vez que as funções menu_lab e menu_nivel retornam a a função menu_princ.
	  {
		menu_princ();
	  }

     }while(aux==0);
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void game_over()
{
		clrscr();
		gotoxy(10,10);
		cprintf("GAME OVER");
		cprintf("\nPRESS ENTER");
		getch();
		menu_princ();
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//Função main
int main(int argc, char *argv[])
{
     menu_princ();//chama o menu principal
     return 0;
}


/* Valores para o campo : quando o campo for igual a 1 teremos uma parede;
				quando o cmpo for igual a 2 teremos a cobra
				e quando o campo for igual a 3 sera impresso a fruta
				0 sera o valor de espaços em branco
*/
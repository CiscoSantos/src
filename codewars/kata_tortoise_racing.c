#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

int* race(int v1, int v2, int g) {
  if(v1 >= v2)
  {
    int* vec = malloc(3*sizeof(int));  //A alocação dinamica foi necessária para passar nos testes do Kata. O problema pode ter sido que o endereço provisionado para o ponteiro na função local devia estar sendo descartado quando a função era encerrada. Uma vez que fiz a alocação dinamica foi possivel passar no teste. Algo que deve ser notado é que quando compilado localmente no Linux o comportamento foi diferente do que no site do Codewars.
    vec[0] = vec[1] = vec[2] = -1;
    int *end;
    end = vec;
    return end;
  }
  
  int tempo = (g * 3600)/(v2-v1);
  int hora = tempo/3600;
  int min = (tempo % 3600)/60;
  int sec = (tempo % 3600) % 60;
  
  int *end; 
  int vec[3] = {hora,min,sec};
  end = vec;
  return end;  
}

void main(){


	int a1[3] = {720, 850, 70};
	int *resut = race(a1[0],a1[1],a1[2]);
	printf("ˇ\n - ");
	for(int k = 0; k<3; k++)
	{
		printf(" %d ",resut[k]);
	}
	printf("ˇ- \n");
	int a2[3] = {820, 81, 550};
	int *resut2 = race(a2[0],a2[1],a2[2]);
	printf("ˇ\n - ");
	for(int k = 0; k<3; k++)
	{
		printf(" %d ",resut2[k]);
	}
	printf("ˇ- \n");
//    	dotest(820, 81, 550, a2);
    	int a3[3] = {80, 91, 37};
	int *resut3 = race(a3[0],a3[1],a3[2]);
	printf("ˇ\n - ");
	for(int k = 0; k<3; k++)
	{
		printf(" %d ",resut3[k]);
	}
	printf("ˇ- \n");
  //  	dotest(80, 91, 37, a3);

}

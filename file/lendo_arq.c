#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	int i,isquare;
	fp = fopen ("writing_to_file.txt","r");
	if (fp==NULL){
		printf("Deu merda e o arquivo não foi aberto.");
		exit(0); // para funcionar requer a biblioteca stdlib.
	}
//	printf("%p",fp);
      /* write to the file */
	while (fscanf(fp, "%d,%d\n",&i,&isquare)==2)	
		printf("i: %d, isquare: %d\n", i, isquare);
	
	fclose(fp);	

	
	return 0;
}

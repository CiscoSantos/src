#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE *fp;
	fp = fopen ("writing_to_file.txt","w");
	if (fp==NULL){
		printf("Deu merda e o arquivo não foi aberto.");
		exit(0); // para funcionar requer a biblioteca stdlib.
	}
//	printf("%p",fp);
	int i;
	for (i=0; i<100;i++){
		fprintf(fp,"%d, %d\n",i,i*i);
	}
	return 0;
}

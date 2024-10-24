#include <stdio.h>
#include <stdlib.h>

void main ()
{
	int i = 1;
	int *pi = &i;
	int **ppi = &pi;

	printf("i = %d, &i = %p\n", i, &i);
	printf("pi = %p, &pi = %p\n", pi, &pi);
	printf("ppi = %p, &ppi = %p\n", ppi, &ppi);

	*pi += 1; 

	printf("i = %d, &i = %p\n", i, &i);
	printf("pi = %p, &pi = %p\n", pi, &pi);
	printf("ppi = %p, &ppi = %p\n", ppi, &ppi);

	**ppi += 1;

	printf("i = %d, &i = %p\n", i, &i);
	printf("pi = %p, &pi = %p\n", pi, &pi);
	printf("ppi = %p, &ppi = %p\n", ppi, &ppi);
}

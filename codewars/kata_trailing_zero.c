#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long zeros(long n)
{

        if(n<=0) return 0;
        long n_zeros=0,quociente=n;
        printf("\n------------- Inicio do teste para N = %ld",n);  
        do
        {
                printf("\nQuociente:%ld - Numero de Zeros:%ld",quociente,n_zeros);
                quociente = quociente/5;
                n_zeros= n_zeros + quociente;
        }while(quociente>=5);
        
        printf("\nXXXXXXXXXXXXXXXX Fim do teste para N = %ld - Resultado Final: %lu ;",n,n_zeros);  
        
        return n_zeros;
}



long zeros(long n);

int main(void)
{

	printf("Numero saida: %ld;",zeros(126));
	return 0;

}

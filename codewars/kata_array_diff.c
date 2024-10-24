#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z) {

        int total=n1;
        int* lista = (int *) malloc(sizeof(int) * n1);
        int k = 0;
        for(size_t t=0;t<n1;t++)
        {
          printf("%d: ",arr1[t]);
          
        }
        printf("           || ");
        for(size_t t=0;t<n2;t++)
        {
          printf("%d:",arr2[t]);
          
        }

        
        bool inedito = true;
        for(int i=0;i<n1;i++)
        {
                for(int j=0;j<n2;j++)
                {
                        if(arr2[j] == arr1[i])
                        {
				//total--;
                                inedito = false;
                        }
                }
                if(inedito==true)
                {
                        lista[k]=arr1[i];
                        k++;
                }
                else
                {
                        inedito = true;
                }
        }
        printf("\nTotal: %d\n",total);
        for(int h=0;h<total;h++)
        {
                printf("%d - ",lista[h]);
        }
        printf("\n");
        *z = (size_t) k;
        printf("%zu\n",*z);
        int * volta = &total;
        return lista;
        
}

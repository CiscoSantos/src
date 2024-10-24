#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void reset( int *array, int size) {
   memset(array,0,size * sizeof(*array));
   for(int i =0;i< size;i++)
   {
   	printf("%d\n",array[i]);
   
   }
}
int main()
{
   int array[10];
   reset( array, 10 ); // sets all elements to 0
}

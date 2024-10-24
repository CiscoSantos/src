#include <time.h>
#include <stdio.h>

int main(void)
{
  printf("Elapsed time: %ld secs.\n%ld\n%ld\n%ld", clock()/CLOCKS_PER_SEC,clock(),CLOCKS_PER_SEC,clock());
  return 0; 
}


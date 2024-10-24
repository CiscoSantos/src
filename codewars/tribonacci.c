#include <stdlib.h>
#include <stdio.h>

long long *tribonacci(const long long signature[3], size_t n);

#define ASSERT_ARR_EQ(expected, submitted, sz)                           \
    if(sz == 0 && submitted != NULL)                                     \
      { free(submitted); submitted = NULL;                               \
        cr_assert(0, "n == 0, should return NULL\n"); }                  \
    for(size_t i=0; i<sz; i++)                                           \
        if(submitted[i] != expected[i])                                  \
            cr_assert(0,                                                 \
                "Incorrect value at index %i: %lld should equal %lld\n", \
                i, submitted[i], expected[i]);                           \
    cr_assert(1);


int main (void)
{
	
	const long long signature[3] = {1, 1, 1};
	const size_t n = 10;
	const long long expected[10] = {0, 0, 1, 1, 2, 4, 7, 13, 24, 44};
	const long long *submitted = tribonacci(signature, n);
	ASSERT_ARR_EQ(expected, submitted, n);
	free(submitted);
	submitted = NULL;
}


long long *tribonacci(const long long signature[3], size_t n) {

  long long fibo[100000];
  for(int i=0; i <100000;i++) fibo[i]=0;
  fibo[0]=signature[0];
  fibo[1]=signature[1];
  fibo[2]=signature[2];
  
  for (int i=3;i<n;i++){
    int j=i-1;
    fibo[i]= fibo[i] + fibo[j];
    j=j-1;
    fibo[i]= fibo[i] + fibo[j];
    j=j-1;
    fibo[i]= fibo[i] + fibo[j];
    printf("\n%lld", fibo[i]);

  }
  return &(fibo[0]);
}

#include <string.h>
 /* memset */
 void *(memset)(void *s, int c, size_t n)
 {
     unsigned char *us = s;
     unsigned char uc = c;
     while (n-- != 0)
         *us++ = uc;
     return s;
 }

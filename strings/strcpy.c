#include <string.h>
 /* strcpy */
 char *(strcpy)(char *restrict s1, const char *restrict s2)
 {
     char *dst = s1;
     const char *src = s2;
     /* Do the copying in a loop.  */
     while ((*dst++ = *src++) != '\0')
         ;               /* The body of this loop is left empty. */
     /* Return the destination string.  */
     return s1;
 }

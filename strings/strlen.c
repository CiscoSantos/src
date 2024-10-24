#include <string.h>
 /* strlen */
 size_t (strlen)(const char *s)
 {
     const char *p = s; /* pointer to character constant */
     /* Loop over the data in s.  */
     while (*p != '\0')
         p++;
     return (size_t)(p - s);
 }

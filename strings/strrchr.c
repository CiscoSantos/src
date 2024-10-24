#include <string.h>
 /* strrchr */
 char *(strrchr)(const char *s, int c)
 {
     const char *last = NULL;
     /* If the character we're looking for is the terminating null,
        we just need to look for that character as there's only one
        of them in the string.  */
     if (c == '\0')
         return strchr(s, c);
     /* Loop through, finding the last match before hitting NULL.  */
     while ((s = strchr(s, c)) != NULL) {
         last = s;
         s++;
     }
     return (char *) last;
 }

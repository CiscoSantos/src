#include <string.h>
 /* strchr */
 char *(strchr)(const char *s, int c)
 {
     char ch = c;
     /* Scan s for the character.  When this loop is finished,
        s will either point to the end of the string or the
        character we were looking for.  */
     while (*s != '\0' && *s != ch)
         s++;
     return (*s == ch) ? (char *) s : NULL;
 }

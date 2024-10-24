#include <stdbool.h>
#include <string.h>

int search_substr(const char *full_text, const char *search_text, bool allow_overlap) {
    int sub_len = strlen(search_text);
    if ( sub_len == 0 || sub_len > strlen(full_text) ) return 0;
    int count = 0;
    char * res = strstr(full_text, search_text);
    if ( allow_overlap ) {
        while( res != NULL ) {
            count += 1;
            res = strstr(res + 1, search_text);
        }
    }
    else {
        while( res != NULL ) {
            count += 1;
            res = strstr(res + sub_len, search_text);
        }
    }
    return count;
}

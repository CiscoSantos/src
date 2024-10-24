#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* vertMirror(char* strng) {
    // your code
	printf("%s",strng);
	char array[]= gets(strng);

}
char* horMirror(char* strng) {
    // your code
}
typedef char* (*generic_func_t) (char*);
char* oper(generic_func_t f, char* s) {
    // your code
}


int main(void)
{
	char z[]="abcd\nefgh\nijkl\nmnop";
	char* test=z;
 	vertMirror(test);

}


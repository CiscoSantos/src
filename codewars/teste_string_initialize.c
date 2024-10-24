#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
//#include <ncurses.h>

char * copyStr(char s[])
    {
      int len = strlen(s); //find length of s
      char * copy; 
      copy = (char *)malloc(len); //dynamically allocate memory 
      int i; 
      for(i=0;i<len;i++) 
       {
         copy[i]=s[i];  //copy characters               
       }
       return copy; //return address
    }

int main(int argc, char ** argv)
    {
     char * str;
     str = "music is my aeroplane";
     char * res;
     res = copyStr(str);
     printf("The copied string is : %s\n",res);
   //  getch();
    }


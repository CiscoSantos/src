#include <stdio.h>


int (strcmp)(const char *s1, const char *s2)
 {
     unsigned char uc1, uc2;
     /* Move s1 and s2 to the first differing characters 
        in each string, or the ends of the strings if they
        are identical.  */
     while (*s1 != '\0' && *s1 == *s2) {
         s1++;
         s2++;
     }
     /* Compare the characters as unsigned char and
        return the difference.  */
     uc1 = (*(unsigned char *) s1);
     uc2 = (*(unsigned char *) s2);
     return ((uc1 < uc2) ? -1 : (uc1 > uc2));
 }


int main(void)
{
	const char *cores[] = { "Azul", "Roxo", "Preto ", "Branco", "Vermelho", "Verde" };
	for(int i = 0;i <4;i++)
	{	

		if(strcmp(cores[i],cores[i+1]) == -1) printf("\nCor %s é menor que %s;\n",cores[i],cores[i+1]);
		if(strcmp(cores[i],cores[i+1]) == 1) printf("\nCor %s é maior que %s;\n",cores[i],cores[i+1]);
		if(strcmp(cores[i],cores[i+1]) == 0) printf("\nCor %s é igual que %s;\n",cores[i],cores[i+1]);
		
	}
}

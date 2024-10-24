#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>


int main (int argc, char **argv)
{
	int i;
	i=0;
   	for(i=0;i<=10;i++){	
		
		sleep(1);
		printf("ROLLLLA!!!!");
		fflush(stdout);

	}
	


	return 0;  // make sure your main returns int
}

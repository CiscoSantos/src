#include<stdio.h>
#include<signal.h>
void bypass_sigint(int sig_no)
{
 
}
int main()
{
 
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = &bypass_sigint;
    sigaction(SIGINT, &sa,NULL);
 
    while(1)
    {
        sleep(1);
        printf("do nothing \n ");
    }
    return 0;
}

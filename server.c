#include<unistd.h>
#include<stdio.h>
#include<signal.h>

void soma(int sinal)
{
    if (sinal == SIGUSR1)
    {
       // printf("%d", 1 + 1);
    }
    if(sinal == SIGUSR2)
        printf("%d", 2 + 2);   
}
int main()
{
    int pid = getpid();
    printf("Thi is : %d\n", pid);
    signal(SIGUSR2,soma);
    sleep(5000);
}

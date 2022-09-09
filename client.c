#include<signal.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char* argv[])
{
    int v = atoi(argv[1]);
    kill(v,SIGUSR2);
}

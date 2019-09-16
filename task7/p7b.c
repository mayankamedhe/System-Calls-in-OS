#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]);
    int fork_int;
    pid_t cpid;

    srand(time(0));
    
    printf("Parent is : %d\n", getpid());
    printf("Number of children: %d\n",n);
    
    for(int i=0;i<n;i++)
    {
        int delay;
        delay = rand()%1000000;
        //printf("%d\n", delay);
        
        fork_int = fork();
        if(fork_int == 0)
        {
            printf("Child %d is created\n",getpid());
            usleep(delay);
            exit(0);
        }
    }

    if(fork_int != 0)
    {
        for (int i = 0; i < n; ++i)
        {
            cpid = wait(NULL);
            printf("Child %d exited\n", cpid);   
        }
    
    printf("Parent exited\n");
    }
    
}
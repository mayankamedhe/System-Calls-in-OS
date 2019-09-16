#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]);
    printf("Parent is : %d\n", getpid());
    printf("Number of children: %d\n",n);
    rec_child(n);
    return 0;


}

void rec_child(int n)
{
    pid_t cpid;
    int i;
    i=fork();

    if(n <= 0)
    {
        return;
    }
    else
    {
        if(i==0)
        {

            printf("Child %d is created\n", getpid());
            rec_child(n-1);
        }
        else
        {
            cpid = wait(NULL);
            printf("Child %d exited\n", i);
        }
    }
}

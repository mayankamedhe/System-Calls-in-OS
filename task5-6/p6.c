#include <stdio.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
        pid_t cpid;
        int i;
        char ch;
        i=fork();

        if(i==0)
        {

                printf("Child : My process ID is: %d\n", getpid());
        		printf("Child : The parent process ID is: %d\n", getppid());
                scanf("%c", &ch);
        }
        else
        {

			printf("Parent : My process ID is: %d\n", getpid());
    		printf("Parent : The child process ID is: %d\n", i);
            sleep(60);
            cpid = wait(NULL);
            printf("Parent : The parent has terminated.\n");
        }

        return 0;


}

#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>

#include <stdio.h>

int main()
{
		pid_t cpid;
        int i;
        i=fork();

        if(i==0)
        {

                printf("Child : My process ID is : %d\n", getpid());
        		printf("Child : The parent process ID is : %d\n", getppid());
        }
        else
        {
        	//sleep(15);
        	cpid = wait(NULL);
			printf("Parent : My process ID is : %d\n", getpid());
    		printf("Parent : The child process ID is : %d\n", i);
    		printf("Parent : The child with process ID %d has terminated.\n", i);
        }

        return 0;


}